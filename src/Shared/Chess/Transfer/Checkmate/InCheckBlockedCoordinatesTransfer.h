//
// Created by Julian Sommer on 23.09.23.
//

#ifndef CHESSAPPLICATION_INCHECKBLOCKEDCOORDINATESTRANSFER_H
#define CHESSAPPLICATION_INCHECKBLOCKEDCOORDINATESTRANSFER_H

#include <utility>

class InCheckBlockedCoordinatesTransfer {
private:
    std::pair<int, int> blockedCoordinateFromCellToOpponentPiece;
    bool hasCoordinateOpponentPiece;
    bool isRealTransfer;

public:
    InCheckBlockedCoordinatesTransfer();

    InCheckBlockedCoordinatesTransfer &setBlockedCoordinateFromCellToOpponentPiece(
        std::pair<int, int> blockedCoordinateFromCellToOpponentPiece
    );
    InCheckBlockedCoordinatesTransfer &setHasCoordinateOpponentPiece(bool hasCoordinateOpponentPiece);
    InCheckBlockedCoordinatesTransfer &setIsRealTransfer(bool isRealTransfer);

    std::pair<int, int> getBlockedCoordinateFromCellToOpponentPiece();
    bool getHasCoordinateOpponentPiece();
    bool getIsRealTransfer();
};

#endif // CHESSAPPLICATION_INCHECKBLOCKEDCOORDINATESTRANSFER_H
