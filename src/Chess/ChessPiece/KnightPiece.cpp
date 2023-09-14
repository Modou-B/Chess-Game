//
// Created by Julian Sommer on 29.08.23.
//

#include "KnightPiece.h"

KnightPiece::KnightPiece(int player): BaseChessPiece("Knight", player) {}

std::vector<std::pair<int, int>> KnightPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->checkVerticalMovement(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->checkVerticalMovement(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<std::pair<int, int>> KnightPiece::checkVerticalMovement(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate + 2));
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate - 2));

    return possibleMoves;
}

std::vector<std::pair<int, int>> KnightPiece::checkHorizontalMovement(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 2), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 2), yCoordinate);

    return possibleMoves;
}