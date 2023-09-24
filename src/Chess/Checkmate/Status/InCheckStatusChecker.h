//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_INCHECKSTATUSCHECKER_H
#define CHESSAPPLICATION_INCHECKSTATUSCHECKER_H

#include <utility>
#include <vector>
#include <string>
#include <map>

class ChessField;
class BaseChessPiece;
class KingPieceMovementChecker;
class InCheckResponseTransfer;
class ChessPlayerData;
class InCheckBlockedCoordinatesTransfer;

class InCheckStatusChecker {
private:
    KingPieceMovementChecker *kingPieceMovementChecker;

    std::map<std::string, InCheckBlockedCoordinatesTransfer*> hashedCoords;

protected:
    void updateFullInCheckResponseTransfer(InCheckResponseTransfer inCheckResponseTransfer, InCheckResponseTransfer *fullInCheckResponseTransfer);

    int getCheckBlockAmountForSpecificPieces(ChessField *chessField, std::vector<BaseChessPiece*> specificPieces, std::pair<int, int> kingPieceCoordinates, int currentPlayer);

    bool verifyIfPieceTakeResultsInCheck(
        ChessField *chessField, InCheckBlockedCoordinatesTransfer* inCheckBlockedCoordinatesTransfer, std::pair<int, int> kingPieceCoordinates, std::pair<int, int> coordinatesOfCheckedPiece, int currentPlayer);

    void hashInCheckCords(InCheckResponseTransfer inCheckResponseTransfer);
    std::string getHash(std::pair<int, int> coords);

public:
    InCheckStatusChecker(KingPieceMovementChecker *kingPieceMovementChecker);

    InCheckResponseTransfer getAmountOfPiecesThatCheckKing(ChessField *chessField, std::pair<int, int> kingPieceCoordinates, int currentPlayer);

    int getAmountOfPiecesThatBlockCheck(ChessField *chessField, ChessPlayerData *chessPlayerData, InCheckResponseTransfer inCheckResponseTransfer, std::pair<int, int> kingPieceCoordinates, int currentPlayer);
};

#endif // CHESSAPPLICATION_INCHECKSTATUSCHECKER_H
