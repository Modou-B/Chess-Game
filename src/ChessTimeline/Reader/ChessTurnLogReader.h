//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTURNLOGREADER_H
#define CHESSAPPLICATION_CHESSTURNLOGREADER_H

#include <vector>

using namespace std;

class ChessTimelineMapper;
class ChessTurnLogTransfer;
class ChessTurnLog;

class ChessTurnLogReader {
private:
    ChessTimelineMapper *chessTimelineMapper;

public:
    ChessTurnLogReader(ChessTimelineMapper *chessTimelineMapper);

    ChessTurnLogTransfer *getChessTurnLogForSpecificTurn(int turn);
    vector<ChessTurnLogTransfer *> getChessTurnLogsForTurnRange(int startTurn, int endTurn);
};

#endif // CHESSAPPLICATION_CHESSTURNLOGREADER_H
