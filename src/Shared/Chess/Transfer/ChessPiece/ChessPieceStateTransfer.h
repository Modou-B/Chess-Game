//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECESTATETRANSFER_H
#define CHESSAPPLICATION_CHESSPIECESTATETRANSFER_H

#include <utility>
#include <string>

using namespace std;

class QJsonObject;

class ChessPieceStateTransfer {
private:
    int playerOfChessPiece;
    string chessPieceType;
    string state;
    int moveCounter;
    bool usedDoubleMove;
    pair<int, int> startCoordinate;
    pair<int, int> endCoordinate;

public:   
    ChessPieceStateTransfer *setPlayerOfChessPiece(int player);
    ChessPieceStateTransfer *setChessPieceType(string chessPieceType);
    ChessPieceStateTransfer *setState(string chessPieceState);
    ChessPieceStateTransfer *setMoveCounter(int moveCounter);
    ChessPieceStateTransfer *setUsedDoubleMove(bool usedDoubleMove);
    ChessPieceStateTransfer *setStartCoordinate(pair<int, int> startCoordinate);
    ChessPieceStateTransfer *setEndCoordinate(pair<int, int> endCoordinate);

    int getPlayerOfChessPiece();
    string getChessPieceType();
    string getState();
    int getMoveCounter();
    bool getUsedDoubleMove();
    pair<int, int> getStartCoordinate();
    pair<int, int> getEndCoordinate();

    QJsonObject toQJsonObject();
    void fromQJsonObject(QJsonObject jsonObject);
};

#endif // CHESSAPPLICATION_CHESSPIECESTATETRANSFER_H
