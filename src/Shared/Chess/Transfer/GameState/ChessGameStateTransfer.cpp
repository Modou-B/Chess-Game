//
// Created by Julian Sommer on 25.09.23.
//

#include "ChessGameStateTransfer.h"

ChessGameStateTransfer *ChessGameStateTransfer::setCurrentGameState(string gameState) {
    this->currentGameState = gameState;

    return this;
}

ChessGameStateTransfer *ChessGameStateTransfer::setCurrentPlayer(int player) {
    this->currentPlayer = player;

    return this;
}

ChessGameStateTransfer *ChessGameStateTransfer::setCurrentOpponentPlayer(int player) {
    this->currentOpponentPlayer = player;

    return this;
}

ChessGameStateTransfer *ChessGameStateTransfer::setTurnCounter(int turnCounter) {
    this->turnCounter = turnCounter;

    return this;
}

ChessGameStateTransfer *ChessGameStateTransfer::setLastTurnClickedCellCoordinate(
    pair<int, int> lastTurnClickedCellCoordinate
) {
    this->lastTurnClickedCellCoordinate = lastTurnClickedCellCoordinate;

    return this;
}

string ChessGameStateTransfer::getCurrentGameState() {
    return this->currentGameState;
}

int ChessGameStateTransfer::getCurrentPlayer() {
    return this->currentPlayer;
}

int ChessGameStateTransfer::getCurrentOpponentPlayer() {
    return this->currentOpponentPlayer;
}

int ChessGameStateTransfer::getTurnCounter() {
    return this->turnCounter;
}

pair<int, int> ChessGameStateTransfer::getLastTurnClickedCellCoordinate() {
    return this->lastTurnClickedCellCoordinate;
}