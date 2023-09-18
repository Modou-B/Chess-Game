//
// Created by Julian Sommer on 17.09.23.
//

#include "ChessPieceMovementGenerator.h"

#include "../../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPieceMovementTransfer.h"
#include "iostream"
ChessPiecePossibleMoveTransfer *ChessPieceMovementGenerator::generateChessPiecePossibleMoveTransfer(
        std::string moveType, int xCoordinate, int yCoordinate) {

    auto chessPiecePossibleMoveTransfer = new ChessPiecePossibleMoveTransfer;
    chessPiecePossibleMoveTransfer->setMoveType(moveType).setXCoordinate(xCoordinate).setYCoordinate(yCoordinate);

    return chessPiecePossibleMoveTransfer;
}

ChessPieceMovementTransfer *ChessPieceMovementGenerator::generateChessPieceMovementTransfer(
        std::string action, std::pair<int, int> oldCoordinates, std::pair<int, int> newCoordinates) {

    auto chessPieceMovementTransfer = new ChessPieceMovementTransfer;
    chessPieceMovementTransfer->setAction(action).setOldCoordinates(oldCoordinates).setNewCoordinates(newCoordinates);

    return chessPieceMovementTransfer;
}

ChessPieceMovementTransfer *ChessPieceMovementGenerator::generateChessPieceMovementTransfer(
    std::string action, std::pair<int, int> oldCoordinates) {

    auto chessPieceMovementTransfer = new ChessPieceMovementTransfer;
    chessPieceMovementTransfer->setAction(action).setOldCoordinates(oldCoordinates);

    return chessPieceMovementTransfer;
}
