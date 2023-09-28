//
// Created by Modou on 28.09.23.
//

#include "ChessSelectionPiece.h"
#include "ChessGridLayout.h"

ChessSelectionPiece::ChessSelectionPiece(ChessGridLayout *gridLayout, std::string pieceType) {
    this->gridLayout = gridLayout;
    this->pieceType = pieceType;

    connect(this, &QPushButton::released, this, &ChessSelectionPiece::setSelectionPiece);
}

void ChessSelectionPiece::setSelectionPiece() {
    this->gridLayout->setChessPieceSwitchType(this->pieceType);
    this->gridLayout->setChessPieceTypeSetCondition(true);
}