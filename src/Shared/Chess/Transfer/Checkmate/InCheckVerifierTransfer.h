//
// Created by Julian Sommer on 22.09.23.
//

#ifndef CHESSAPPLICATION_INCHECKVERIFIERTRANSFER_H
#define CHESSAPPLICATION_INCHECKVERIFIERTRANSFER_H

#include <string>
#include <vector>
#include <utility>

class InCheckBlockedCoordinatesTransfer;

class InCheckVerifierTransfer {
private:
    int xCoordinateToVerify;
    int yCoordinateToVerify;
    int currentPlayer;
    int moveCounter;
    std::string pieceTypeToCheck;

    std::vector<InCheckBlockedCoordinatesTransfer*> lastCheckedCoordinates;
public:
    InCheckVerifierTransfer &setXCoordinateToVerify(int xCoordinateToVerify);
    InCheckVerifierTransfer &setYCoordinateToVerify(int yCoordinateToVerify);
    InCheckVerifierTransfer &setCurrentPlayer(int currentPlayer);
    InCheckVerifierTransfer &setMoveCounter(int currentMove);
    InCheckVerifierTransfer &setPieceTypeToCheck(std::string pieceTypeToCheck);

    void addLastInCheckBlockedCoordinatesTransfer(InCheckBlockedCoordinatesTransfer* inCheckBlockedCoordinatesTransfer);

    int getXCoordinateToVerify();
    int getYCoordinateToVerify();
    int getCurrentPlayer();
    int getMoveCounter();
    std::string getPieceTypeToCheck();
    std::vector<InCheckBlockedCoordinatesTransfer*> getLastInCheckBlockedCoordinatesTransfer();

    void clearLastCheckedCoordinates();
};

#endif // CHESSAPPLICATION_INCHECKVERIFIERTRANSFER_H
