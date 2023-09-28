//
// Created by Modou on 28.09.23.
//

#include "ChessGridLayout.h"

ChessGridLayout::ChessGridLayout() {
    this->switchPiecePieceSetCondition = false;
}

void ChessGridLayout::setChessPieceSwitchType(std::string pieceType) {
    this->switchPieceType = pieceType;
}

void ChessGridLayout::setChessPieceTypeSetCondition(bool isSet) {
    this->switchPiecePieceSetCondition = isSet;
}

std::string ChessGridLayout::getChessPieceSwitchType() {
    return this->switchPieceType;
}

bool ChessGridLayout::isChessPieceSwitchTypeSet() {
    return this->switchPiecePieceSetCondition;
}