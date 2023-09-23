//
// Created by Julian Sommer on 23.09.23.
//

#include "InCheckBlockedCoordinatesTransfer.h"

InCheckBlockedCoordinatesTransfer::InCheckBlockedCoordinatesTransfer() {
    this->isRealTransfer = false;
}

InCheckBlockedCoordinatesTransfer &InCheckBlockedCoordinatesTransfer::setBlockedCoordinateFromCellToOpponentPiece(
    std::pair<int, int> blockedCoordinateFromCellToOpponentPiece) {
    this->blockedCoordinateFromCellToOpponentPiece = blockedCoordinateFromCellToOpponentPiece;

    return *this;
}

InCheckBlockedCoordinatesTransfer &InCheckBlockedCoordinatesTransfer::setHasCoordinateOpponentPiece(bool hasCoordinateOpponentPiece) {
    this->hasCoordinateOpponentPiece = hasCoordinateOpponentPiece;

    return *this;
}

InCheckBlockedCoordinatesTransfer &InCheckBlockedCoordinatesTransfer::setIsRealTransfer(bool isRealTransfer) {
    this->isRealTransfer = isRealTransfer;

    return *this;
}

std::pair<int, int> InCheckBlockedCoordinatesTransfer::getBlockedCoordinateFromCellToOpponentPiece() {
    return this->blockedCoordinateFromCellToOpponentPiece;
}

bool InCheckBlockedCoordinatesTransfer::getHasCoordinateOpponentPiece() {
    return this->hasCoordinateOpponentPiece;
}

bool InCheckBlockedCoordinatesTransfer::getIsRealTransfer() {
    return this->isRealTransfer;
}
