//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTurnLog.h"
#include "ChessPieceLog.h"

ChessTurnLog::ChessTurnLog(int currentPlayer, int turnCounter, std::vector<ChessPieceLog *> *chessPieceLogs) {
    this->currentPlayer = currentPlayer;
    this->turnCounter = turnCounter;
    this->chessPieceLogs = chessPieceLogs;
}

ChessTurnLog::ChessTurnLog() {}

void ChessTurnLog::setCurrentPlayer(int player) {
  this->currentPlayer = player;
}

void ChessTurnLog::setTurnCounter(int turnCounter) {
    this->turnCounter = turnCounter;
}

void ChessTurnLog::setChessPieceLogs(std::vector<ChessPieceLog *> *chessPieceLogs) {
  this->chessPieceLogs = chessPieceLogs;
}

int ChessTurnLog::getCurrentPlayer() {
    return this->currentPlayer;
}

int ChessTurnLog::getTurnCounter() {
    return this->turnCounter;
}

std::vector<ChessPieceLog*> *ChessTurnLog::getChessPieceLogs() {
    return this->chessPieceLogs;
}