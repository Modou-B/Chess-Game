//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTIMELINEDATA_H
#define CHESSAPPLICATION_CHESSTIMELINEDATA_H

#include <vector>
#include <string>

using namespace std;

class ChessTurnLog;

class ChessTimelineData {
private:
    static vector<ChessTurnLog*> *chessTurnLogs;

public:
    static void insertNewTurnLog(ChessTurnLog *turnLog);

    static vector<ChessTurnLog*> *getChessTurnLogs();
};

#endif // CHESSAPPLICATION_CHESSTIMELINEDATA_H
