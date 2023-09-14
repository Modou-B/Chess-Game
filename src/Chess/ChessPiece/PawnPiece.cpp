//
// Created by Julian Sommer on 29.08.23.
//

#include "PawnPiece.h"
#include "iostream"

PawnPiece::PawnPiece(int player): BaseChessPiece("Pawn", player) {
    this->hasMoved = false;
}

std::vector<std::pair<int, int>> PawnPiece::determinePossibleMovesForPlayer1(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    yCoordinate--;
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);

    if (!this->hasMoved) {
        yCoordinate--;
        possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);
    }

    return possibleMoves;
}

std::vector<std::pair<int, int>> PawnPiece::determinePossibleMovesForPlayer2(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {

    yCoordinate++;
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);

    if (!this->hasMoved) {
        yCoordinate++;
        possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);
    }

    return possibleMoves;
}


void PawnPiece::handleMovement() {
    this->hasMoved = !this->hasMoved;
}

std::vector<std::pair<int, int>> PawnPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    if (this->getPlayer() == 1) {
        return this->determinePossibleMovesForPlayer1(chessField, possibleMoves, xCoordinate, yCoordinate);
    }

    return this->determinePossibleMovesForPlayer2(chessField, possibleMoves, xCoordinate, yCoordinate);
}
