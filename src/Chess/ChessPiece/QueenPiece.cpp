//
// Created by Julian Sommer on 29.08.23.
//

#include "QueenPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"

QueenPiece::QueenPiece(
    int player,
    ChessPieceMovementMapper *chessPieceMovementMapper,
    KingPieceMovementChecker *kingPieceMovementChecker
    ): BaseChessPiece(ChessConstants::QUEEN_PIECE_TYPE, player, chessPieceMovementMapper, kingPieceMovementChecker) {}

std::vector<ChessPiecePossibleMoveTransfer*> QueenPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinatesForDiagonalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForVerticalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForHorizontalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}