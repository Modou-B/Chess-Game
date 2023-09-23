//
// Created by Julian Sommer on 16.09.23.
//

#include "ChessPieceMovementManager.h"
#include "../../GameApplication/GameApplication.h"
#include "../../GameApplication/Player/ChessPlayerData.h"
#include "../../Model/ChessCell.h"
#include "../../ChessPiece/BaseChessPiece.h"
#include "../../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../../Shared/Chess/ChessConstants.h"
#include "../../../Shared/Chess/ChessMovementConstants.h"
#include "../Generator/ChessPieceMovementGenerator.h"
#include "../PawnPiece.h"
#include "../../Model/ChessField.h"
#include "iostream"
// initialize static variables
std::vector<ChessPiecePossibleMoveTransfer*> ChessPieceMovementManager::possibleMovesForClickedCell;
std::vector<ChessPiecePossibleMoveTransfer*> ChessPieceMovementManager::previousPossibleMovesForClickedCell;

ChessPieceMovementManager::ChessPieceMovementManager(ChessPieceMovementGenerator *chessPieceMovementGenerator) {
    this->chessPieceMovementGenerator = chessPieceMovementGenerator;
}

ChessMovementResponseTransfer ChessPieceMovementManager::handleChessMovement(std::pair<int, int> currentCellCoordinates, bool isPlayerInCheck, ChessPlayerData *opponentPlayerData) {
    ChessCell *currentChessCell = GameApplication::getChessCell(currentCellCoordinates);

    ChessMovementResponseTransfer chessMovementResponseTransfer = ChessMovementResponseTransfer();
    if (!GameApplication::wasPreviousCellClicked()) {
        return this->handleMovementWithoutPreviousClickedCell(currentChessCell, chessMovementResponseTransfer, isPlayerInCheck);
    }

    return this->handleMovementWithPreviousClickedCell(currentChessCell, chessMovementResponseTransfer, isPlayerInCheck, opponentPlayerData);
}


