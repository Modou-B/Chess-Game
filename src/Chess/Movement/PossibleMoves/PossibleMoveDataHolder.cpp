//
// Created by Julian Sommer on 02.10.23.
//

#include "PossibleMoveDataHolder.h"

vector<ChessPiecePossibleMoveTransfer *> PossibleMoveDataHolder::previousPossibleMovesForClickedCell;
vector<ChessPiecePossibleMoveTransfer *> PossibleMoveDataHolder::possibleMovesForClickedCell;

void PossibleMoveDataHolder::setPreviousPossibleMovesForClickedCell(vector<ChessPiecePossibleMoveTransfer *> possibleMoves) {
    PossibleMoveDataHolder::previousPossibleMovesForClickedCell = possibleMoves;
}

void PossibleMoveDataHolder::setPossibleMovesForClickedCell(vector<ChessPiecePossibleMoveTransfer *> possibleMoves) {
    PossibleMoveDataHolder::possibleMovesForClickedCell = possibleMoves;
}

vector<ChessPiecePossibleMoveTransfer *> PossibleMoveDataHolder::getPreviousPossibleMovesForClickedCell() {
    return PossibleMoveDataHolder::previousPossibleMovesForClickedCell;
}

vector<ChessPiecePossibleMoveTransfer *> PossibleMoveDataHolder::getPossibleMovesForClickedCell() {
    return PossibleMoveDataHolder::possibleMovesForClickedCell;
}

void PossibleMoveDataHolder::deletePreviousPossibleMoves() {
    PossibleMoveDataHolder::previousPossibleMovesForClickedCell.clear();
}

void PossibleMoveDataHolder::deletePossibleMoves() {
    PossibleMoveDataHolder::possibleMovesForClickedCell.clear();
}