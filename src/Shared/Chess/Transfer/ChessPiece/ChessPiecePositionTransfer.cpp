//
// Created by Julian Sommer on 01.10.23.
//

#include "ChessPiecePositionTransfer.h"

ChessPiecePositionTransfer *ChessPiecePositionTransfer::setCurrentChessPieceCoordinates(pair<int, int> currentCoordinates) {
    this->currentCoordinates = currentCoordinates;

    return this;
}

pair<int, int> ChessPiecePositionTransfer::getCurrentChessPieceCoordinates() {
    return this->currentCoordinates;
}