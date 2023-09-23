//
// Created by Julian Sommer on 29.08.23.
//

#include "QueenPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"

QueenPiece::QueenPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator): BaseChessPiece(ChessConstants::QUEEN_PIECE_TYPE, player, chessPieceMovementGenerator) {}

std::vector<ChessPiecePossibleMoveTransfer*> QueenPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinatesForDiagonalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForVerticalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForHorizontalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}