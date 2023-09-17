//
// Created by Julian Sommer on 07.09.23.
//

#include "GameApplicationManager.h"
#include "../Creator/ChessCreator.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "GameApplication.h"
#include "ChessPiece/Movement/ChessPieceMovementManager.h"
#include "../Model/ChessCell.h"
#include "../ChessPiece/BaseChessPiece.h"

GameApplicationManager::GameApplicationManager(ChessCreator *chessCreator, ChessPieceMovementManager* chessPieceMovementManager) {
    this->chessCreator = chessCreator;
    this->chessPieceMovementManager = chessPieceMovementManager;
}

void GameApplicationManager::initiateChessApplication() {
    auto *chessField = this->chessCreator->initiateChessField();

    GameApplication::setChessField(chessField);
}

ChessMovementResponseTransfer GameApplicationManager::handleChessCellClick(std::pair<int, int> currentCellCoordinates) {
    auto chessMovementResponseTransfer = this->chessPieceMovementManager->handleChessMovement(currentCellCoordinates);

    return chessMovementResponseTransfer;
}

void GameApplicationManager::endCurrentTurn(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    GameApplication::toggleCurrentPlayer();
    GameApplication::togglePreviousClickedCellValue();

    this->updateStateLastTurnChessPieces();

    GameApplication::increaseTurnCounter();
    GameApplication::setCoordinatesOfLastTurnClickedCell(chessMovementResponseTransfer.getCurrentCellCoordinates());

    this->chessPieceMovementManager->clearPossibleMoveCollections();
}

void GameApplicationManager::updateStateLastTurnChessPieces() {
    if (GameApplication::getTurnCounter() == 0) {
        return;
    }

    auto *lastTurnClickedChessCellChessPiece = GameApplication::getChessCell(GameApplication::getCoordinatesOfLastTurnClickedCell())->getChessPiece();
    lastTurnClickedChessCellChessPiece->updateLastTurnMovedStatus();
}
