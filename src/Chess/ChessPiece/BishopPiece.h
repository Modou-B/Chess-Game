//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_BISHOPPIECE_H
#define CHESSAPPLICATION_BISHOPPIECE_H

#include "BaseChessPiece.h"

class ChessPieceMovementGenerator;
class ChessPiecePossibleMoveTransfer;

class BishopPiece: public BaseChessPiece {
public:
    BishopPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_BISHOPPIECE_H
