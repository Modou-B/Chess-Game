//
// Created by Julian Sommer on 02.10.23.
//

#ifndef CHESSAPPLICATION_POSSIBLEMOVECOLLECTIONTRANSFER_H
#define CHESSAPPLICATION_POSSIBLEMOVECOLLECTIONTRANSFER_H

#include <vector>

using namespace std;

class ChessPiecePossibleMoveTransfer;

class PossibleMoveCollectionTransfer {
private:
    vector<ChessPiecePossibleMoveTransfer*> previousPossibleMoveTransfers = {};
    vector<ChessPiecePossibleMoveTransfer*> possibleMoveTransfers = {};

public:
    PossibleMoveCollectionTransfer *setPreviousPossibleMoveTransfers(vector<ChessPiecePossibleMoveTransfer*> possibleMoves);
    PossibleMoveCollectionTransfer *setPossibleMoveTransfers(vector<ChessPiecePossibleMoveTransfer*> possibleMoves);

    void addPreviousPossibleMoveTransfer(ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer);
    void addPossibleMoveTransfer(ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer);

    vector<ChessPiecePossibleMoveTransfer*> getPreviousPossibleMoveTransfers();
    vector<ChessPiecePossibleMoveTransfer*> getPossibleMoveTransfers();
};

#endif // CHESSAPPLICATION_POSSIBLEMOVECOLLECTIONTRANSFER_H
