//
// Created by Julian Sommer on 07.09.23.
//

#include "ChessMovementResponseTransfer.h"
#include "ChessPieceMovementTransfer.h"
#include "ChessPiecePossibleMoveTransfer.h"

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