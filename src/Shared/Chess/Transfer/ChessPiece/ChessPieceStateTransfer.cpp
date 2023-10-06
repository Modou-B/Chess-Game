//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessPieceStateTransfer.h"

ChessPieceStateTransfer *ChessPieceStateTransfer::setPlayerOfChessPiece(int player) {
    this->playerOfChessPiece = player;

    return this;
}

ChessPieceStateTransfer *ChessPieceStateTransfer::setChessPieceType(string chessPieceType) {
    this->chessPieceType = chessPieceType;

    return this;
}

ChessPieceStateTransfer *ChessPieceStateTransfer::setState(string chessPieceState) {
    this->state = chessPieceState;

    return this;
}

ChessPieceStateTransfer *ChessPieceStateTransfer::setMoveCounter(int moveCounter) {
    this->moveCounter = moveCounter;

    return this;
}

ChessPieceStateTransfer *ChessPieceStateTransfer::setUsedDoubleMove(bool usedDoubleMove) {
    this->usedDoubleMove = usedDoubleMove;

    return this;
}

ChessPieceStateTransfer *ChessPieceStateTransfer::setStartCoordinate(pair<int, int> startCoordinate) {
    this->startCoordinate = startCoordinate;

    return this;
}

ChessPieceStateTransfer *ChessPieceStateTransfer::setEndCoordinate(pair<int, int> endCoordinate) {
    this->endCoordinate = endCoordinate;

    return this;
}

int ChessPieceStateTransfer::getPlayerOfChessPiece() {
    return this->playerOfChessPiece;
}

string ChessPieceStateTransfer::getChessPieceType() {
    return this->chessPieceType;
}

string ChessPieceStateTransfer::getState() {
    return this->state;
}

int ChessPieceStateTransfer::getMoveCounter() {
    return this->moveCounter;
}

bool ChessPieceStateTransfer::getUsedDoubleMove() {
    return this->usedDoubleMove;
}

pair<int, int> ChessPieceStateTransfer::getStartCoordinate() {
    return this->startCoordinate;
}

pair<int, int> ChessPieceStateTransfer::getEndCoordinate() {
    return this->endCoordinate;
}
