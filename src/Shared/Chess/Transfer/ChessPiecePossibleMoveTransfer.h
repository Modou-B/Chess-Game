//
// Created by Julian Sommer on 17.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H


#include <string>

using namespace std;

class QJsonObject;

class ChessPiecePossibleMoveTransfer {
private:
    string moveType;

    int xCoordinate;
    int yCoordinate;

public:
    ChessPiecePossibleMoveTransfer &setMoveType(string moveType);
    ChessPiecePossibleMoveTransfer &setXCoordinate(int xCoordinate);
    ChessPiecePossibleMoveTransfer &setYCoordinate(int yCoordinate);

    string getMoveType();
    int getXCoordinate();
    int getYCoordinate();

    QJsonObject toQJsonObject();
    void fromQJsonObject(QJsonObject jsonObject);
};


#endif //CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H
