//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessPieceInformationTransfer.h"

ChessPieceInformationTransfer *ChessPieceInformationTransfer::setChessPieceColor(std::string chessPieceColor) {
    this->chessPieceColor = chessPieceColor;

    return this;
}

ChessPieceInformationTransfer *ChessPieceInformationTransfer::setChessPieceStateTransfer(ChessPieceStateTransfer *chessPieceStateTransfer) {
    this->chessPieceStateTransfer = chessPieceStateTransfer;

    return this;
}

std::string ChessPieceInformationTransfer::getChessPieceColor() {
    return this->chessPieceColor;
}

ChessPieceStateTransfer *ChessPieceInformationTransfer::getChessPieceStateTransfer() {
    return this->chessPieceStateTransfer;
}