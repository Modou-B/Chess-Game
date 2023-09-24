//
// Created by Julian Sommer on 22.09.23.
//

#ifndef CHESSAPPLICATION_INCHECKRESPONSETRANSFER_H
#define CHESSAPPLICATION_INCHECKRESPONSETRANSFER_H

#include <string>
#include <vector>
#include <utility>

class InCheckBlockedCoordinatesTransfer;

class InCheckResponseTransfer {
private:
    int amountOfPiecesThatCheckCell = 0;

    std::string latestPieceTypeThatCheckKing;
    std::vector<InCheckBlockedCoordinatesTransfer*> latestCoordinatesFromCellToOpponentPiece;
public:
    InCheckResponseTransfer &setAmountOfPiecesThatCheckCell(int amountOfPiecesThatCheckCell);
    InCheckResponseTransfer &setLatestPieceTypeThatCheckKing(std::string latestPieceTypeThatCheckKing);
    InCheckResponseTransfer &setLatestCoordinatesFromCellToOpponentPiece(std::vector<InCheckBlockedCoordinatesTransfer*> latestCoordinatesFromCellToOpponentPiece);

    int getAmountOfPiecesThatCheckCell();
    std::string getLatestPieceTypeThatCheckKing();
    std::vector<InCheckBlockedCoordinatesTransfer*> getLatestCoordinatesFromCellToOpponentPiece();
};

#endif // CHESSAPPLICATION_INCHECKRESPONSETRANSFER_H
