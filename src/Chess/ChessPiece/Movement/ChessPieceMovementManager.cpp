//
// Created by Julian Sommer on 16.09.23.
//

#include "ChessPieceMovementManager.h"
#include "../../GameApplication/GameApplication.h"
#include "../../Model/ChessCell.h"
#include "../../ChessPiece/BaseChessPiece.h"
#include "../../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../../Shared/Chess/ChessConstants.h"
#include "../../../Shared/Chess/ChessMovementConstants.h"
#include "../Generator/ChessPieceMovementGenerator.h"
#include "../PawnPiece.h"
#include "../../../ChessGui/Renderer/ChessGuiRenderer.h"

// initialize static variables
std::vector<ChessPiecePossibleMoveTransfer*> ChessPieceMovementManager::possibleMovesForClickedCell;
std::vector<ChessPiecePossibleMoveTransfer*> ChessPieceMovementManager::previousPossibleMovesForClickedCell;

ChessPieceMovementManager::ChessPieceMovementManager(ChessPieceMovementGenerator *chessPieceMovementGenerator) {
    this->chessPieceMovementGenerator = chessPieceMovementGenerator;
}

ChessMovementResponseTransfer ChessPieceMovementManager::handleChessMovement(std::pair<int, int> currentCellCoordinates) {
    ChessCell *currentChessCell = GameApplication::getChessCell(currentCellCoordinates);
    ChessMovementResponseTransfer chessMovementResponseTransfer = ChessMovementResponseTransfer();

    if (!GameApplication::wasPreviousCellClicked()) {
        return this->handleMovementWithoutPreviousClickedCell(currentChessCell, chessMovementResponseTransfer);
    }

    return this->handleMovementWithPreviousClickedCell(currentChessCell, chessMovementResponseTransfer);
}


ChessMovementResponseTransfer ChessPieceMovementManager::handleMovementWithPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();
    if (currentChessPiece && this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        chessMovementResponseTransfer = this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates(), chessMovementResponseTransfer);
        chessMovementResponseTransfer.setState(ChessConstants::STATE_SWITCHED_PIECE);

        return this->saveClickedCellCoordinates(currentChessCell->getCoordinates(), chessMovementResponseTransfer);
    }

    for (auto & chessPiecePossibleMoveTransfer : ChessPieceMovementManager::possibleMovesForClickedCell)
    {
        if (currentChessCell->getCoordinates().first == chessPiecePossibleMoveTransfer->getYCoordinate()
            && currentChessCell->getCoordinates().second == chessPiecePossibleMoveTransfer->getXCoordinate()) {

            ChessCell* previousChessCell = GameApplication::getChessCell(GameApplication::getPreviouslyClickedCellCoordinates());

            return this->moveChessPiece(previousChessCell, currentChessCell, chessMovementResponseTransfer, chessPiecePossibleMoveTransfer);
        }
    }

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::moveChessPiece(
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPiecePossibleMoveTransfer *usedMove) {

    ChessPieceMovementManager::previousPossibleMovesForClickedCell = ChessPieceMovementManager::possibleMovesForClickedCell;
    chessMovementResponseTransfer.setPreviousPossibleMoves(&ChessPieceMovementManager::previousPossibleMovesForClickedCell);
    chessMovementResponseTransfer.setCurrentCellCoordinates(currentChessCell->getCoordinates());

    previousChessCell->getChessPiece()->handleMovement(usedMove);

    chessMovementResponseTransfer.togglePieceMovementValue();
    chessMovementResponseTransfer.setState(ChessConstants::STATE_MOVED_PIECE);

    chessMovementResponseTransfer.addChessPieceMovementTransfer(
        this->chessPieceMovementGenerator->generateChessPieceMovementTransfer(
            ChessMovementConstants::ACTION_MOVE, previousChessCell->getCoordinates(), currentChessCell->getCoordinates()));

    if (usedMove->getMoveType() == ChessMovementConstants::MOVE_TYPE_EN_PASSANT) {
        chessMovementResponseTransfer = this->addEnPassantChessPieceMovement(previousChessCell, currentChessCell, chessMovementResponseTransfer);
    }

    currentChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer ChessPieceMovementManager::addEnPassantChessPieceMovement(
    ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {

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
    chessCellWithOpponentPawnPiece->setChessPiece(nullptr);

    return chessMovementResponseTransfer;
}


ChessMovementResponseTransfer ChessPieceMovementManager::handleMovementWithoutPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();

    if (!currentChessPiece) {
        return chessMovementResponseTransfer;
    }

    if (this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        chessMovementResponseTransfer = this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates(), chessMovementResponseTransfer);

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

ChessMovementResponseTransfer ChessPieceMovementManager::savePossibleMovesForClickedPiece(
        BaseChessPiece *clickedChessPiece, std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    if (!ChessPieceMovementManager::possibleMovesForClickedCell.empty()) {
        ChessPieceMovementManager::previousPossibleMovesForClickedCell = ChessPieceMovementManager::possibleMovesForClickedCell;
    }

    ChessPieceMovementManager::possibleMovesForClickedCell = clickedChessPiece->determinePossibleMoves(GameApplication::getChessField(), currentCellCoordinates);
    if (!ChessPieceMovementManager::possibleMovesForClickedCell.empty()) {
        chessMovementResponseTransfer.setPossibleMoves(&ChessPieceMovementManager::possibleMovesForClickedCell);
        chessMovementResponseTransfer.togglePossibleMovesCheckValue();
    }

    if (!ChessPieceMovementManager::previousPossibleMovesForClickedCell.empty()) {
        chessMovementResponseTransfer.setPreviousPossibleMoves(&ChessPieceMovementManager::previousPossibleMovesForClickedCell);
    }

    return chessMovementResponseTransfer;
}

void ChessPieceMovementManager::clearPossibleMoveCollections() {
    ChessPieceMovementManager::possibleMovesForClickedCell.clear();
    ChessPieceMovementManager::previousPossibleMovesForClickedCell.clear();
}
