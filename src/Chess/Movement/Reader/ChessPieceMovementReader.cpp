//
// Created by Julian Sommer on 02.10.23.
//

#include "ChessPieceMovementReader.h"
#include "../PossibleMoves/PossibleMoveDataHolder.h"
#include "../../../Shared/Chess/Transfer/Movement/PossibleMoveCollectionTransfer.h"

PossibleMoveCollectionTransfer ChessPieceMovementReader::getPossibleMovesForAllTypes() {
    auto possibleMoveCollectionTransfer = PossibleMoveCollectionTransfer();

    this->addPreviousPossibleMoves(
        possibleMoveCollectionTransfer,
        PossibleMoveDataHolder::getPreviousPossibleMovesForClickedCell()
    );

    this->addPossibleMoves(
        possibleMoveCollectionTransfer,
        PossibleMoveDataHolder::getPossibleMovesForClickedCell()
    );

    return possibleMoveCollectionTransfer;
}

PossibleMoveCollectionTransfer ChessPieceMovementReader::getPreviousPossibleMoves() {
    auto possibleMoveCollectionTransfer = PossibleMoveCollectionTransfer();

    this->addPreviousPossibleMoves(
        possibleMoveCollectionTransfer,
        PossibleMoveDataHolder::getPreviousPossibleMovesForClickedCell()
    );

    return possibleMoveCollectionTransfer;
}

PossibleMoveCollectionTransfer ChessPieceMovementReader::getPossibleMoves() {
    auto possibleMoveCollectionTransfer = PossibleMoveCollectionTransfer();

    this->addPossibleMoves(
        possibleMoveCollectionTransfer,
        PossibleMoveDataHolder::getPossibleMovesForClickedCell()
    );

    return possibleMoveCollectionTransfer;
}

void ChessPieceMovementReader::addPreviousPossibleMoves(
    PossibleMoveCollectionTransfer &possibleMoveCollectionTransfer,
    vector<ChessPiecePossibleMoveTransfer *> previousPossibleMoves
) {
    possibleMoveCollectionTransfer.setPreviousPossibleMoveTransfers(previousPossibleMoves);
}

void ChessPieceMovementReader::addPossibleMoves(
    PossibleMoveCollectionTransfer &possibleMoveCollectionTransfer,
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    possibleMoveCollectionTransfer.setPossibleMoveTransfers(possibleMoves);
}