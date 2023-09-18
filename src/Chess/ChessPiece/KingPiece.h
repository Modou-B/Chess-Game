//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_KINGPIECE_H
#define CHESSAPPLICATION_KINGPIECE_H

#include "BaseChessPiece.h"

class ChessPieceMovementGenerator;
class ChessPiecePossibleMoveTransfer;

class KingPiece: public BaseChessPiece {
protected:
    std::vector<ChessPiecePossibleMoveTransfer*> checkHorizontalMovement(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);
public:
    KingPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_KINGPIECE_H
