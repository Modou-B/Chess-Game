//
// Created by Julian Sommer on 16.09.23.
//

#include "ChessPieceMovementManager.h"
#include "Writer/ChessPieceMovementWriter.h"
#include "Reader/ChessPieceMovementReader.h"
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

ChessPieceMovementManager::ChessPieceMovementManager(
    ChessPieceMovementMapper *chessPieceMovementMapper,
    ChessPieceMovementWriter *chessPieceMovementWriter,
    ChessPieceMovementReader *chessPieceMovementReader
) {
    this->chessPieceMovementMapper = chessPieceMovementMapper;
    this->chessPieceMovementWriter = chessPieceMovementWriter;
    this->chessPieceMovementReader = chessPieceMovementReader;
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

    chessMovementResponseTransfer.addChessPieceStateTransfer(
        this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
            chessMovementResponseTransfer.getCurrentPlayer(),
            previousChessCell->getChessPiece()->getType(),
            ChessMovementConstants::CHESS_PIECE_STATE_MOVED,
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
      chessMovementResponseTransfer.addChessPieceStateTransfer(
        this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
            chessMovementResponseTransfer.getCurrentOpponentPlayer(),
            currentChessCell->getChessPiece()->getType(),
            ChessMovementConstants::CHESS_PIECE_STATE_DELETED,
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

      chessMovementResponseTransfer.addChessPieceStateTransfer(
          this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
              chessMovementResponseTransfer.getCurrentOpponentPlayer(),
              ChessConstants::PAWN_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_DELETED_EN_PASSANT,
              coordinatesOfOpponentPawnPiece
          )
      );
    } else {
      coordinatesOfOpponentPawnPiece = make_pair((currentCoordinates.first-1), currentCoordinates.second);

      chessMovementResponseTransfer.addChessPieceStateTransfer(
          this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
              chessMovementResponseTransfer.getCurrentOpponentPlayer(),
              ChessConstants::PAWN_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_DELETED_EN_PASSANT,
              coordinatesOfOpponentPawnPiece
          )
      );
    }

    auto *chessCellWithOpponentPawnPiece = GameApplication::getChessCell(coordinatesOfOpponentPawnPiece);

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
              chessMovementResponseTransfer.getCurrentOpponentPlayer(),
              ChessConstants::ROOK_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_MOVED,
              oldCoordinatesOfRookPiece,
              newCoordinatesOfRookPiece
          )
      );
    } else {
      oldCoordinatesOfRookPiece = make_pair(currentCoordinates.first, 0);
      newCoordinatesOfRookPiece = make_pair(currentCoordinates.first, (currentCoordinates.second+1));

      chessMovementResponseTransfer.addChessPieceStateTransfer(
          this->chessPieceMovementMapper->mapDataToChessPieceStateTransfer(
              chessMovementResponseTransfer.getCurrentOpponentPlayer(),
              ChessConstants::ROOK_PIECE_TYPE,
              ChessMovementConstants::CHESS_PIECE_STATE_MOVED,
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