//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_BAREKINGDRAWSTATUSCHECKER_H
#define CHESSAPPLICATION_BAREKINGDRAWSTATUSCHECKER_H

#include <utility>

class ChessField;
class ChessPlayerData;

class BareKingDrawStatusChecker {
protected:
    bool hasOpponentOnlyKnightOrBishopLeft(ChessPlayerData *opponentChessPlayerData);

public:
    bool isCheckmateNotPossible(ChessPlayerData *currentChessPlayerData, ChessPlayerData *opponentChessPlayerData);
};

#endif // CHESSAPPLICATION_BAREKINGDRAWSTATUSCHECKER_H
