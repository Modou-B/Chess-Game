//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_QUEENPIECE_H
#define CHESSAPPLICATION_QUEENPIECE_H

#include "BaseChessPiece.h"


class QueenPiece: public BaseChessPiece {
public:
    QueenPiece(int player);

    std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_QUEENPIECE_H
