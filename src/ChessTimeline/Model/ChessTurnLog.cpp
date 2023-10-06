//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTurnLog.h"
#include "ChessPieceLog.h"

ChessTurnLog::ChessTurnLog(
    string currentGameState,
    int currentPlayer,
    int currentOpponentPlayer,
    int turnCounter, 
    vector<ChessPieceLog *> *chessPieceLogs
) {
    this->currentGameState = currentGameState;
    this->currentPlayer = currentPlayer;
    this->currentOpponentPlayer = currentOpponentPlayer;
    this->turnCounter = turnCounter;
    this->chessPieceLogs = chessPieceLogs;
}

ChessTurnLog::ChessTurnLog() {}

void ChessTurnLog::setCurrentGameState(string gameState)
{
    this->currentGameState = gameState;
}

void ChessTurnLog::setCurrentPlayer(int player)
{
    this->currentPlayer = player;
}

void ChessTurnLog::setCurrentOpponentPlayer(int player)
{
    this->currentOpponentPlayer = player;
}

void ChessTurnLog::setTurnCounter(int turnCounter)
{
    this->turnCounter = turnCounter;
}

void ChessTurnLog::setCoordinateOfLastTurnClickedCell(
    pair<int, int> coordinateOfLastTurnClickedCell
) {
    this->coordinateOfLastTurnClickedCell = coordinateOfLastTurnClickedCell;
}

void ChessTurnLog::setChessPieceLogs(vector<ChessPieceLog *> *chessPieceLogs)
{
    this->chessPieceLogs = chessPieceLogs;
}

string ChessTurnLog::getCurrentGameState()
{
    return this->currentGameState;
}

int ChessTurnLog::getCurrentPlayer()
{
    return this->currentPlayer;
}

int ChessTurnLog::getCurrentOpponentPlayer()
{
    return this->currentOpponentPlayer;
}

int ChessTurnLog::getTurnCounter()
{
    return this->turnCounter;
}

pair<int, int> ChessTurnLog::getCoordinateOfLastTurnClickedCell()
{
    return this->coordinateOfLastTurnClickedCell;
}

vector<ChessPieceLog*> *ChessTurnLog::getChessPieceLogs()
{
    return this->chessPieceLogs;
}