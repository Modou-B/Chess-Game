//
// Created by Julian Sommer on 07.09.23.
//

#include "ChessMovementResponseTransfer.h"
#include "ChessPieceMovementTransfer.h"
#include "ChessPiece/ChessPieceStateTransfer.h"
#include "ChessPiecePossibleMoveTransfer.h"
#include <QJsonObject>
#include <QJsonArray>
#include "iostream"

ChessMovementResponseTransfer::ChessMovementResponseTransfer() {
    this->state = "";
    this->chessPieceStateTransfers = vector<ChessPieceStateTransfer*>();
}

ChessMovementResponseTransfer *ChessMovementResponseTransfer::setState(string state) {
    this->state = state;

    return this;
}

ChessMovementResponseTransfer *ChessMovementResponseTransfer::setCurrentPlayer(int player) {
    this->currentPlayer = player;

    return this;
}

ChessMovementResponseTransfer *ChessMovementResponseTransfer::setCurrentOpponentPlayer(int player) {
    this->currentOpponentPlayer = player;

    return this;
}

ChessMovementResponseTransfer *ChessMovementResponseTransfer::setPreviousPossibleMoveTransfers(
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    this->previousPossibleMoveTransfers = possibleMoves;

    return this;
}

ChessMovementResponseTransfer *ChessMovementResponseTransfer::setPossibleMoveTransfers(
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    this->possibleMoveTransfers = possibleMoves;

    return this;
}

ChessMovementResponseTransfer *ChessMovementResponseTransfer::setChessPieceStateTransfers(
    vector<ChessPieceStateTransfer *> chessPieceStateTransfers
) {
    this->chessPieceStateTransfers = chessPieceStateTransfers;

    return this;
}

void ChessMovementResponseTransfer::addChessPieceStateTransfer(ChessPieceStateTransfer *chessPieceStateTransfer) {
    this->chessPieceStateTransfers.push_back(chessPieceStateTransfer);
}

void ChessMovementResponseTransfer::addPossibleMoveTransfer(
    ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer
) {
    this->possibleMoveTransfers.push_back(chessPiecePossibleMoveTransfer);
}

void ChessMovementResponseTransfer::addPreviousPossibleMoveTransfer(
    ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer
) {
    this->previousPossibleMoveTransfers.push_back(chessPiecePossibleMoveTransfer);
}

string ChessMovementResponseTransfer::getState() {
    return this->state;
}

int ChessMovementResponseTransfer::getCurrentPlayer() {
    return this->currentPlayer;
}

int ChessMovementResponseTransfer::getCurrentOpponentPlayer() {
    return this->currentOpponentPlayer;
}

vector<ChessPiecePossibleMoveTransfer *> ChessMovementResponseTransfer::getPreviousPossibleMoveTransfers() {
    return this->previousPossibleMoveTransfers;
}

vector<ChessPiecePossibleMoveTransfer *> ChessMovementResponseTransfer::getPossibleMoveTransfers() {
    return this->possibleMoveTransfers;
}

vector<ChessPieceStateTransfer*> ChessMovementResponseTransfer::getChessPieceStateTransfers() {
    return this->chessPieceStateTransfers;
}

QJsonObject ChessMovementResponseTransfer::toQJsonObject() {
    QJsonObject jsonObject;

    jsonObject["state"] = QString::fromStdString(this->state);
    jsonObject["currentPlayer"] = this->currentPlayer;
    jsonObject["opponentPlayer"] = this->currentOpponentPlayer;

    QJsonArray possibleMoveData;
    for (auto possibleMoveTransfer : this->possibleMoveTransfers) {
        possibleMoveData.append(possibleMoveTransfer->toQJsonObject());
    }
    jsonObject["possibleMoves"] = possibleMoveData;

    QJsonArray previousPossibleMoveData;
    for (auto previousPossibleMoveTransfer : this->previousPossibleMoveTransfers) {
        previousPossibleMoveData.append(previousPossibleMoveTransfer->toQJsonObject());
    }
    jsonObject["previousPossibleMoves"] = previousPossibleMoveData;

    QJsonArray chessPieceStateData;
    for (auto chessPieceStateTransfer : this->chessPieceStateTransfers) {
        chessPieceStateData.append(chessPieceStateTransfer->toQJsonObject());
    }
    jsonObject["chessPieceStates"] = chessPieceStateData;

    return jsonObject;
}

void ChessMovementResponseTransfer::fromQJsonObject(QJsonObject jsonObject)
{
    this->state = jsonObject["state"].toString().toStdString();
    this->currentPlayer = jsonObject["currentPlayer"].toInt();
    this->currentOpponentPlayer = jsonObject["opponentPlayer"].toInt();

    for (auto possibleMoveData : jsonObject["possibleMoves"].toArray()) {
        auto chessPiecePossibleMoveTransfer = new ChessPiecePossibleMoveTransfer;

        chessPiecePossibleMoveTransfer->fromQJsonObject(possibleMoveData.toObject());

        this->addPossibleMoveTransfer(chessPiecePossibleMoveTransfer);
    }

    for (auto previousPossibleMoveData : jsonObject["possibleMoves"].toArray()) {
        auto chessPiecePossibleMoveTransfer = new ChessPiecePossibleMoveTransfer;

        chessPiecePossibleMoveTransfer->fromQJsonObject(previousPossibleMoveData.toObject());

        this->addPreviousPossibleMoveTransfer(chessPiecePossibleMoveTransfer);
    }

    for (auto chessPieceStateData : jsonObject["chessPieceStates"].toArray()) {
        auto chessPieceStateTransfer = new ChessPieceStateTransfer;

        chessPieceStateTransfer->fromQJsonObject(chessPieceStateData.toObject());

        this->addChessPieceStateTransfer(chessPieceStateTransfer);
    }
}