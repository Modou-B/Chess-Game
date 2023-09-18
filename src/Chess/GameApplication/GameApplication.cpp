//
// Created by Julian Sommer on 06.09.23.
//

#include "GameApplication.h"

#include "../Model/ChessField.h"

ChessField *GameApplication::chessField = nullptr;
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

void GameApplication::increaseTurnCounter() {
    GameApplication::turnCounter++;
}
