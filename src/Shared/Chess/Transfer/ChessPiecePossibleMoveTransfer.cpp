//
// Created by Julian Sommer on 17.09.23.
//

#include "ChessPiecePossibleMoveTransfer.h"

ChessPiecePossibleMoveTransfer &ChessPiecePossibleMoveTransfer::setMoveType(std::string moveType) {
    this->moveType = moveType;

    return *this;
}

ChessPiecePossibleMoveTransfer &ChessPiecePossibleMoveTransfer::setXCoordinate(int xCoordinate) {
    this->xCoordinate = xCoordinate;

    return *this;
}

ChessPiecePossibleMoveTransfer &ChessPiecePossibleMoveTransfer::setYCoordinate(int yCoordinate) {
    this->yCoordinate = yCoordinate;

    return *this;
}

std::string ChessPiecePossibleMoveTransfer::getMoveType() {
    return this->moveType;
}

int ChessPiecePossibleMoveTransfer::getXCoordinate() {
    return this->xCoordinate;
}

int ChessPiecePossibleMoveTransfer::getYCoordinate() {
    return this->yCoordinate;
}

