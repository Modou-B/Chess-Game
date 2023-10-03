//
// Created by Julian Sommer on 02.10.23.
//

#include "PossibleMoveCollectionTransfer.h"

PossibleMoveCollectionTransfer *PossibleMoveCollectionTransfer::setPreviousPossibleMoveTransfers(
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    this->previousPossibleMoveTransfers = possibleMoves;

    return this;
}

PossibleMoveCollectionTransfer *PossibleMoveCollectionTransfer::setPossibleMoveTransfers(
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    this->possibleMoveTransfers = possibleMoves;

    return this;
}

void PossibleMoveCollectionTransfer::addPreviousPossibleMoveTransfer(
    ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer
) {
    this->previousPossibleMoveTransfers.push_back(chessPiecePossibleMoveTransfer);
}

void PossibleMoveCollectionTransfer::addPossibleMoveTransfer(
    ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer
) {
    this->possibleMoveTransfers.push_back(chessPiecePossibleMoveTransfer);
}

vector<ChessPiecePossibleMoveTransfer *> PossibleMoveCollectionTransfer::getPreviousPossibleMoveTransfers() {
    return this->previousPossibleMoveTransfers;
}

vector<ChessPiecePossibleMoveTransfer *> PossibleMoveCollectionTransfer::getPossibleMoveTransfers() {
    return this->possibleMoveTransfers;
}