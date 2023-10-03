//
// Created by Julian Sommer on 25.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H
#define CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H

#include <string>
#include <utility>

class ChessGameStateTransfer {
private:
    int currentPlayer;
    int currentOpponentPlayer;
    int turnCounter;

public:
    ChessGameStateTransfer *setCurrentPlayer(int player);
    ChessGameStateTransfer *setCurrentOpponentPlayer(int player);
    ChessGameStateTransfer *setTurnCounter(int turnCounter);

    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    int getTurnCounter();
};

#endif // CHESSAPPLICATION_CHESSGAMESTATETRANSFER_H
