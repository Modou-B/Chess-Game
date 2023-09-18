//
// Created by Julian Sommer on 29.08.23.
//

#include "KingPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"

KingPiece::KingPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator): BaseChessPiece("King", player, chessPieceMovementGenerator) {
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::checkHorizontalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}
