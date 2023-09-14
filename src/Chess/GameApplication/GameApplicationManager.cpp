//
// Created by Julian Sommer on 07.09.23.
//

#include "GameApplicationManager.h"
#include "../Creator/ChessCreator.h"
#include "../Model/ChessCell.h"
#include "../ChessPiece/BaseChessPiece.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "GameApplication.h"
#include "iostream"

std::vector<std::pair<int, int>> GameApplicationManager::possibleMovesForClickedCell;

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
        this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates());

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
    currentChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    chessMovementResponseTransfer.togglePieceMovementValue();
    chessMovementResponseTransfer.setPreviousCellCoordinates(previousChessCell->getCoordinates()).setCurrentCellCoordinates(currentChessCell->getCoordinates());

    this->endCurrentTurn();

    return chessMovementResponseTransfer;
}

ChessMovementResponseTransfer GameApplicationManager::handleMovementWithoutPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer) {
    BaseChessPiece *currentChessPiece = currentChessCell->getChessPiece();

    if (!currentChessPiece) {
        return chessMovementResponseTransfer;
    }

    if (this->doesChessPieceBelongToCurrentPlayer(currentChessPiece)) {
        this->savePossibleMovesForClickedPiece(currentChessPiece, currentChessCell->getCoordinates());

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

void GameApplicationManager::savePossibleMovesForClickedPiece(BaseChessPiece *clickedChessPiece, std::pair<int, int> currentCellCoordinates) {

    GameApplicationManager::possibleMovesForClickedCell = clickedChessPiece->determinePossibleMoves(GameApplication::getChessField(), currentCellCoordinates);
}

void GameApplicationManager::endCurrentTurn() {
    GameApplication::toggleCurrentPlayer();
    GameApplication::togglePreviousClickedCellValue();

    GameApplicationManager::possibleMovesForClickedCell.clear();
}





