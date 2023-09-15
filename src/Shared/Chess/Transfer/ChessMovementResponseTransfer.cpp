//
// Created by Julian Sommer on 07.09.23.
//

#include "ChessMovementResponseTransfer.h"

ChessMovementResponseTransfer::ChessMovementResponseTransfer() {
    this->hasPieceMoved = false;
    this->hasPossibleMoves = false;
    this->state = "";
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

std::vector<std::pair<int, int>> *ChessMovementResponseTransfer::getPossibleMoves() {
    return this->possibleMoves;
}

bool ChessMovementResponseTransfer::doesPieceHasPossibleMoves() {
    return this->hasPossibleMoves;
}

void ChessMovementResponseTransfer::togglePossibleMovesCheckValue() {
    this->hasPossibleMoves = !this->hasPossibleMoves;
}

void ChessMovementResponseTransfer::setPossibleMoves(std::vector<std::pair<int, int>> *possibleMoves) {
    this->possibleMoves = possibleMoves;
}

std::string ChessMovementResponseTransfer::getState() {
    return this->state;
}

void ChessMovementResponseTransfer::setState(std::string state) {
    this->state = state;
}

void ChessMovementResponseTransfer::setPreviousPossibleMoves(std::vector<std::pair<int, int>> *previousPossibleMoves) {
    this->previousPossibleMoves = previousPossibleMoves;
}

std::vector<std::pair<int, int>> *ChessMovementResponseTransfer::getPreviousPossibleMoves() {
    return this->previousPossibleMoves;
}
