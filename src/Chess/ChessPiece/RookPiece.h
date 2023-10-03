//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_ROOKPIECE_H
#define CHESSAPPLICATION_ROOKPIECE_H

#include "BaseChessPiece.h"

class ChessPieceMovementMapper;
class ChessPiecePossibleMoveTransfer;
class KingPieceMovementChecker;

class RookPiece: public BaseChessPiece {
public:
    RookPiece(int player, ChessPieceMovementMapper *chessPieceMovementMapper, KingPieceMovementChecker *kingPieceMovementChecker);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_ROOKPIECE_H
