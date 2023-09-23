//
// Created by Julian Sommer on 06.09.23.
//

#include "GameApplication.h"
#include "../Model/ChessField.h"

ChessField *GameApplication::chessField = nullptr;
ChessPlayerData *GameApplication::chessPlayer1Data = nullptr;
ChessPlayerData *GameApplication::chessPlayer2Data = nullptr;

int GameApplication::currentPlayer = 1;
int GameApplication::turnCounter = 0;

std::pair<int, int> GameApplication::previouslyClickedCell;
std::pair<int, int> GameApplication::coordinatesOfLastTurnClickedCell;

bool GameApplication::hasPreviousClickedCell = false;

int GameApplication::getCurrentPlayer() {
    return GameApplication::currentPlayer;
}

ChessCell *GameApplication::getChessCell(std::pair<int, int> cellCoordinates) {
    return GameApplication::chessField->getChessCell(cellCoordinates);
}

std::pair<int, int> GameApplication::getPreviouslyClickedCellCoordinates() {
    return GameApplication::previouslyClickedCell;
}

std::pair<int, int> GameApplication::getCoordinatesOfLastTurnClickedCell() {
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

void GameApplication::setPreviouslyClickedCellCoordinates(std::pair<int, int> currentCellCoordinates) {
    GameApplication::previouslyClickedCell = currentCellCoordinates;

    GameApplication::hasPreviousClickedCell = true;
}

void GameApplication::setCoordinatesOfLastTurnClickedCell(std::pair<int, int> lastTurnClickedCell) {
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

void GameApplication::increaseTurnCounter() {
    GameApplication::turnCounter++;
}
