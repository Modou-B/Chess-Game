//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessPieceTransfer.h"

std::string ChessPieceTransfer::getType() {
    return this->type;
}

int ChessPieceTransfer::getPlayer() {
    return this->player;
}

ChessPieceTransfer &ChessPieceTransfer::setType(std::string type) {
    this->type = type;

    return *this;
}

ChessPieceTransfer &ChessPieceTransfer::setPlayer(int player) {
    this->player = player;

    return *this;
}