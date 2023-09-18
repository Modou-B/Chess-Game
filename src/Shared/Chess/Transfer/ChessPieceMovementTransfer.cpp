//
// Created by Julian Sommer on 16.09.23.
//

#include "ChessPieceMovementTransfer.h"

ChessPieceMovementTransfer &ChessPieceMovementTransfer::setAction(std::string action) {
    this->action = action;

    return *this;
}

ChessPieceMovementTransfer &ChessPieceMovementTransfer::setOldCoordinates(std::pair<int, int> oldCoordinates) {
    this->oldCoordinates = oldCoordinates;

    return *this;
}

ChessPieceMovementTransfer &ChessPieceMovementTransfer::setNewCoordinates(std::pair<int, int> newCoordinates) {
    this->newCoordinates = newCoordinates;

    return *this;
}

std::string ChessPieceMovementTransfer::getAction() {
    return this->action;
}

std::pair<int, int> ChessPieceMovementTransfer::getOldCoordinates() {
    return this->oldCoordinates;
}

std::pair<int, int> ChessPieceMovementTransfer::getNewCoordinates() {
    return this->newCoordinates;
}