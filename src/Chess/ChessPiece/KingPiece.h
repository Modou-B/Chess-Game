//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_KINGPIECE_H
#define CHESSAPPLICATION_KINGPIECE_H

#include "BaseChessPiece.h"

class KingPiece: public BaseChessPiece {
protected:
    std::vector<std::pair<int, int>> checkHorizontalMovement(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);
public:
    KingPiece(int player);

    std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_KINGPIECE_H
