//
// Created by Julian Sommer on 29.08.23.
//

#include "RookPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"

RookPiece::RookPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator): BaseChessPiece(ChessConstants::ROOK_PIECE_TYPE, player, chessPieceMovementGenerator) {}

std::vector<ChessPiecePossibleMoveTransfer*> RookPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->tryToAddCoordinatesForHorizontalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->tryToAddCoordinatesForVerticalMovement(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}