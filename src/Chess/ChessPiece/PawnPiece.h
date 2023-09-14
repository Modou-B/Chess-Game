//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_PAWNPIECE_H
#define CHESSAPPLICATION_PAWNPIECE_H

#include "BaseChessPiece.h"
#include <vector>
#include <utility>

class PawnPiece: public BaseChessPiece {
private:
    bool hasMoved;

protected:
    std::vector<std::pair<int, int>> determinePossibleMovesForPlayer1(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<std::pair<int, int>> determinePossibleMovesForPlayer2(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);

    // method checkForEnPassant
    // method checkForDiagonalPieces
public:
    PawnPiece(int player);

    std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) override;

    void handleMovement() override;
};


#endif //CHESSAPPLICATION_PAWNPIECE_H
