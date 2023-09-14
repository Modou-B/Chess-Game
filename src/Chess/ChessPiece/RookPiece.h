//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_ROOKPIECE_H
#define CHESSAPPLICATION_ROOKPIECE_H

#include "BaseChessPiece.h"

class RookPiece: public BaseChessPiece {
public:
    RookPiece(int player);

    std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_ROOKPIECE_H
