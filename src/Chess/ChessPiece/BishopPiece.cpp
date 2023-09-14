//
// Created by Julian Sommer on 29.08.23.
//

#include "BishopPiece.h"

BishopPiece::BishopPiece(int player): BaseChessPiece("Bishop", player) {}

std::vector<std::pair<int, int>> BishopPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->tryToAddCoordinatesForDiagonalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}