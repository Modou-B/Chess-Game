//
// Created by Julian Sommer on 25.09.23.
//

#include "ChessTurnLogTransfer.h"
#include "../Chess/Transfer/ChessPiece/ChessPieceInformationTransfer.h"

ChessTurnLogTransfer::ChessTurnLogTransfer() {
    this->chessPieceInformationTransfers = {};
}

ChessTurnLogTransfer *ChessTurnLogTransfer::setChessGameStateTransfer(
    ChessGameStateTransfer *chessGameStateTransfer
) {
    this->chessGameStateTransfer = chessGameStateTransfer;

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

ChessGameStateTransfer *ChessTurnLogTransfer::getChessGameStateTransfer() {
    return this->chessGameStateTransfer;
}

std::vector<ChessPieceInformationTransfer*> ChessTurnLogTransfer::getChessPieceInformationTransfers() {
    return this->chessPieceInformationTransfers;
}
