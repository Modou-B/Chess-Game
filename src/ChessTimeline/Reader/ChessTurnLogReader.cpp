//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTurnLogReader.h"
#include "../Model/ChessTimelineData.h"
#include "../Mapper/ChessTimelineMapper.h"
#include "../../Shared/ChessTimeline/ChessTurnLogTransfer.h"
#include "iostream"

ChessTurnLogReader::ChessTurnLogReader(ChessTimelineMapper *chessTimelineMapper) {
    this->chessTimelineMapper = chessTimelineMapper;
}

ChessTurnLogTransfer *ChessTurnLogReader::getChessTurnLogForSpecificTurn(int turn)
{
    if (ChessTimelineData::getChessTurnLogs()->empty()) {
        return new ChessTurnLogTransfer();
    }

    return this->chessTimelineMapper->mapChessTurnLogToChessTurnLogTransfer(
             ChessTimelineData::getChessTurnLogs()->at(turn)
    );
}

vector<ChessTurnLogTransfer *> ChessTurnLogReader::getChessTurnLogsForTurnRange(int startTurn, int endTurn) {
    vector<ChessTurnLogTransfer *> chessTurnLogTransfers = {};

    for (int i = startTurn; i < endTurn; i++) {
        chessTurnLogTransfers.push_back(
            this->getChessTurnLogForSpecificTurn(i)
        );
    }

    return chessTurnLogTransfers;
}