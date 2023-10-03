//
// Created by Julian Sommer on 25.09.23.
//

#include "ChessTurnLogTransfer.h"
#include "../Chess/Transfer/ChessPiece/ChessPieceInformationTransfer.h"

ChessTurnLogTransfer::ChessTurnLogTransfer() {
    this->chessPieceInformationTransfers = {};
}

ChessTurnLogTransfer *ChessTurnLogTransfer::setCurrentPlayer(int currentPlayer) {
    this->currentPlayer = currentPlayer;

    return this;
}

ChessTurnLogTransfer *ChessTurnLogTransfer::setTurnCounter(int turnCounter) {
    this->turnCounter = turnCounter;

    return this;
}

ChessTurnLogTransfer *ChessTurnLogTransfer::setChessPieceInformationTransfers(
    vector<ChessPieceInformationTransfer *> chessPieceInformationTransfers
) {
    this->chessPieceInformationTransfers = chessPieceInformationTransfers;

    return this;
}

void ChessTurnLogTransfer::addChessPieceInformationTransfer(ChessPieceInformationTransfer *chessPieceInformationTransfer) {
    this->chessPieceInformationTransfers.push_back(chessPieceInformationTransfer);
}

int ChessTurnLogTransfer::getCurrentPlayer() {
    return this->currentPlayer;
}

int ChessTurnLogTransfer::getTurnCounter() {
    return this->turnCounter;
}

std::vector<ChessPieceInformationTransfer*> ChessTurnLogTransfer::getChessPieceInformationTransfers() {
    return this->chessPieceInformationTransfers;
}
