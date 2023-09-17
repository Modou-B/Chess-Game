//
// Created by Julian Sommer on 17.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTGENERATOR_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTGENERATOR_H

#include <string>
#include <utility>

class ChessPiecePossibleMoveTransfer;
class ChessPieceMovementTransfer;

class ChessPieceMovementGenerator {
public:
    ChessPiecePossibleMoveTransfer *generateChessPiecePossibleMoveTransfer(
            std::string moveType, int xCoordinate, int yCoordinate);

    ChessPieceMovementTransfer *generateChessPieceMovementTransfer(
            std::string action, std::pair<int, int> oldCoordinates, std::pair<int, int> newCoordinates);

    ChessPieceMovementTransfer *generateChessPieceMovementTransfer(
            std::string action, std::pair<int, int> oldCoordinates);
};


#endif //CHESSAPPLICATION_CHESSPIECEMOVEMENTGENERATOR_H
