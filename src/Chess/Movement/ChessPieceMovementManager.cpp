//
// Created by Julian Sommer on 16.09.23.
//

#include "ChessPieceMovementManager.h"
#include "Writer/ChessPieceMovementWriter.h"
#include "Reader/ChessPieceMovementReader.h"
#include "../ChessPiece/Creator/ChessPieceCreator.h"
#include "../../ChessGui/Renderer/ChessGuiRenderer.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Shared/Chess/Transfer/Movement/PossibleMoveCollectionTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "ChessPiece/BaseChessPiece.h"
#include "Mapper/ChessPieceMovementMapper.h"
#include "ChessPiece/PawnPiece.h"
#include "GameApplication/GameApplication.h"
#include "GameApplication/Player/ChessPlayerData.h"
#include "Model/ChessCell.h"
#include "Model/ChessField.h"
#include "iostream"
#include "../../Shared/ChessTimeline/ChessTurnLogTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceInformationTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceStateTransfer.h"
#include "../GameApplication/Writer/GameApplicationDataWriter.h"

ChessPieceMovementManager::ChessPieceMovementManager(
    ChessPieceMovementMapper *chessPieceMovementMapper,
    ChessPieceMovementWriter *chessPieceMovementWriter,
    ChessPieceMovementReader *chessPieceMovementReader,
    ChessPieceCreator * chessPieceCreator,
    GameApplicationDataWriter *gameApplicationDataWriter
) {
    this->chessPieceMovementMapper = chessPieceMovementMapper;
    this->chessPieceMovementWriter = chessPieceMovementWriter;
    this->chessPieceMovementReader = chessPieceMovementReader;
    this->chessPieceCreator = chessPieceCreator;
    this->gameApplicationDataWriter = gameApplicationDataWriter;
}

ChessMovementResponseTransfer ChessPieceMovementManager::handleChessMovement(
    pair<int, int> currentCellCoordinates,
    ChessMovementResponseTransfer chessMovementResponseTransfer,
    bool isPlayerInCheck,
    ChessPlayerData *opponentPlayerData
) {
    ChessCell *currentChessCell = GameApplication::getChessCell(currentCellCoordinates);

    chessMovementResponseTransfer.setState(ChessMovementConstants::MOVEMENT_STATE_NOT_MOVED);

    if (!GameApplication::wasPreviousCellClicked()) {
        return this->handleMovementWithoutPreviousClickedCell(currentChessCell, chessMovementResponseTransfer, isPlayerInCheck);
    }

    return this->handleMovementWithPreviousClickedCell(currentChessCell, chessMovementResponseTransfer, isPlayerInCheck, opponentPlayerData);
}


