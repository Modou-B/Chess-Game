//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECELOG_H
#define CHESSAPPLICATION_CHESSPIECELOG_H

#include <utility>
#include <string>

using namespace std;

class ChessPieceLog {
private:
    int playerOfChessPiece;
    string chessPieceColor;
    string chessPieceType;
    string chessPieceState;
    pair<int, int> startCellCoordinate;
    pair<int, int> endCellCoordinate;

public:
    ChessPieceLog(
        int playerOfChessPiece,
        string chessPieceColor,
        string chessPieceType,
        string chessPieceState,
        pair<int, int> startCellCoordinate,
        pair<int, int> endCellCoordinate
    );

    int getPlayerOfChessPiece();
    string getChessPieceColor();
    string getChessPieceType();
    string getChessPieceState();
    pair<int, int> getStartingCellCoordinate();
    pair<int, int> getEndCellCoordinate();
};

#endif // CHESSAPPLICATION_CHESSPIECELOG_H
