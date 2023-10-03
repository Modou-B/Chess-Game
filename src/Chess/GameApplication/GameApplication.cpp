//
// Created by Julian Sommer on 06.09.23.
//

#include "GameApplication.h"
#include "../Model/ChessField.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"

ChessField *GameApplication::chessField = nullptr;
ChessPlayerData *GameApplication::chessPlayer1Data = nullptr;
ChessPlayerData *GameApplication::chessPlayer2Data = nullptr;

ChessMovementResponseTransfer GameApplication::savedChessMovementResponseTransfer = {};
string GameApplication::currentGameState = "";

int GameApplication::currentPlayer = 1;
int GameApplication::currentOpponentPlayer = 2;
int GameApplication::turnCounter = 0;

pair<int, int> GameApplication::previouslyClickedCell;
pair<int, int> GameApplication::coordinatesOfLastTurnClickedCell;

bool GameApplication::hasPreviousClickedCell = false;

int GameApplication::getCurrentPlayer() {
    return GameApplication::currentPlayer;
}

ChessCell *GameApplication::getChessCell(pair<int, int> cellCoordinates) {
    return GameApplication::chessField->getChessCell(cellCoordinates);
}

pair<int, int> GameApplication::getPreviouslyClickedCellCoordinates() {
    return GameApplication::previouslyClickedCell;
}

pair<int, int> GameApplication::getCoordinatesOfLastTurnClickedCell() {
    return GameApplication::coordinatesOfLastTurnClickedCell;
}

void GameApplication::setChessField(ChessField *chessFieldModel) {
    GameApplication::chessField = chessFieldModel;
}

void GameApplication::setChessPlayer1Data(ChessPlayerData *chessPlayerData) {
    GameApplication::chessPlayer1Data = chessPlayerData;
}

void GameApplication::setChessPlayer2Data(ChessPlayerData *chessPlayerData) {
    GameApplication::chessPlayer2Data = chessPlayerData;
}

void GameApplication::setCurrentPlayer(int currentPlayer) {
    GameApplication::currentPlayer = currentPlayer;
}

void GameApplication::setCurrentOpponentPlayer(int currentOpponentPlayer) {
    GameApplication::currentOpponentPlayer = currentOpponentPlayer;
}

void GameApplication::setTurnCounter(int turnCounter) {
    GameApplication::turnCounter = turnCounter;
}

void GameApplication::setCurrentGameState(string gameState) {
    GameApplication::currentGameState = gameState;
}

void GameApplication::saveChessMovementResponseTransfer(
    ChessMovementResponseTransfer chessMovementResponseTransfer
) {
    GameApplication::savedChessMovementResponseTransfer = chessMovementResponseTransfer;
}

void GameApplication::setPreviouslyClickedCellCoordinates(pair<int, int> currentCellCoordinates) {
    GameApplication::previouslyClickedCell = currentCellCoordinates;

    GameApplication::hasPreviousClickedCell = true;
}

void GameApplication::setCoordinatesOfLastTurnClickedCell(pair<int, int> lastTurnClickedCell) {
    GameApplication::coordinatesOfLastTurnClickedCell = lastTurnClickedCell;
}

void GameApplication::togglePreviousClickedCellValue() {
    GameApplication::hasPreviousClickedCell = !GameApplication::hasPreviousClickedCell;
}

bool GameApplication::wasPreviousCellClicked() {
    return GameApplication::hasPreviousClickedCell;
}

ChessField *GameApplication::getChessField() {
    return GameApplication::chessField;
}

// deprecated
void GameApplication::toggleCurrentPlayer() {
    if (GameApplication::currentPlayer == 1) {
        GameApplication::currentPlayer = 2;

        return;
    }

    GameApplication::currentPlayer = 1;
}

int GameApplication::getTurnCounter() {
    return GameApplication::turnCounter;
}

ChessPlayerData *GameApplication::getCurrentChessPlayerData() {
    if (GameApplication::getCurrentPlayer() == 1) {
        return GameApplication::chessPlayer1Data;
    }

    return GameApplication::chessPlayer2Data;
}

ChessPlayerData *GameApplication::getOpponentChessPlayerData() {
    if (GameApplication::getCurrentPlayer() == 1) {
        return GameApplication::chessPlayer2Data;
    }

    return GameApplication::chessPlayer1Data;
}

ChessPlayerData *GameApplication::getChessPlayerDataForPlayer(int player)
{
    if (player == 1) {
      return GameApplication::chessPlayer1Data;
    }

    return GameApplication::chessPlayer2Data;
}

int GameApplication::getCurrentOpponentPlayer() {
    return GameApplication::currentOpponentPlayer;
}

string GameApplication::getCurrentGameState() {
    return GameApplication::currentGameState;
}

ChessMovementResponseTransfer GameApplication::getSavedChessMovementResponseTransfer() {
    return GameApplication::savedChessMovementResponseTransfer;
}

void GameApplication::increaseTurnCounter() {
    GameApplication::turnCounter++;
}

void GameApplication::switchPlayers() {
    int currentPlayer = GameApplication::currentPlayer;

    GameApplication::currentPlayer = GameApplication::currentOpponentPlayer;
    GameApplication::currentOpponentPlayer = currentPlayer;
}