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

ChessField *ChessField::getCopy() {
    auto *chessFieldCopy = new ChessField;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto coordinates = std::make_pair(i, j);
            chessFieldCopy->addChessCell(this->getChessCell(coordinates)->getCopy());
        }
    }

    return chessFieldCopy;
}

