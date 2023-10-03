//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTURNLOG_H
#define CHESSAPPLICATION_CHESSTURNLOG_H

#include <vector>

class ChessPieceLog;

class ChessTurnLog {
private:
    int currentPlayer;
    int turnCounter;
    std::vector<ChessPieceLog *> *chessPieceLogs;

public:
    ChessTurnLog(int currentPlayer, int turnCounter, std::vector<ChessPieceLog*> *chessPieceLogs);
    ChessTurnLog();

    void setCurrentPlayer(int player);
    void setTurnCounter(int turnCounter);
    void setChessPieceLogs(std::vector<ChessPieceLog *> *chessPieceLogs);

    int getCurrentPlayer();
    int getTurnCounter();
    std::vector<ChessPieceLog*> *getChessPieceLogs();
};

#endif // CHESSAPPLICATION_CHESSTURNLOG_H
