//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessCellTransfer.h"

ChessCellTransfer::ChessCellTransfer() {
    this->chessField = nullptr;
    this->chessPiece = nullptr;
}

ChessField *ChessCellTransfer::getChessField() {
    return this->chessField;
}

BaseChessPiece *ChessCellTransfer::getChessPiece() {
    return this->chessPiece;
}

int ChessCellTransfer::getXPosition() {
    return this->xPosition;
}

int ChessCellTransfer::getYPosition() {
    return this->yPosition;
}

ChessCellTransfer &ChessCellTransfer::setChessField(ChessField *chessField) {
    this->chessField = chessField;

    return *this;
}

ChessCellTransfer &ChessCellTransfer::setChessPiece(BaseChessPiece *chessPiece) {
    this->chessPiece = chessPiece;

    return *this;
}

ChessCellTransfer &ChessCellTransfer::setXPosition(int xPosition) {
    this->xPosition = xPosition;

    return *this;
}

ChessCellTransfer &ChessCellTransfer::setYPosition(int yPosition) {
    this->yPosition = yPosition;

    return *this;
}



