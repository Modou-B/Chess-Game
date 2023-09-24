//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTTRAIT_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTTRAIT_H

#include <utility>

class ChessPieceMovementTrait {
public:
    static bool areCoordinatesOutOfBounds(int xCoordinate, int yCoordinate);

    static std::pair<int, int> generateXYCoordinates(int xCoordinate, int yCoordinate);
    static std::pair<int, int> generateYXCoordinates(int xCoordinate, int yCoordinate);
};

#endif // CHESSAPPLICATION_CHESSPIECEMOVEMENTTRAIT_H
