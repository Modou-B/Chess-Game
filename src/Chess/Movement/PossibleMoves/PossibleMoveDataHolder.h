//
// Created by Julian Sommer on 02.10.23.
//

#ifndef CHESSAPPLICATION_POSSIBLEMOVEDATAHOLDER_H
#define CHESSAPPLICATION_POSSIBLEMOVEDATAHOLDER_H

#include <vector>
#include <utility>

using namespace std;

class ChessPiecePossibleMoveTransfer;

class PossibleMoveDataHolder {
private:
    static vector<ChessPiecePossibleMoveTransfer*> previousPossibleMovesForClickedCell;
    static vector<ChessPiecePossibleMoveTransfer*> possibleMovesForClickedCell;

public:
    static void setPreviousPossibleMovesForClickedCell(vector<ChessPiecePossibleMoveTransfer*> possibleMoves);
    static void setPossibleMovesForClickedCell(vector<ChessPiecePossibleMoveTransfer*> possibleMoves);

    static vector<ChessPiecePossibleMoveTransfer*> getPreviousPossibleMovesForClickedCell();
    static vector<ChessPiecePossibleMoveTransfer*> getPossibleMovesForClickedCell();

    static void deletePreviousPossibleMoves();
    static void deletePossibleMoves();
};

#endif // CHESSAPPLICATION_POSSIBLEMOVEDATAHOLDER_H
