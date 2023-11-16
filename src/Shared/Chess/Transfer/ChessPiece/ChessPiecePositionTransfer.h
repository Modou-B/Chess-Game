//
// Created by Julian Sommer on 01.10.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEPOSITIONTRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEPOSITIONTRANSFER_H

#include <utility>

using namespace std;

class QJsonObject;

class ChessPiecePositionTransfer {
private:
    pair<int, int> currentCoordinates;

public:
    ChessPiecePositionTransfer *setCurrentChessPieceCoordinates(pair<int, int> currentCoordinates);

    pair<int, int> getCurrentChessPieceCoordinates();

    QJsonObject toQJsonObject();
    void fromQJsonObject(QJsonObject jsonObject);
};

#endif // CHESSAPPLICATION_CHESSPIECEPOSITIONTRANSFER_H
