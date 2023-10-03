//
// Created by Julian Sommer on 03.10.23.
//

#ifndef CHESSAPPLICATION_CHESSGUICELLMANAGER_H
#define CHESSAPPLICATION_CHESSGUICELLMANAGER_H

#include <utility>
#include <string>

using namespace std;

class QGridLayout;

class ChessGuiCellManager {
private:
    static QGridLayout *chessGuiCellGrid;

public:
    void setChessGuiCellGrid(QGridLayout *chessGuiCellGrid);

    void handlePawnPieceSwitch(
        pair<int, int> chessGuiCellCoordinate,
        string pieceTypeToSwitch
    );
};

#endif // CHESSAPPLICATION_CHESSGUICELLMANAGER_H
