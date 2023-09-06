//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessField.h"
#include "ChessCell.h"

ChessCell *ChessField::getChessCell(std::pair<int, int> coordinates) {
    return this->chessField[coordinates.first][coordinates.second];
}

void ChessField::addChessCell(ChessCell *chessCell) {
    auto coordinates = chessCell->getCoordinates();

    this->chessField[coordinates.first][coordinates.second] = chessCell;
}

