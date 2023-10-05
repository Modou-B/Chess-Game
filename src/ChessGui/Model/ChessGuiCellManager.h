//
// Created by Julian Sommer on 03.10.23.
//

#ifndef CHESSAPPLICATION_CHESSGUICELLMANAGER_H
#define CHESSAPPLICATION_CHESSGUICELLMANAGER_H

#include <utility>
#include <string>
#include <vector>

using namespace std;

class QGridLayout;
class ChessTurnLogTransfer;
class ChessPieceInformationTransfer;
class ChessGuiCell;

class ChessGuiCellManager {
private:
    static QGridLayout *chessGuiCellGrid;

protected:
    ChessGuiCell *getChessGuiCell(pair<int, int> chessCellCoordinate);

    void handleChessPieceStates(
        ChessPieceInformationTransfer *chessPieceInformationTransfer,
        string mode
    );

public:
    void setChessGuiCellGrid(QGridLayout *chessGuiCellGrid);

    void handlePawnPieceSwitch(
        pair<int, int> chessGuiCellCoordinate,
        string pieceTypeToSwitch
    );

    void forwardChessGridToLatestTurn(vector<ChessTurnLogTransfer *> chessTurnLogTransfers);
    void updateChessGrid(
        ChessTurnLogTransfer *chessTurnLogTransfer,
        string mode
    );
};

#endif // CHESSAPPLICATION_CHESSGUICELLMANAGER_H