ChessMovementResponseTransfer ChessPieceMovementManager::handleMovementWithPreviousClickedCell(
    ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, bool isPlayerInCheck, ChessPlayerData *opponentPlayerData) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();

    if (currentChessPiece && this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        this->savePossibleMovesForClickedPiece(currentChessPiece, isPlayerInCheck);
        this->saveClickedCellCoordinates(currentChessCell->getCoordinates());
        chessMovementResponseTransfer.setState(ChessMovementConstants::MOVEMENT_STATE_SWITCHED_TO_OWN_PIECE);

        return this->finalizeChessMovementResponse(chessMovementResponseTransfer);
    }

    auto possibleMoveCollectionTransfer = this->chessPieceMovementReader->getPossibleMoves();
    for (auto & chessPiecePossibleMoveTransfer : possibleMoveCollectionTransfer.getPossibleMoveTransfers())
    {
        if (currentChessCell->getCoordinates().first == chessPiecePossibleMoveTransfer->getYCoordinate()
            && currentChessCell->getCoordinates().second == chessPiecePossibleMoveTransfer->getXCoordinate()) {

            ChessCell* previousChessCell = GameApplication::getChessCell(GameApplication::getPreviouslyClickedCellCoordinates());

            return this->moveChessPiece(previousChessCell, currentChessCell, chessMovementResponseTransfer, chessPiecePossibleMoveTransfer, opponentPlayerData);
        }
    }

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::moveChessPiece(
    ChessCell *previousChessCell,
    ChessCell *currentChessCell,
    ChessMovementResponseTransfer chessMovementResponseTransfer,
    ChessPiecePossibleMoveTransfer *usedMove,
    ChessPlayerData *opponentPlayerData
) {
    this->chessPieceMovementWriter->updatePreviousPossibleMoveDataWithCurrentPossibleMoves();

    previousChessCell->getChessPiece()->handleMovement(usedMove);

    chessMovementResponseTransfer.setState(ChessMovementConstants::MOVEMENT_STATE_MOVED);

    bool previousUsedDoubleMove = false;
    if (previousChessCell->getChessPiece()->getType() == ChessConstants::PAWN_PIECE_TYPE) {
        auto *previousPawnPiece = static_cast<PawnPiece *>(previousChessCell->getChessPiece());
        previousUsedDoubleMove = previousPawnPiece->getUsedDoubleMove();
    }

    chessMovementResponseTransfer.addChessPieceStateTransfer(
        this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
            chessMovementResponseTransfer.getCurrentPlayer(),
            previousChessCell->getChessPiece()->getType(),
            ChessMovementConstants::CHESS_PIECE_STATE_MOVED,
            previousChessCell->getChessPiece()->getMoveCounter(),
            previousUsedDoubleMove,
            previousChessCell->getCoordinates(),
            currentChessCell->getCoordinates()
        )
    );

    if (usedMove->getMoveType() == ChessMovementConstants::MOVE_TYPE_EN_PASSANT) {
        chessMovementResponseTransfer = this->addEnPassantChessPieceMovement(previousChessCell, currentChessCell, chessMovementResponseTransfer, opponentPlayerData);
    }

    if (usedMove->getMoveType() == ChessMovementConstants::MOVE_TYPE_CASTLING) {
        chessMovementResponseTransfer = this->addCastlingChessPieceMovement(currentChessCell, chessMovementResponseTransfer);
    }

    previousChessCell->getChessPiece()->setCurrentCoordinates(currentChessCell->getCoordinates());

    if (currentChessCell->getChessPiece()) {
        opponentPlayerData->removePiece(currentChessCell->getChessPiece());
    }

    if (previousChessCell->getChessPiece()->getType() == ChessConstants::PAWN_PIECE_TYPE
        && (currentChessCell->getCoordinates().first == 7
            || currentChessCell->getCoordinates().first == 0)
    ) {
        chessMovementResponseTransfer.setState(ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH_SELECTION_START);
    }

    if (currentChessCell->getChessPiece() != nullptr) {
      bool currentUsedDoubleMove = false;
      if (currentChessCell->getChessPiece()->getType() == ChessConstants::PAWN_PIECE_TYPE) {
          auto *pawnPiece = static_cast<PawnPiece *>(currentChessCell->getChessPiece());
          currentUsedDoubleMove = pawnPiece->getUsedDoubleMove();
      }

      chessMovementResponseTransfer.addChessPieceStateTransfer(
        this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
            chessMovementResponseTransfer.getCurrentOpponentPlayer(),
            currentChessCell->getChessPiece()->getType(),
            ChessMovementConstants::CHESS_PIECE_STATE_DELETED,
            currentChessCell->getChessPiece()->getMoveCounter(),
            currentUsedDoubleMove,
            currentChessCell->getCoordinates()
        )
      );
    }

    this->saveClickedCellCoordinates(currentChessCell->getCoordinates());

    currentChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    return this->finalizeChessMovementResponse(chessMovementResponseTransfer);
}

