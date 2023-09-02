//
// Created by Julian Sommer on 26.08.23.
//

#include "BaseChessPiece.h"

void BaseChessPiece::determinePossibleMoves() {
    return;
}

BaseChessPiece::BaseChessPiece(std::string type, int player) {
    this->type = type;
    this->player = player;
}

std::string BaseChessPiece::getType() {
    return this->type;
}
