//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_KNIGHTPIECE_H
#define CHESSAPPLICATION_KNIGHTPIECE_H

#include "BaseChessPiece.h"

class ChessPieceMovementMapper;
class ChessPiecePossibleMoveTransfer;
class KingPieceMovementChecker;

class KnightPiece: public BaseChessPiece {
protected:
    std::vector<ChessPiecePossibleMoveTransfer*> checkHorizontalMovement(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<ChessPiecePossibleMoveTransfer*> checkVerticalMovement(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);
public:
    KnightPiece(int player, ChessPieceMovementMapper *chessPieceMovementMapper, KingPieceMovementChecker *kingPieceMovementChecker);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_KNIGHTPIECE_H
