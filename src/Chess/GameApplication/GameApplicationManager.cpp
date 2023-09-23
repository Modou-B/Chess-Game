//
// Created by Julian Sommer on 07.09.23.
//

#include "GameApplicationManager.h"
#include "../Creator/ChessCreator.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "GameApplication.h"
#include "ChessPiece/Movement/ChessPieceMovementManager.h"
#include "../Checkmate/CheckmateManager.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include "Player/ChessPlayerData.h"
#include "../ChessPiece/BaseChessPiece.h"
#include "iostream"
GameApplicationManager::GameApplicationManager(
    ChessCreator *chessCreator, ChessPieceMovementManager* chessPieceMovementManager, CheckmateManager *checkmateManager) {

    this->chessCreator = chessCreator;
    this->chessPieceMovementManager = chessPieceMovementManager;
    this->checkmateManager = checkmateManager;
}

void GameApplicationManager::initiateChessApplication() {
    auto *chessField = new ChessField;
    auto *chessPlayer1Data = new ChessPlayerData;
    auto *chessPlayer2Data = new ChessPlayerData;

    this->chessCreator->initiateChessData(chessField, chessPlayer1Data, chessPlayer2Data);

    GameApplication::setChessField(chessField);
    GameApplication::setChessPlayer1Data(chessPlayer1Data);
    GameApplication::setChessPlayer2Data(chessPlayer2Data);

    this->checkmateManager->setKingPieceCoordinates(std::make_pair(7, 4), 1);
    this->checkmateManager->setKingPieceCoordinates(std::make_pair(0, 4), 2);
}

ChessMovementResponseTransfer GameApplicationManager::handleChessCellClick(std::pair<int, int> currentCellCoordinates) {
    auto playerInCheckStatus = GameApplication::getCurrentChessPlayerData()->isPlayerInCheck();
    auto chessMovementResponseTransfer = this->chessPieceMovementManager->handleChessMovement(currentCellCoordinates, playerInCheckStatus, GameApplication::getOpponentChessPlayerData());

    return chessMovementResponseTransfer;
}

void GameApplicationManager::endCurrentTurn(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    if (chessMovementResponseTransfer.getHasKingMoved()) {
        this->checkmateManager->setKingPieceCoordinates(chessMovementResponseTransfer.getCurrentCellCoordinates(), GameApplication::getCurrentPlayer());
    }

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
    if (lastTurnClickedChessCellChessPiece) {
        lastTurnClickedChessCellChessPiece->updateLastTurnMovedStatus();
    }
}

void GameApplicationManager::startNewTurn() {
    this->checkmateManager->determineCurrentGameState(
      GameApplication::getChessField(),
      GameApplication::getCurrentChessPlayerData(),
      GameApplication::getOpponentChessPlayerData(),
      GameApplication::getCurrentPlayer()
    );
}
