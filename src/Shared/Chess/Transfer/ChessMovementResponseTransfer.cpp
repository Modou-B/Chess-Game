//
// Created by Julian Sommer on 07.09.23.
//

#include "ChessMovementResponseTransfer.h"

ChessMovementResponseTransfer::ChessMovementResponseTransfer() {
    this->hasPieceMoved = false;
}

bool ChessMovementResponseTransfer::wasPieceMoved() {
    return this->hasPieceMoved;
}

std::pair<int, int> ChessMovementResponseTransfer::getPreviousCellCoordinates() {
    return this->previousCellCoordinates;
}

std::pair<int, int> ChessMovementResponseTransfer::getCurrentCellCoordinates() {
    return this->currentCellCoordinates;
}

void ChessMovementResponseTransfer::togglePieceMovementValue() {
    this->hasPieceMoved = !this->hasPieceMoved;
}

ChessMovementResponseTransfer &ChessMovementResponseTransfer::setPreviousCellCoordinates(std::pair<int, int> coordinates) {
    this->previousCellCoordinates = coordinates;

    return *this;
}

ChessMovementResponseTransfer &ChessMovementResponseTransfer::setCurrentCellCoordinates(std::pair<int, int> coordinates) {
    this->currentCellCoordinates = coordinates;

    return *this;
}
