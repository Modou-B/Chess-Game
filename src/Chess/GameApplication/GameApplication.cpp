//
// Created by Julian Sommer on 06.09.23.
//

#include "GameApplication.h"

#include "../Model/ChessField.h"

ChessField *GameApplication::chessField = nullptr;
int GameApplication::currentPlayer = 1;
bool GameApplication::isTurnFinished = false;
bool GameApplication::wasCellWithChessPieceClickedValue = false;

std::pair<int, int> GameApplication::previouslyClickedCell;
bool GameApplication::hasPreviousClickedCell = false;

int GameApplication::getCurrentPlayer() {
    return GameApplication::currentPlayer;
}

ChessCell *GameApplication::getChessCell(std::pair<int, int> cellCoordinates) {
    return GameApplication::chessField->getChessCell(cellCoordinates);
}

bool GameApplication::wasCellWithChessPieceClicked() {
    return GameApplication::wasCellWithChessPieceClickedValue;
}

std::pair<int, int> GameApplication::getPreviouslyClickedCellCoordinates() {
    return GameApplication::previouslyClickedCell;
}

void GameApplication::setChessField(ChessField *chessFieldModel) {
    GameApplication::chessField = chessFieldModel;
}

void GameApplication::toggleCellWithChessPieceClickedValue() {
    GameApplication::wasCellWithChessPieceClickedValue = !GameApplication::wasCellWithChessPieceClickedValue;
}

void GameApplication::setPreviouslyClickedCellCoordinates(std::pair<int, int> currentCellCoordinates) {
    GameApplication::previouslyClickedCell = currentCellCoordinates;

    GameApplication::togglePreviousClickedCellValue();
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
