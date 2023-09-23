//
// Created by Julian Sommer on 29.08.23.
//

#include "KnightPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"

KnightPiece::KnightPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator): BaseChessPiece(ChessConstants::KNIGHT_PIECE_TYPE, player, chessPieceMovementGenerator) {}

std::vector<ChessPiecePossibleMoveTransfer*> KnightPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->checkVerticalMovement(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->checkVerticalMovement(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> KnightPiece::checkVerticalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate + 2));
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate - 2));

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> KnightPiece::checkHorizontalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 2), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 2), yCoordinate);

    return possibleMoves;
}