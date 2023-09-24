//
// Created by Julian Sommer on 07.09.23.
//

#include "ChessMovementResponseTransfer.h"
#include "ChessPieceMovementTransfer.h"
#include "ChessPiecePossibleMoveTransfer.h"

ChessMovementResponseTransfer::ChessMovementResponseTransfer() {
    this->hasPieceMoved = false;
    this->hasPossibleMoves = false;
    this->hasKingMoved = false;
    this->state = "";
    this->chessPiecesToMove = new std::vector<ChessPieceMovementTransfer*>();
}

bool ChessMovementResponseTransfer::wasPieceMoved() {
    return this->hasPieceMoved;
}

void ChessMovementResponseTransfer::togglePieceMovementValue() {
    this->hasPieceMoved = !this->hasPieceMoved;
}

ChessMovementResponseTransfer &ChessMovementResponseTransfer::addChessPieceMovementTransfer(ChessPieceMovementTransfer *chessPieceMovementTransfer) {
    this->chessPiecesToMove->push_back(chessPieceMovementTransfer);

    return *this;
}

ChessMovementResponseTransfer &ChessMovementResponseTransfer::setCurrentCellCoordinates(std::pair<int, int> currentCellCoordinates) {
    this->currentCellCoordinates = currentCellCoordinates;

    return *this;
}

ChessMovementResponseTransfer &ChessMovementResponseTransfer::setHasKingMoved(bool value) {
    this->hasKingMoved = value;

    return *this;
}

std::pair<int, int> ChessMovementResponseTransfer::getCurrentCellCoordinates() {
    return this->currentCellCoordinates;
}

std::vector<ChessPiecePossibleMoveTransfer*> *ChessMovementResponseTransfer::getPossibleMoves() {
    return &this->possibleMoves;
}

bool ChessMovementResponseTransfer::doesPieceHasPossibleMoves() {
    return this->hasPossibleMoves;
}

void ChessMovementResponseTransfer::togglePossibleMovesCheckValue() {
    this->hasPossibleMoves = !this->hasPossibleMoves;
}

void ChessMovementResponseTransfer::setPossibleMoves(std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves) {
    this->possibleMoves = possibleMoves;
}

std::string ChessMovementResponseTransfer::getState() {
    return this->state;
}

void ChessMovementResponseTransfer::setState(std::string state) {
    this->state = state;
}

void ChessMovementResponseTransfer::setPreviousPossibleMoves(std::vector<ChessPiecePossibleMoveTransfer*> *previousPossibleMoves) {
    this->previousPossibleMoves = previousPossibleMoves;
}

void ChessMovementResponseTransfer::setPossibleMovesCheckValue(bool value) {
    this->hasPossibleMoves = value;
}

std::vector<ChessPiecePossibleMoveTransfer*> *ChessMovementResponseTransfer::getPreviousPossibleMoves() {
    return this->previousPossibleMoves;
}

std::vector<ChessPieceMovementTransfer *> *ChessMovementResponseTransfer::getChessPiecesToMove() {
    return this->chessPiecesToMove;
}

bool ChessMovementResponseTransfer::getHasKingMoved() {
    return this->hasKingMoved;
}