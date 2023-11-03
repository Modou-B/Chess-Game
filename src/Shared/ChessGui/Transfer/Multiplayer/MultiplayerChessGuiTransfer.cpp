//
// Created by Julian Sommer on 02.11.23.
//

#include "MultiplayerChessGuiTransfer.h"
#include <QJsonObject>

MultiplayerChessGuiTransfer *MultiplayerChessGuiTransfer::setUsername(string username) {
    this->username = username;

    return this;
}

MultiplayerChessGuiTransfer *MultiplayerChessGuiTransfer::setOpponentUsername(string opponentUsername) {
    this->opponentUsername = opponentUsername;

    return this;
}

MultiplayerChessGuiTransfer *MultiplayerChessGuiTransfer::setCurrentPlayer(int player) {
    this->currentPlayer = player;

    return this;
}

MultiplayerChessGuiTransfer *MultiplayerChessGuiTransfer::setOpponentPlayer(int player) {
    this->opponentPlayer = player;

    return this;
}

MultiplayerChessGuiTransfer *MultiplayerChessGuiTransfer::fromJsonObject(QJsonObject jsonData)
{
    this->currentPlayer = jsonData[QLatin1String("player")].toInt();
    this->opponentPlayer = jsonData[QLatin1String("opponentPlayer")].toInt();

    this->username = jsonData[QLatin1String("playerName")].toString().toStdString();
    this->opponentUsername = jsonData[QLatin1String("opponentPlayerName")].toString().toStdString();

    return this;
}

string MultiplayerChessGuiTransfer::getUsername() {
    return this->username;
}

string MultiplayerChessGuiTransfer::getOpponentUsername() {
    return this->opponentUsername;
}

int MultiplayerChessGuiTransfer::getCurrentPlayer() {
    return this->currentPlayer;
}

int MultiplayerChessGuiTransfer::getOpponentPlayer() {
    return this->opponentPlayer;
}

