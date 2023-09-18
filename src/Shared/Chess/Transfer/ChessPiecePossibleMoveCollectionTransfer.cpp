//
// Created by Julian Sommer on 10.09.23.
//

#include "ChessPiecePossibleMoveCollectionTransfer.h"

ChessPiecePossibleMoveCollectionTransfer::ChessPiecePossibleMoveCollectionTransfer() {
    this->hasOpponentPieceAsPossibleMove = false;
    this->isOwnChessPieceIsInFront = false;
}

std::vector<ChessPiecePossibleMoveTransfer*> *ChessPiecePossibleMoveCollectionTransfer::getPossibleMoveVector() {
    return this->possibleMoves;
}

void ChessPiecePossibleMoveCollectionTransfer::setPossibleMoveVector(std::vector<ChessPiecePossibleMoveTransfer*> *possibleMoves) {
    this->possibleMoves = possibleMoves;
}

bool ChessPiecePossibleMoveCollectionTransfer::getHasOpponentPieceAsPossibleMove() {
    return this->hasOpponentPieceAsPossibleMove;
}

void ChessPiecePossibleMoveCollectionTransfer::setHasOpponentPieceAsPossibleMove(bool value) {
    this->hasOpponentPieceAsPossibleMove = value;
}

bool ChessPiecePossibleMoveCollectionTransfer::getIsOwnChessPieceIsInFront() {
    return this->isOwnChessPieceIsInFront;
}

void ChessPiecePossibleMoveCollectionTransfer::setIsOwnChessPieceIsInFront(bool value) {
    this->isOwnChessPieceIsInFront = value;
}