ChessMovementResponseTransfer ChessPieceMovementManager::handleMovementWithPreviousClickedCell(
    ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, bool isPlayerInCheck, ChessPlayerData *opponentPlayerData) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();

    if (currentChessPiece && this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        if (isPlayerInCheck && !currentChessPiece->canPieceBlockCheck() && currentChessPiece->getType() != ChessConstants::KING_PIECE_TYPE) {
            return chessMovementResponseTransfer;
        }

        chessMovementResponseTransfer = this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates(), chessMovementResponseTransfer, isPlayerInCheck);
        chessMovementResponseTransfer.setState(ChessConstants::STATE_SWITCHED_PIECE);

        return this->saveClickedCellCoordinates(currentChessCell->getCoordinates(), chessMovementResponseTransfer);
    }

    for (auto & chessPiecePossibleMoveTransfer : ChessPieceMovementManager::possibleMovesForClickedCell)
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
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPiecePossibleMoveTransfer *usedMove, ChessPlayerData *opponentPlayerData) {

    ChessPieceMovementManager::previousPossibleMovesForClickedCell = ChessPieceMovementManager::possibleMovesForClickedCell;
    chessMovementResponseTransfer.setPreviousPossibleMoves(&ChessPieceMovementManager::previousPossibleMovesForClickedCell);
    chessMovementResponseTransfer.setCurrentCellCoordinates(currentChessCell->getCoordinates());

    previousChessCell->getChessPiece()->handleMovement(usedMove);

    chessMovementResponseTransfer.togglePieceMovementValue();
    chessMovementResponseTransfer.setState(ChessConstants::STATE_MOVED_PIECE);
    if (previousChessCell->getChessPiece()->getType() == ChessConstants::KING_PIECE_TYPE) {
        chessMovementResponseTransfer.setHasKingMoved(true);
    }

    chessMovementResponseTransfer.addChessPieceMovementTransfer(
        this->chessPieceMovementGenerator->generateChessPieceMovementTransfer(
            ChessMovementConstants::ACTION_MOVE, previousChessCell->getCoordinates(), currentChessCell->getCoordinates()));

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

    currentChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::addEnPassantChessPieceMovement(
    ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPlayerData *opponentPlayerData) {

    auto *pawnPiece = static_cast<PawnPiece*>(previousChessCell->getChessPiece());
    auto currentCoordinates = currentChessCell->getCoordinates();

    auto coordinatesOfOpponentPawnPiece = std::pair<int,int>();
    if (pawnPiece->getPlayer() == 1) {
        coordinatesOfOpponentPawnPiece = std::make_pair((currentCoordinates.first+1), currentCoordinates.second);

        chessMovementResponseTransfer.addChessPieceMovementTransfer(
            this->chessPieceMovementGenerator->generateChessPieceMovementTransfer(
                ChessMovementConstants::ACTION_DELETE, coordinatesOfOpponentPawnPiece));

    } else {
      coordinatesOfOpponentPawnPiece = std::make_pair((currentCoordinates.first-1), currentCoordinates.second);

      chessMovementResponseTransfer.addChessPieceMovementTransfer(
          this->chessPieceMovementGenerator->generateChessPieceMovementTransfer(
              ChessMovementConstants::ACTION_DELETE, coordinatesOfOpponentPawnPiece));
    }

    auto *chessCellWithOpponentPawnPiece = GameApplication::getChessCell(coordinatesOfOpponentPawnPiece);

    opponentPlayerData->removePiece(chessCellWithOpponentPawnPiece->getChessPiece());
    chessCellWithOpponentPawnPiece->setChessPiece(nullptr);

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::addCastlingChessPieceMovement(
    ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {

    auto currentCoordinates = currentChessCell->getCoordinates();

    std::pair<int,int> oldCoordinatesOfRookPiece;
    std::pair<int,int> newCoordinatesOfRookPiece;

    if (currentCoordinates.second == 6) {
        oldCoordinatesOfRookPiece = std::make_pair(currentCoordinates.first, 7);
        newCoordinatesOfRookPiece = std::make_pair(currentCoordinates.first, (currentCoordinates.second-1));

        chessMovementResponseTransfer.addChessPieceMovementTransfer(
            this->chessPieceMovementGenerator->generateChessPieceMovementTransfer(
                ChessMovementConstants::ACTION_MOVE, oldCoordinatesOfRookPiece, newCoordinatesOfRookPiece));
    } else {
        oldCoordinatesOfRookPiece = std::make_pair(currentCoordinates.first, 0);
        newCoordinatesOfRookPiece = std::make_pair(currentCoordinates.first, (currentCoordinates.second+1));

        chessMovementResponseTransfer.addChessPieceMovementTransfer(
            this->chessPieceMovementGenerator->generateChessPieceMovementTransfer(
                ChessMovementConstants::ACTION_MOVE, oldCoordinatesOfRookPiece, newCoordinatesOfRookPiece));
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

        chessMovementResponseTransfer = this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates(), chessMovementResponseTransfer, isPlayerInCheck);

        return this->saveClickedCellCoordinates(currentChessCell->getCoordinates(), chessMovementResponseTransfer);
    }

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::saveClickedCellCoordinates(std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    GameApplication::setPreviouslyClickedCellCoordinates(currentCellCoordinates);

    return chessMovementResponseTransfer;
}

bool ChessPieceMovementManager::doesChessPieceBelongToCurrentPlayer(BaseChessPiece *currentChessPiece) {
    int currentPlayer = GameApplication::getCurrentPlayer();

    if (currentChessPiece->getPlayer() == currentPlayer) {
        return true;
    }

    return false;
}

std::vector<ChessPiecePossibleMoveTransfer *> ChessPieceMovementManager::getPossibleMovesForCheckStatus(BaseChessPiece *clickedChessPiece, bool isPlayerInCheck) {
    if (isPlayerInCheck && clickedChessPiece->getType() != ChessConstants::KING_PIECE_TYPE) {
      return clickedChessPiece->getCoordinatesThatBlockCheck();
    }

    return clickedChessPiece->determinePossibleMoves(GameApplication::getChessField(), clickedChessPiece->getCurrentCoordinates());
}

ChessMovementResponseTransfer ChessPieceMovementManager::savePossibleMovesForClickedPiece(
        BaseChessPiece *clickedChessPiece, std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer, bool isPlayerInCheck) {
    if (!ChessPieceMovementManager::possibleMovesForClickedCell.empty()) {
        ChessPieceMovementManager::previousPossibleMovesForClickedCell = ChessPieceMovementManager::possibleMovesForClickedCell;
    }

    auto possibleMoves = this->getPossibleMovesForCheckStatus(clickedChessPiece, isPlayerInCheck);
    if (!possibleMoves.empty()) {
        chessMovementResponseTransfer.setPossibleMoves(possibleMoves);
        chessMovementResponseTransfer.setPossibleMovesCheckValue(true);
    }

    ChessPieceMovementManager::possibleMovesForClickedCell = possibleMoves;

    if (!ChessPieceMovementManager::previousPossibleMovesForClickedCell.empty()) {
        chessMovementResponseTransfer.setPreviousPossibleMoves(&ChessPieceMovementManager::previousPossibleMovesForClickedCell);
    }

    return chessMovementResponseTransfer;
}

void ChessPieceMovementManager::clearPossibleMoveCollections() {
    ChessPieceMovementManager::possibleMovesForClickedCell.clear();
    ChessPieceMovementManager::previousPossibleMovesForClickedCell.clear();
}