ChessMovementResponseTransfer ChessPieceMovementManager::addEnPassantChessPieceMovement(
    ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPlayerData *opponentPlayerData) {

    auto *pawnPiece = static_cast<PawnPiece*>(previousChessCell->getChessPiece());
    auto currentCoordinates = currentChessCell->getCoordinates();

    auto coordinatesOfOpponentPawnPiece = pair<int,int>();
    if (pawnPiece->getPlayer() == 1) {
      coordinatesOfOpponentPawnPiece = make_pair((currentCoordinates.first+1), currentCoordinates.second);
    } else {
      coordinatesOfOpponentPawnPiece = make_pair((currentCoordinates.first-1), currentCoordinates.second);
    }

    auto *chessCellWithOpponentPawnPiece = GameApplication::getChessCell(coordinatesOfOpponentPawnPiece);

    chessMovementResponseTransfer.addChessPieceStateTransfer(
          this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
              chessMovementResponseTransfer.getCurrentOpponentPlayer(),
              ChessConstants::PAWN_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_DELETED_EN_PASSANT,
              chessCellWithOpponentPawnPiece->getChessPiece()->getMoveCounter(),
              true,
              coordinatesOfOpponentPawnPiece
          )
      );

    opponentPlayerData->removePiece(chessCellWithOpponentPawnPiece->getChessPiece());
    chessCellWithOpponentPawnPiece->setChessPiece(nullptr);

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::addCastlingChessPieceMovement(
    ChessCell *currentChessCell,
    ChessMovementResponseTransfer chessMovementResponseTransfer
) {
    auto currentCoordinates = currentChessCell->getCoordinates();

    pair<int,int> oldCoordinatesOfRookPiece;
    pair<int,int> newCoordinatesOfRookPiece;

    if (currentCoordinates.second == 6) {
      oldCoordinatesOfRookPiece = make_pair(currentCoordinates.first, 7);
      newCoordinatesOfRookPiece = make_pair(currentCoordinates.first, (currentCoordinates.second-1));

      chessMovementResponseTransfer.addChessPieceStateTransfer(
          this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
              chessMovementResponseTransfer.getCurrentPlayer(),
              ChessConstants::ROOK_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_MOVED,
              0,
              false,
              oldCoordinatesOfRookPiece,
              newCoordinatesOfRookPiece
          )
      );
    } else {
      oldCoordinatesOfRookPiece = make_pair(currentCoordinates.first, 0);
      newCoordinatesOfRookPiece = make_pair(currentCoordinates.first, (currentCoordinates.second+1));

      chessMovementResponseTransfer.addChessPieceStateTransfer(
          this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
              chessMovementResponseTransfer.getCurrentPlayer(),
              ChessConstants::ROOK_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_MOVED,
              0,
              false,
              oldCoordinatesOfRookPiece,
              newCoordinatesOfRookPiece
          )
      );
    }

    auto *oldChessCellWithRookPiece = GameApplication::getChessCell(oldCoordinatesOfRookPiece);
    auto *newChessCellWithRookPiece = GameApplication::getChessCell(newCoordinatesOfRookPiece);

    oldChessCellWithRookPiece->getChessPiece()->setCurrentCoordinates(newCoordinatesOfRookPiece);
    newChessCellWithRookPiece->setChessPiece(oldChessCellWithRookPiece->getChessPiece());
    oldChessCellWithRookPiece->setChessPiece(nullptr);

    return chessMovementResponseTransfer;
}


ChessMovementResponseTransfer ChessPieceMovementManager::handleMovementWithoutPreviousClickedCell(
    ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, bool isPlayerInCheck) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();

    if (!currentChessPiece) {
        return chessMovementResponseTransfer;
    }

    if (this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        if (isPlayerInCheck && !currentChessPiece->canPieceBlockCheck() && currentChessPiece->getType() != ChessConstants::KING_PIECE_TYPE) {
            return chessMovementResponseTransfer;
        }

        this->savePossibleMovesForClickedPiece(currentChessPiece, isPlayerInCheck);
        this->saveClickedCellCoordinates(currentChessCell->getCoordinates());

        return this->finalizeChessMovementResponse(chessMovementResponseTransfer);
    }

    return chessMovementResponseTransfer;
}

void ChessPieceMovementManager::saveClickedCellCoordinates(pair<int, int> currentCellCoordinates) {
    GameApplication::setPreviouslyClickedCellCoordinates(currentCellCoordinates);
}

bool ChessPieceMovementManager::doesChessPieceBelongToCurrentPlayer(BaseChessPiece *currentChessPiece) {
    int currentPlayer = GameApplication::getCurrentPlayer();

    if (currentChessPiece->getPlayer() == currentPlayer) {
        return true;
    }

    return false;
}

vector<ChessPiecePossibleMoveTransfer *> ChessPieceMovementManager::getPossibleMovesForCheckStatus(BaseChessPiece *clickedChessPiece, bool isPlayerInCheck) {
    if (isPlayerInCheck && clickedChessPiece->getType() != ChessConstants::KING_PIECE_TYPE) {
        return clickedChessPiece->getCoordinatesThatBlockCheck();
    }

    return clickedChessPiece->determinePossibleMoves(GameApplication::getChessField(), clickedChessPiece->getCurrentCoordinates());
}

void ChessPieceMovementManager::savePossibleMovesForClickedPiece(
    BaseChessPiece *clickedChessPiece,
    bool isPlayerInCheck
) {
    auto possibleMoves = this->getPossibleMovesForCheckStatus(clickedChessPiece, isPlayerInCheck);

    this->chessPieceMovementWriter->updatePossibleMoveData(possibleMoves);
}

void ChessPieceMovementManager::clearPossibleMoveCollections() {
    this->chessPieceMovementWriter->clearPossibleMoveCollections();
}

ChessMovementResponseTransfer ChessPieceMovementManager::finalizeChessMovementResponse(
    ChessMovementResponseTransfer chessMovementResponseTransfer
) {
    this->expandResponseWithPossibleMoves(chessMovementResponseTransfer);

    return chessMovementResponseTransfer;
}

