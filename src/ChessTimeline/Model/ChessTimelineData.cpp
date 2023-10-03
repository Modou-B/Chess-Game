//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTimelineData.h"

vector<ChessTurnLog*> *ChessTimelineData::chessTurnLogs = new vector<ChessTurnLog*>();

void ChessTimelineData::insertNewTurnLog(ChessTurnLog *turnLog) {
    ChessTimelineData::chessTurnLogs->push_back(turnLog);
}

vector<ChessTurnLog*> *ChessTimelineData::getChessTurnLogs() {
    return ChessTimelineData::chessTurnLogs;
}

