//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessPieceStateTransfer.h"
#include <QJsonObject>

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

QJsonObject ChessPieceStateTransfer::toQJsonObject()
{
    QJsonObject jsonObject;

    jsonObject["playerOfChessPiece"] = this->playerOfChessPiece;
    jsonObject["chessPieceType"] = QString::fromStdString(this->chessPieceType);
    jsonObject["chessPieceState"] = QString::fromStdString(this->state);
    jsonObject["moveCounter"] = this->moveCounter;
    jsonObject["usedDoubleMove"] = this->usedDoubleMove;
    jsonObject["startCoordinateY"] = this->startCoordinate.first;
    jsonObject["startCoordinateX"] = this->startCoordinate.second;
    jsonObject["endCoordinateY"] = this->endCoordinate.first;
    jsonObject["endCoordinateX"] = this->endCoordinate.second;

    return jsonObject;
}

void ChessPieceStateTransfer::fromQJsonObject(QJsonObject jsonObject)
{
    this->playerOfChessPiece = jsonObject["playerOfChessPiece"].toInt();
    this->chessPieceType = jsonObject["chessPieceType"].toString().toStdString();
    this->state = jsonObject["chessPieceState"].toString().toStdString();
    this->moveCounter = jsonObject["moveCounter"].toInt();
    this->usedDoubleMove = jsonObject["usedDoubleMove"].toBool();
    this->startCoordinate = pair<int, int>(
        jsonObject["startCoordinateY"].toInt(),
        jsonObject["startCoordinateX"].toInt()
    );
    this->endCoordinate = pair<int, int>(
        jsonObject["endCoordinateY"].toInt(),
        jsonObject["endCoordinateX"].toInt()
    );
}