void ChessPieceMovementManager::expandResponseWithPossibleMoves(
    ChessMovementResponseTransfer &chessMovementResponseTransfer
) {
    auto possibleMoveCollectionTransfer = this->chessPieceMovementReader->getPossibleMovesForAllTypes();

    chessMovementResponseTransfer.setPreviousPossibleMoveTransfers(
        possibleMoveCollectionTransfer.getPreviousPossibleMoveTransfers()
    )
        ->setPossibleMoveTransfers(possibleMoveCollectionTransfer.getPossibleMoveTransfers());
}

void ChessPieceMovementManager::updateChessGrid(
    ChessTurnLogTransfer *chessTurnLogTransfer
) {

    cout << "ChessPieceMovementManager::updateChessGrid" <<endl;

    vector<ChessPieceInformationTransfer *> chessPieceDeleteInformationStateTransfers;
    for (auto &chessPieceInformationTransfer: chessTurnLogTransfer->getChessPieceInformationTransfers()) {

        if (chessPieceInformationTransfer->getChessPieceStateTransfer()->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
              cout << "ChessPieceMovementManager::moved" <<endl;

            this->handleChessPieceStates(chessPieceInformationTransfer);

            continue;
        }

        chessPieceDeleteInformationStateTransfers.push_back(chessPieceInformationTransfer);
    }

    for (auto &chessPieceInformationTransfer: chessPieceDeleteInformationStateTransfers) {
        cout << "ChessPieceMovementManager::deleted" <<endl;

        this->handleChessPieceStates(chessPieceInformationTransfer);
    }
}

void ChessPieceMovementManager::updateMultiplayerChessGrid(
    ChessTurnLogTransfer *chessTurnLogTransfer
) {
    vector<ChessPieceInformationTransfer *> chessPieceDeleteInformationStateTransfers;
    for (auto &chessPieceInformationTransfer: chessTurnLogTransfer->getChessPieceInformationTransfers()) {
        if (chessPieceInformationTransfer->getChessPieceStateTransfer()->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
            auto *chessPieceStateTransfer = chessPieceInformationTransfer->getChessPieceStateTransfer();
            auto *startChessCell = GameApplication::getChessCell(chessPieceStateTransfer->getStartCoordinate());

            auto *chessPiece = this->chessPieceCreator->createChessPiece(chessPieceStateTransfer);
            startChessCell->setChessPiece(nullptr);

            auto *movedChessGuiCell = GameApplication::getChessCell(chessPieceStateTransfer->getEndCoordinate());
            movedChessGuiCell->setChessPiece(chessPiece);

            continue;
        }

        chessPieceDeleteInformationStateTransfers.push_back(chessPieceInformationTransfer);
    }

    for (auto &chessPieceInformationTransfer: chessPieceDeleteInformationStateTransfers) {
        if (chessPieceInformationTransfer->getChessPieceStateTransfer()->getState() == ChessMovementConstants::CHESS_PIECE_STATE_DELETED_EN_PASSANT) {
            auto *chessPieceStateTransfer = chessPieceInformationTransfer->getChessPieceStateTransfer();
            auto *startChessCell = GameApplication::getChessCell(chessPieceStateTransfer->getStartCoordinate());

            auto *chessPiece = this->chessPieceCreator->createChessPiece(chessPieceStateTransfer);
        }
    }
}

void ChessPieceMovementManager::handleChessPieceStates(
    ChessPieceInformationTransfer *chessPieceInformationTransfer
) {
    auto *chessPieceStateTransfer = chessPieceInformationTransfer->getChessPieceStateTransfer();
    auto *startChessCell = GameApplication::getChessCell(chessPieceStateTransfer->getStartCoordinate());

    auto *chessPiece = this->chessPieceCreator->createChessPiece(chessPieceStateTransfer);

    startChessCell->setChessPiece(chessPiece);

    if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
        auto *movedChessGuiCell = GameApplication::getChessCell(chessPieceStateTransfer->getEndCoordinate());
        movedChessGuiCell->setChessPiece(nullptr);

        if (chessPieceStateTransfer->getChessPieceType() == ChessConstants::KING_PIECE_TYPE) {
            this->gameApplicationDataWriter
                ->saveChessPieceForChessPlayerData(
                  chessPiece,
                  chessPieceStateTransfer->getChessPieceType(),
                  chessPieceStateTransfer->getPlayerOfChessPiece()
            );
        }

        return;
    }

    if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_DELETED
        || chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_DELETED_EN_PASSANT) {

        this->gameApplicationDataWriter
            ->saveChessPieceForChessPlayerData(
              chessPiece,
              chessPieceStateTransfer->getChessPieceType(),
              chessPieceStateTransfer->getPlayerOfChessPiece()
        );
    }
}

