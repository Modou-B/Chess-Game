//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessField.h"
#include "ChessCell.h"

ChessCell *ChessField::getChessCell(int xPosition, int yPosition) {
    return this->chessField[xPosition][yPosition];
}

void ChessField::addChessCell(ChessCell *chessCell) {
    auto coordinates = chessCell->getCoordinates();

    this->chessField[coordinates.first][coordinates.second] = chessCell;
}
