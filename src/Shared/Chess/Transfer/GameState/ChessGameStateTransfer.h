//
// Created by Julian Sommer on 25.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H
#define CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H

#include <string>

using namespace std;

class ChessGameStateTransfer {
private:
    string currentGameState;
    int currentPlayer;
    int currentOpponentPlayer;
    int turnCounter;

public:
    ChessGameStateTransfer *setCurrentGameState(string gameState);
    ChessGameStateTransfer *setCurrentPlayer(int player);
    ChessGameStateTransfer *setCurrentOpponentPlayer(int player);
    ChessGameStateTransfer *setTurnCounter(int turnCounter);

    string getCurrentGameState();
    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    int getTurnCounter();
};

#endif // CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H
