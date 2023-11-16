//
// Created by Julian Sommer on 17.09.23.
//

#include "ChessPiecePossibleMoveTransfer.h"
#include <QJsonObject>

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

QJsonObject ChessPiecePossibleMoveTransfer::toQJsonObject() {
    QJsonObject jsonObject;

    jsonObject["moveType"] = QString::fromStdString(this->moveType);
    jsonObject["xCoordinate"] = this->xCoordinate;
    jsonObject["yCoordinate"] = this->yCoordinate;

    return jsonObject;
}

void ChessPiecePossibleMoveTransfer::fromQJsonObject(QJsonObject jsonObject) {
    this->moveType = jsonObject["moveType"].toString().toStdString();
    this->xCoordinate = jsonObject["xCoordinate"].toInt();
    this->yCoordinate = jsonObject["yCoordinate"].toInt();
}
