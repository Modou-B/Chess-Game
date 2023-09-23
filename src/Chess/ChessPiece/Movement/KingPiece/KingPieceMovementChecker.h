//
// Created by Julian Sommer on 21.09.23.
//

#ifndef CHESSAPPLICATION_KINGPIECEMOVEMENTCHECKER_H
#define CHESSAPPLICATION_KINGPIECEMOVEMENTCHECKER_H

#include <utility>
#include <vector>
#include <string>

class ChessField;
class InCheckBlockedCoordinatesTransfer;
class InCheckVerifierTransfer;
class InCheckResponseTransfer;

class KingPieceMovementChecker {
private:
    bool continueToVerifyCoordinates(ChessField *chessField, InCheckVerifierTransfer *inCheckVerifierTransfer, InCheckResponseTransfer *inCheckResponseTransfer);

    InCheckVerifierTransfer createInCheckVerifierTransfer(int xCoordinate, int yCoordinate, int currentPlayer, std::string pieceTypeToCheck);
    InCheckBlockedCoordinatesTransfer *createInCheckBlockedCoordinatesTransfer(int xCoordinate, int yCoordinate);

    void resetVerifyData(int *xCoordinateToReset, int *yCoordinateToReset, InCheckVerifierTransfer *inCheckVerifierTransfer, int xValue, int yValue);
    void mapToInCheckResponseTransfer(std::string pieceType, std::vector<InCheckBlockedCoordinatesTransfer*> checkedCoordinates, InCheckResponseTransfer *inCheckResponseTransfer);
    bool isPawnViable(std::string diagonalDirection, int pawnPiecePlayer);

protected:
    void checkForKnightsHorizontally(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer, InCheckResponseTransfer *inCheckResponseTransfer);

    void checkForKnightsVertically(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer, InCheckResponseTransfer *inCheckResponseTransfer);

public:
    InCheckResponseTransfer getVerticalCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);

    InCheckResponseTransfer getHorizontalCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);

    InCheckResponseTransfer getDiagonalCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);

    InCheckResponseTransfer getKnightCheckAmountForGivenChessCell(
        ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer);
};

#endif // CHESSAPPLICATION_KINGPIECEMOVEMENTCHECKER_H
