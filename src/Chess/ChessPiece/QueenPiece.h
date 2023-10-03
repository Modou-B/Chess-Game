//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_QUEENPIECE_H
#define CHESSAPPLICATION_QUEENPIECE_H

#include "BaseChessPiece.h"

class ChessPieceMovementMapper;
class ChessPiecePossibleMoveTransfer;
class KingPieceMovementChecker;

class QueenPiece: public BaseChessPiece {
public:
    QueenPiece(int player, ChessPieceMovementMapper *chessPieceMovementMapper, KingPieceMovementChecker *kingPieceMovementChecker);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_QUEENPIECE_H
