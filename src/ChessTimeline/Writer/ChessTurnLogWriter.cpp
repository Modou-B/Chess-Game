//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTurnLogWriter.h"
#include "../Mapper/ChessTimelineMapper.h"
#include "../../Shared/ChessTimeline/EndTurnInformationTransfer.h"
#include "../Model/ChessTurnLog.h"
#include "../Model/ChessPieceLog.h"
#include "../Model/ChessTimelineData.h"

ChessTurnLogWriter::ChessTurnLogWriter(ChessTimelineMapper *chessTimelineMapper) {
    this->chessTimelineMapper = chessTimelineMapper;
}

void ChessTurnLogWriter::logChessPieceStateTransfers(
    EndTurnInformationTransfer endTurnInformationTransfer
) {
    auto *chessTurnLog = new ChessTurnLog();
    this->chessTimelineMapper->mapEndTurnInformationTransferToChessTurnLog(
      endTurnInformationTransfer,
        *chessTurnLog
    );

    ChessTimelineData::insertNewTurnLog(chessTurnLog);
}

void ChessTurnLogWriter::removeLastTurnLog()
{
    ChessTimelineData::getChessTurnLogs()->erase(
        ChessTimelineData::getChessTurnLogs()->begin() + (ChessTimelineData::getChessTurnLogs()->size()-1)
    );
}