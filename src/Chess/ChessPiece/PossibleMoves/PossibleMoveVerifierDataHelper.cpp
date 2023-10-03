//
// Created by Julian Sommer on 02.10.23.
//

#include "PossibleMoveVerifierDataHelper.h"

PossibleMoveVerifierDataHelper::PossibleMoveVerifierDataHelper() {
    this->hasOpponentPieceAsPossibleMove = false;
    this->isOwnChessPieceIsInFront = false;
}

vector<ChessPiecePossibleMoveTransfer*> *PossibleMoveVerifierDataHelper::getPossibleMoveVector() {
    return this->possibleMoves;
}

void PossibleMoveVerifierDataHelper::setPossibleMoveVector(vector<ChessPiecePossibleMoveTransfer*> *possibleMoves) {
    this->possibleMoves = possibleMoves;
}

bool PossibleMoveVerifierDataHelper::getHasOpponentPieceAsPossibleMove() {
    return this->hasOpponentPieceAsPossibleMove;
}

void PossibleMoveVerifierDataHelper::setHasOpponentPieceAsPossibleMove(bool value) {
    this->hasOpponentPieceAsPossibleMove = value;
}

bool PossibleMoveVerifierDataHelper::getIsOwnChessPieceIsInFront() {
    return this->isOwnChessPieceIsInFront;
}

void PossibleMoveVerifierDataHelper::setIsOwnChessPieceIsInFront(bool value) {
    this->isOwnChessPieceIsInFront = value;
}

void PossibleMoveVerifierDataHelper::resetVerifierProperties() {
    this->hasOpponentPieceAsPossibleMove = false;
    this->isOwnChessPieceIsInFront = false;
}
