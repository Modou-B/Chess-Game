//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCell.h"

ChessCell::ChessCell(ChessField *chessFieldModel, BaseChessPiece *chessPiece, std::pair<int, int> coordinates) {
    this->chessFieldModel = chessFieldModel;
    this->chessPiece = chessPiece;
    this->coordinates = coordinates;
    // Connect button signal to appropriate slot
    this->connect(this, &QPushButton::released, this, &ChessCell::handleButton);
}

void ChessCell::handleButton() {

    exit(1);
}

void ChessCell::setChessPiece(BaseChessPiece *baseChessPiece) {
    this->chessPiece = baseChessPiece;
}

std::pair<int, int> ChessCell::getCoordinates() {
    return this->coordinates;
}
