//
// Created by Julian Sommer on 01.10.23.
//

#include "ChessPiecePositionTransfer.h"
#include <QJsonObject>

ChessPiecePositionTransfer *ChessPiecePositionTransfer::setCurrentChessPieceCoordinates(pair<int, int> currentCoordinates) {
    this->currentCoordinates = currentCoordinates;

    return this;
}

pair<int, int> ChessPiecePositionTransfer::getCurrentChessPieceCoordinates() {
    return this->currentCoordinates;
}

QJsonObject ChessPiecePositionTransfer::toQJsonObject()
{
    QJsonObject jsonData;

    jsonData["currentXCoordinate"] = this->currentCoordinates.first;
    jsonData["currentYCoordinate"] = this->currentCoordinates.second;

    return jsonData;
}

void ChessPiecePositionTransfer::fromQJsonObject(QJsonObject jsonObject)
{
    this->currentCoordinates = pair<int, int>(
      jsonObject["currentXCoordinate"].toInt(),
      jsonObject["currentYCoordinate"].toInt()
    );
}