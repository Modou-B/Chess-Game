//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessPieceLog.h"

ChessPieceLog::ChessPieceLog(
    int playerOfChessPiece,
    string chessPieceColor,
    string chessPieceType,
    string chessPieceState,
    pair<int, int> startCellCoordinate,
    pair<int, int> endCellCoordinate
) {
    this->playerOfChessPiece = playerOfChessPiece;
    this->chessPieceColor = chessPieceColor;
    this->chessPieceType = chessPieceType;
    this->chessPieceState = chessPieceState;
    this->startCellCoordinate = startCellCoordinate;
    this->endCellCoordinate = endCellCoordinate;
}

int ChessPieceLog::getPlayerOfChessPiece() {
    return this->playerOfChessPiece;
}

string ChessPieceLog::getChessPieceColor() {
    return this->chessPieceColor;
}

string ChessPieceLog::getChessPieceType() {
    return this->chessPieceType;
}

string ChessPieceLog::getChessPieceState() {
    return this->chessPieceState;
}

pair<int, int> ChessPieceLog::getStartingCellCoordinate() {
    return this->startCellCoordinate;
}

pair<int, int> ChessPieceLog::getEndCellCoordinate() {
    return this->endCellCoordinate;
}