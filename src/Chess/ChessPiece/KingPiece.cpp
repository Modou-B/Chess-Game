//
// Created by Julian Sommer on 29.08.23.
//

#include "KingPiece.h"

KingPiece::KingPiece(int player): BaseChessPiece("King", player) {
}

std::vector<std::pair<int, int>> KingPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<std::pair<int, int>> KingPiece::checkHorizontalMovement(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}
