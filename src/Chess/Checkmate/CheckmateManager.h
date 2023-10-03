//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_CHECKMATEMANAGER_H
#define CHESSAPPLICATION_CHECKMATEMANAGER_H

#include <utility>
#include <vector>
#include <map>

class ChessField;

class InCheckStatusChecker;
class InStalemateStatusChecker;
class BareKingDrawStatusChecker;
class InCheckResponseTransfer;
class ChessPlayerData;

class CheckmateManager {
private:
    InCheckStatusChecker *inCheckStatusChecker;
    InStalemateStatusChecker *inStalemateStatusChecker;
    BareKingDrawStatusChecker *bareKingDrawStatusChecker;

protected:
    bool isPlayerInCheckmate(
      ChessField *chessField, std::pair<int, int> kingPieceCoordinates, ChessPlayerData *chessPlayerData, InCheckResponseTransfer inCheckResponseTransfer, int currentPlayer);

public:
    CheckmateManager(
          InCheckStatusChecker *inCheckStatusChecker, InStalemateStatusChecker *inStalemateStatusChecker, BareKingDrawStatusChecker *bareKingDrawStatusChecker);

    void determineCurrentGameState(ChessField *chessField, ChessPlayerData *currentChessPlayerData, ChessPlayerData *opponentChessPlayerData, int player);
};

#endif // CHESSAPPLICATION_CHECKMATEMANAGER_H
