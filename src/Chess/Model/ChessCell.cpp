//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCell.h"

ChessCell::ChessCell(BaseChessPiece *chessPiece) {
    this->chessPiece = chessPiece;
    // Connect button signal to appropriate slot
    connect(this, &QPushButton::released, this, &ChessCell::handleButton);
}

void ChessCell::handleButton() {
    exit(1);
}
