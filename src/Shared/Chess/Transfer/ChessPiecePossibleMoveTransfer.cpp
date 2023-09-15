//
// Created by Julian Sommer on 10.09.23.
//

#include "ChessPiecePossibleMoveTransfer.h"

ChessPiecePossibleMoveTransfer::ChessPiecePossibleMoveTransfer() {
    this->hasOpponentPieceAsPossibleMove = false;
    this->isOwnChessPieceIsInFront = false;
}

std::vector<std::pair<int, int>> *ChessPiecePossibleMoveTransfer::getPossibleMoveVector() {
    return this->possibleMoves;
}

void ChessPiecePossibleMoveTransfer::setPossibleMoveVector(std::vector<std::pair<int, int>> *possibleMoves) {
    this->possibleMoves = possibleMoves;
}

bool ChessPiecePossibleMoveTransfer::getHasOpponentPieceAsPossibleMove() {
    return this->hasOpponentPieceAsPossibleMove;
}

void ChessPiecePossibleMoveTransfer::setHasOpponentPieceAsPossibleMove(bool value) {
    this->hasOpponentPieceAsPossibleMove = value;
}

bool ChessPiecePossibleMoveTransfer::getIsOwnChessPieceIsInFront() {
    return this->isOwnChessPieceIsInFront;
}

void ChessPiecePossibleMoveTransfer::setIsOwnChessPieceIsInFront(bool value) {
    this->isOwnChessPieceIsInFront = value;
}
