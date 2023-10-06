//
// Created by Julian Sommer on 25.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H
#define CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H

#include <string>
#include <utility>

using namespace std;

class ChessGameStateTransfer {
private:
    string currentGameState;
    int turnCounter;
    int currentPlayer;
    int currentOpponentPlayer;

    pair<int, int> lastTurnClickedCellCoordinate;

public:
    ChessGameStateTransfer *setCurrentGameState(string gameState);
    ChessGameStateTransfer *setCurrentPlayer(int player);
    ChessGameStateTransfer *setCurrentOpponentPlayer(int player);
    ChessGameStateTransfer *setTurnCounter(int turn);
    ChessGameStateTransfer *setLastTurnClickedCellCoordinate(
        pair<int, int> lastTurnClickedCellCoordinate
    );

    string getCurrentGameState();
    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    int getTurnCounter();
    pair<int, int> getLastTurnClickedCellCoordinate();
};

#endif // CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H
