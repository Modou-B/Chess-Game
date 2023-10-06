//
// Created by Julian Sommer on 03.10.23.
//

#include "EndTurnInformationTransfer.h"

EndTurnInformationTransfer *EndTurnInformationTransfer::setChessGameStateTransfer(
    ChessGameStateTransfer *chessGameStateTransfer
) {
    this->chessGameStateTransfer = chessGameStateTransfer;

    return this;
}

EndTurnInformationTransfer *EndTurnInformationTransfer::setChessPieceStateTransfers(
    vector<ChessPieceStateTransfer *> chessPieceStateTransfers
) {
    this->chessPieceStateTransfers = chessPieceStateTransfers;

    return this;
}

ChessGameStateTransfer *EndTurnInformationTransfer::getChessGameStateTransfer() {
    return this->chessGameStateTransfer;
}

vector<ChessPieceStateTransfer *> EndTurnInformationTransfer::getChessPieceStateTransfers() {
    return this->chessPieceStateTransfers;
}