//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_BISHOPPIECE_H
#define CHESSAPPLICATION_BISHOPPIECE_H

#include "BaseChessPiece.h"

class BishopPiece: public BaseChessPiece {
public:
    BishopPiece(int player);

    std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_BISHOPPIECE_H
