//
// Created by Julian Sommer on 07.09.23.
//

#include "GameApplicationManager.h"
#include "../Creator/ChessCreator.h"
#include "../Model/ChessCell.h"
#include "../ChessPiece/BaseChessPiece.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "GameApplication.h"
#include "iostream"

std::vector<std::pair<int, int>> GameApplicationManager::possibleMovesForClickedCell;
std::vector<std::pair<int, int>> GameApplicationManager::previousPossibleMovesForClickedCell;

GameApplicationManager::GameApplicationManager(ChessCreator *chessCreator) {
    this->chessCreator = chessCreator;
}

void GameApplicationManager::initiateChessApplication() {
    ChessField *chessField = this->chessCreator->initiateChessField();

    GameApplication::setChessField(chessField);
}

ChessMovementResponseTransfer GameApplicationManager::handleChessMovement(std::pair<int, int> currentCellCoordinates) {
    ChessCell *currentChessCell = GameApplication::getChessCell(currentCellCoordinates);
    ChessMovementResponseTransfer chessMovementResponseTransfer = ChessMovementResponseTransfer();

    if (!GameApplication::wasPreviousCellClicked()) {
        return this->handleMovementWithoutPreviousClickedCell(currentChessCell, chessMovementResponseTransfer);
    }

    return this->handleMovementWithPreviousClickedCell(currentChessCell, chessMovementResponseTransfer);
}


ChessMovementResponseTransfer GameApplicationManager::handleMovementWithPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();
    if (currentChessPiece && this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        chessMovementResponseTransfer = this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates(), chessMovementResponseTransfer);
        chessMovementResponseTransfer.setState(ChessConstants::STATE_SWITCHED_PIECE);

        return this->saveClickedCellCoordinates(currentChessCell->getCoordinates(), chessMovementResponseTransfer);
    }

    ChessCell* previousChessCell = GameApplication::getChessCell(GameApplication::getPreviouslyClickedCellCoordinates());

    for (auto & possibleCoordinates : GameApplicationManager::possibleMovesForClickedCell)
    {
        if (currentChessCell->getCoordinates().first == possibleCoordinates.second
            && currentChessCell->getCoordinates().second == possibleCoordinates.first) {

            return this->moveChessPiece(previousChessCell, currentChessCell, chessMovementResponseTransfer);
        }
    }

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer GameApplicationManager::moveChessPiece(
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    GameApplicationManager::previousPossibleMovesForClickedCell = GameApplicationManager::possibleMovesForClickedCell;
    chessMovementResponseTransfer.setPreviousPossibleMoves(&GameApplicationManager::previousPossibleMovesForClickedCell);

    previousChessCell->getChessPiece()->handleMovement();
    currentChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    chessMovementResponseTransfer.togglePieceMovementValue();
    chessMovementResponseTransfer.setPreviousCellCoordinates(previousChessCell->getCoordinates()).setCurrentCellCoordinates(currentChessCell->getCoordinates());
    chessMovementResponseTransfer.setState(ChessConstants::STATE_MOVED_PIECE);

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer GameApplicationManager::handleMovementWithoutPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {
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

ChessMovementResponseTransfer GameApplicationManager::saveClickedCellCoordinates(std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    GameApplication::setPreviouslyClickedCellCoordinates(currentCellCoordinates);

    return chessMovementResponseTransfer;
}

bool GameApplicationManager::doesChessPieceBelongToCurrentPlayer(BaseChessPiece *currentChessPiece) {
    int currentPlayer = GameApplication::getCurrentPlayer();

    if (currentChessPiece->getPlayer() == currentPlayer) {
        return true;
    }

    return false;
}

ChessMovementResponseTransfer GameApplicationManager::savePossibleMovesForClickedPiece(
        BaseChessPiece *clickedChessPiece, std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    if (!GameApplicationManager::possibleMovesForClickedCell.empty()) {
        GameApplicationManager::previousPossibleMovesForClickedCell = GameApplicationManager::possibleMovesForClickedCell;
    }

    GameApplicationManager::possibleMovesForClickedCell = clickedChessPiece->determinePossibleMoves(GameApplication::getChessField(), currentCellCoordinates);
    if (!GameApplicationManager::possibleMovesForClickedCell.empty()) {
        chessMovementResponseTransfer.setPossibleMoves(&GameApplicationManager::possibleMovesForClickedCell);
        chessMovementResponseTransfer.togglePossibleMovesCheckValue();
    }

    if (!GameApplicationManager::previousPossibleMovesForClickedCell.empty()) {
        chessMovementResponseTransfer.setPreviousPossibleMoves(&GameApplicationManager::previousPossibleMovesForClickedCell);
    }

    return chessMovementResponseTransfer;
}

void GameApplicationManager::endCurrentTurn() {
    GameApplication::toggleCurrentPlayer();
    GameApplication::togglePreviousClickedCellValue();

    GameApplicationManager::possibleMovesForClickedCell.clear();
    GameApplicationManager::previousPossibleMovesForClickedCell.clear();
}





