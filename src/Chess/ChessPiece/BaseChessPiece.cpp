//
// Created by Julian Sommer on 26.08.23.
//

#include "BaseChessPiece.h"

void BaseChessPiece::determinePossibleMoves() {
    return;
}

BaseChessPiece::BaseChessPiece(std::string type) {
    this->type = type;
}

std::string BaseChessPiece::getType() {
    return this->type;
}
