//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_ROOKPIECE_H
#define CHESSAPPLICATION_ROOKPIECE_H

#include "BaseChessPiece.h"

class ChessPieceMovementGenerator;
class ChessPiecePossibleMoveTransfer;

class RookPiece: public BaseChessPiece {
public:
    RookPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_ROOKPIECE_H
