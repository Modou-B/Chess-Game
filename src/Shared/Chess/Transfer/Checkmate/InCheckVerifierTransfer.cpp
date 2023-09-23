//
// Created by Julian Sommer on 22.09.23.
//

#include "InCheckVerifierTransfer.h"

InCheckVerifierTransfer &InCheckVerifierTransfer::setXCoordinateToVerify(int xCoordinateToVerify) {
    this->xCoordinateToVerify = xCoordinateToVerify;

    return *this;
}

InCheckVerifierTransfer &InCheckVerifierTransfer::setYCoordinateToVerify(int yCoordinateToVerify) {
    this->yCoordinateToVerify = yCoordinateToVerify;

    return *this;
}

InCheckVerifierTransfer &InCheckVerifierTransfer::setCurrentPlayer(int currentPlayer) {
    this->currentPlayer = currentPlayer;

    return *this;
}

InCheckVerifierTransfer &InCheckVerifierTransfer::setMoveCounter(int currentMove) {
    this->moveCounter = currentMove;

    return *this;
}

InCheckVerifierTransfer &InCheckVerifierTransfer::setPieceTypeToCheck(std::string pieceTypeToCheck) {
    this->pieceTypeToCheck = pieceTypeToCheck;

    return *this;
}

void InCheckVerifierTransfer::addLastInCheckBlockedCoordinatesTransfer(InCheckBlockedCoordinatesTransfer* inCheckBlockedCoordinatesTransfer) {
    this->lastCheckedCoordinates.push_back(inCheckBlockedCoordinatesTransfer);
}

int InCheckVerifierTransfer::getXCoordinateToVerify() {
    return this->xCoordinateToVerify;
}

int InCheckVerifierTransfer::getYCoordinateToVerify() {
    return this->yCoordinateToVerify;
}

int InCheckVerifierTransfer::getCurrentPlayer() {
    return this->currentPlayer;
}

int InCheckVerifierTransfer::getMoveCounter() {
    return this->moveCounter;
}

std::string InCheckVerifierTransfer::getPieceTypeToCheck() {
    return this->pieceTypeToCheck;
}

std::vector<InCheckBlockedCoordinatesTransfer*> InCheckVerifierTransfer::getLastInCheckBlockedCoordinatesTransfer() {
    return this->lastCheckedCoordinates;
}

void InCheckVerifierTransfer::clearLastCheckedCoordinates() {
    this->lastCheckedCoordinates.clear();
}