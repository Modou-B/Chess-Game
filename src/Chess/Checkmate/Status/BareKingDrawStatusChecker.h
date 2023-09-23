//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_BAREKINGDRAWSTATUSCHECKER_H
#define CHESSAPPLICATION_BAREKINGDRAWSTATUSCHECKER_H

#include <utility>

class ChessField;

class BareKingDrawStatusChecker {
public:
    bool isCheckmateNotPossible(ChessField *chessField, std::pair<int, int> kingPieceCoordinates, int currentPlayer);
};

#endif // CHESSAPPLICATION_BAREKINGDRAWSTATUSCHECKER_H
