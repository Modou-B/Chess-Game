//
// Created by Julian Sommer on 02.10.23.
//

#include "ChessPieceMovementWriter.h"
#include "../PossibleMoves/PossibleMoveDataHolder.h"
#include "../../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"

void ChessPieceMovementWriter::updatePreviousPossibleMoveData(
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    PossibleMoveDataHolder::setPreviousPossibleMovesForClickedCell(possibleMoves);
}

void ChessPieceMovementWriter::updatePreviousPossibleMoveDataWithCurrentPossibleMoves() {
    PossibleMoveDataHolder::setPreviousPossibleMovesForClickedCell(
        PossibleMoveDataHolder::getPossibleMovesForClickedCell()
    );
}

void ChessPieceMovementWriter::updatePossibleMoveData(
    vector<ChessPiecePossibleMoveTransfer *> possibleMoves
) {
    this->updatePreviousPossibleMoveDataWithCurrentPossibleMoves();
    PossibleMoveDataHolder::setPossibleMovesForClickedCell(possibleMoves);
}

void ChessPieceMovementWriter::clearPossibleMoveCollections() {
    PossibleMoveDataHolder::deletePreviousPossibleMoves();
    PossibleMoveDataHolder::deletePossibleMoves();
}

