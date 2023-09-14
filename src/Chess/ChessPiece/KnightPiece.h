//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_KNIGHTPIECE_H
#define CHESSAPPLICATION_KNIGHTPIECE_H

#include "BaseChessPiece.h"

class KnightPiece: public BaseChessPiece {

protected:
    std::vector<std::pair<int, int>> checkHorizontalMovement(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<std::pair<int, int>> checkVerticalMovement(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);
public:
    KnightPiece(int player);

    std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) override;
};


#endif //CHESSAPPLICATION_KNIGHTPIECE_H
