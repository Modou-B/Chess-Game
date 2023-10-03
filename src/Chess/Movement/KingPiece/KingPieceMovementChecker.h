//
// Created by Julian Sommer on 21.09.23.
//

#ifndef CHESSAPPLICATION_KINGPIECEMOVEMENTCHECKER_H
#define CHESSAPPLICATION_KINGPIECEMOVEMENTCHECKER_H

#include <utility>
#include <vector>
#include <string>

using namespace std;

class ChessField;
class InCheckBlockedCoordinatesTransfer;
class InCheckVerifierTransfer;
class InCheckResponseTransfer;
class GameApplicationDataReader;

class KingPieceMovementChecker {
private:
    GameApplicationDataReader *gameApplicationDataReader;

    bool continueToVerifyCoordinates(ChessField *chessField, InCheckVerifierTransfer *inCheckVerifierTransfer, InCheckResponseTransfer *inCheckResponseTransfer);

    InCheckVerifierTransfer createInCheckVerifierTransfer(int xCoordinate, int yCoordinate, int currentPlayer, string pieceTypeToCheck);
    InCheckBlockedCoordinatesTransfer *createInCheckBlockedCoordinatesTransfer(int xCoordinate, int yCoordinate);

    void resetVerifyData(int *xCoordinateToReset, int *yCoordinateToReset, InCheckVerifierTransfer *inCheckVerifierTransfer, int xValue, int yValue);
    void mapToInCheckResponseTransfer(string pieceType, vector<InCheckBlockedCoordinatesTransfer*> checkedCoordinates, InCheckResponseTransfer *inCheckResponseTransfer);
    bool isPawnViable(string diagonalDirection, int pawnPiecePlayer);

protected:
    void checkForKnightsHorizontally(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer, InCheckResponseTransfer *inCheckResponseTransfer);

    void checkForKnightsVertically(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer, InCheckResponseTransfer *inCheckResponseTransfer);

public:
    KingPieceMovementChecker(GameApplicationDataReader *gameApplicationDataReader);

    InCheckResponseTransfer getVerticalCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);

    InCheckResponseTransfer getHorizontalCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);

    InCheckResponseTransfer getDiagonalCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);

    InCheckResponseTransfer getKnightCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);
    
    pair<int, int> getKingPieceCoordinatesForPlayer(int player);
};

#endif // CHESSAPPLICATION_KINGPIECEMOVEMENTCHECKER_H
