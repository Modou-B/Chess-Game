//
// Created by Julian Sommer on 24.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTIMER_H
#define CHESSAPPLICATION_CHESSTIMER_H

#include "QLCDNumber"

class ChessTimer: public QLCDNumber {
private:
    int currentTime;
    int currentPlayer;
public:
    ChessTimer(int player, int speedModeTimerValue);

    void showTime();
};

#endif // CHESSAPPLICATION_CHESSTIMER_H
