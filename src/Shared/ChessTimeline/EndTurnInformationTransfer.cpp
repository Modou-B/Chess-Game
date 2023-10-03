//
// Created by Julian Sommer on 03.10.23.
//

#include "EndTurnInformationTransfer.h"

EndTurnInformationTransfer *EndTurnInformationTransfer::setCurrentPlayer(int currentPlayer) {
    this->currentPlayer = currentPlayer;

    return this;
}

EndTurnInformationTransfer *EndTurnInformationTransfer::setTurnCounter(int turnCounter) {
    this->turnCounter = turnCounter;

    return this;
}

EndTurnInformationTransfer *EndTurnInformationTransfer::setChessPieceStateTransfers(
    vector<ChessPieceStateTransfer *> chessPieceStateTransfers
) {
    this->chessPieceStateTransfers = chessPieceStateTransfers;

    return this;
}

int EndTurnInformationTransfer::getCurrentPlayer() {
    return this->currentPlayer;
}

int EndTurnInformationTransfer::getTurnCounter() {
    return this->turnCounter;
}

vector<ChessPieceStateTransfer *> EndTurnInformationTransfer::getChessPieceStateTransfers() {
    return this->chessPieceStateTransfers;
}