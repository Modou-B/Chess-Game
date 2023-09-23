//
// Created by Julian Sommer on 22.09.23.
//

#include "InCheckResponseTransfer.h"

InCheckResponseTransfer &InCheckResponseTransfer::setAmountOfPiecesThatCheckCell(int amountOfPiecesThatCheckCell) {
    this->amountOfPiecesThatCheckCell = amountOfPiecesThatCheckCell;

    return *this;
}

InCheckResponseTransfer &InCheckResponseTransfer::setLatestPieceTypeThatCheckKing(std::string latestPieceTypeThatCheckKing) {
    this->latestPieceTypeThatCheckKing = latestPieceTypeThatCheckKing;

    return *this;
}

InCheckResponseTransfer &InCheckResponseTransfer::setLatestCoordinatesFromCellToOpponentPiece(std::vector<InCheckBlockedCoordinatesTransfer*> latestCoordinatesFromCellToOpponentPiece) {
    this->latestCoordinatesFromCellToOpponentPiece = latestCoordinatesFromCellToOpponentPiece;

    return *this;
}

int InCheckResponseTransfer::getAmountOfPiecesThatCheckCell() {
    return this->amountOfPiecesThatCheckCell;
}

std::string InCheckResponseTransfer::getLatestPieceTypeThatCheckKing() {
    return this->latestPieceTypeThatCheckKing;
}

std::vector<InCheckBlockedCoordinatesTransfer*> InCheckResponseTransfer::getLatestCoordinatesFromCellToOpponentPiece() {
    return this->latestCoordinatesFromCellToOpponentPiece;
}