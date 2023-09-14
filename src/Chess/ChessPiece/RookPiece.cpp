//
// Created by Julian Sommer on 29.08.23.
//

#include "RookPiece.h"

RookPiece::RookPiece(int player): BaseChessPiece("Rook", player) {}

std::vector<std::pair<int, int>> RookPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->tryToAddCoordinatesForHorizontalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForVerticalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}