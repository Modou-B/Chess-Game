//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCell.h"

ChessCell::ChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates) {
    this->chessPiece = chessPiece;
    this->coordinates = coordinates;
}

void ChessCell::setChessPiece(BaseChessPiece *baseChessPiece) {
    this->chessPiece = baseChessPiece;
}

std::pair<int, int> ChessCell::getCoordinates() {
    return this->coordinates;
}

BaseChessPiece *ChessCell::getChessPiece() {
    return this->chessPiece;
}
