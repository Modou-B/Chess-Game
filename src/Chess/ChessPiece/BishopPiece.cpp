//
// Created by Julian Sommer on 29.08.23.
//

#include "BishopPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"

BishopPiece::BishopPiece(
    int player, 
    ChessPieceMovementGenerator *chessPieceMovementGenerator,
    KingPieceMovementChecker *kingPieceMovementChecker
    ): BaseChessPiece(ChessConstants::BISHOP_PIECE_TYPE, player, chessPieceMovementGenerator, kingPieceMovementChecker) {}

std::vector<ChessPiecePossibleMoveTransfer*> BishopPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->tryToAddCoordinatesForDiagonalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}