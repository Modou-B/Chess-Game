//
// Created by Julian Sommer on 06.09.23.
//

#include "GameApplication.h"

#include "../Model/ChessField.h"

ChessField *GameApplication::chessField = nullptr;
int GameApplication::currentPlayer = 1;
bool GameApplication::wasCellWithChessPieceClickedValue = false;
std::pair<int, int> GameApplication::previouslyClickedCell;

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

void GameApplication::setCurrentPlayer(int player) {
    GameApplication::currentPlayer = player;
}
