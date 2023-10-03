//
// Created by Julian Sommer on 18.09.23.
//

#include "ChessPieceMovementTrait.h"

bool ChessPieceMovementTrait::areCoordinatesOutOfBounds(int xCoordinate, int yCoordinate) {
    if ((xCoordinate > 7 || xCoordinate < 0) || (yCoordinate > 7 || yCoordinate < 0)) {
        return true;
    }

    return false;
}

std::pair<int, int> ChessPieceMovementTrait::generateXYCoordinates(int xCoordinate, int yCoordinate) {
    return std::make_pair(xCoordinate, yCoordinate);
}

std::pair<int, int> ChessPieceMovementTrait::generateYXCoordinates(int xCoordinate, int yCoordinate) {
    return std::make_pair(yCoordinate, xCoordinate);
}