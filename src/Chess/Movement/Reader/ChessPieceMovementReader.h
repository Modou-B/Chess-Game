//
// Created by Julian Sommer on 02.10.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTREADER_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTREADER_H

#include <vector>

using namespace std;

class PossibleMoveCollectionTransfer;
class ChessPiecePossibleMoveTransfer;

class ChessPieceMovementReader {
protected:
    void addPreviousPossibleMoves(
      PossibleMoveCollectionTransfer &possibleMoveCollectionTransfer,
      vector<ChessPiecePossibleMoveTransfer *> previousPossibleMoves
    );
    void addPossibleMoves(
        PossibleMoveCollectionTransfer &possibleMoveCollectionTransfer,
        vector<ChessPiecePossibleMoveTransfer *> possibleMoves
    );

public:
    PossibleMoveCollectionTransfer getPossibleMovesForAllTypes();
    PossibleMoveCollectionTransfer getPreviousPossibleMoves();
    PossibleMoveCollectionTransfer getPossibleMoves();
};

#endif // CHESSAPPLICATION_CHESSPIECEMOVEMENTREADER_H
