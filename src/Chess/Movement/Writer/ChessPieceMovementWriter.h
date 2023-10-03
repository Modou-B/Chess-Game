//
// Created by Julian Sommer on 02.10.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTWRITER_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTWRITER_H

#include <vector>

using namespace std;

class ChessPiecePossibleMoveTransfer;

class ChessPieceMovementWriter {
public:
    void updatePreviousPossibleMoveData(vector<ChessPiecePossibleMoveTransfer *> possibleMoves);
    void updatePreviousPossibleMoveDataWithCurrentPossibleMoves();

    void updatePossibleMoveData(vector<ChessPiecePossibleMoveTransfer *> possibleMoves);

    void clearPossibleMoveCollections();
};

#endif // CHESSAPPLICATION_CHESSPIECEMOVEMENTWRITER_H
