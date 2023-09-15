//
// Created by Julian Sommer on 29.08.23.
//

#include "QueenPiece.h"
#include "iostream"
QueenPiece::QueenPiece(int player): BaseChessPiece("Queen", player) {}

std::vector<std::pair<int, int>> QueenPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinatesForDiagonalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForVerticalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForHorizontalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}