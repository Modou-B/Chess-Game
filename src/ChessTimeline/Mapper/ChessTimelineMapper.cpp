//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTimelineMapper.h"
#include "../Model/ChessTurnLog.h"
#include "../Model/ChessPieceLog.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceStateTransfer.h"
#include "../../Shared/Chess/Transfer/GameState/ChessGameStateTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceInformationTransfer.h"
#include "../../Shared/ChessTimeline/EndTurnInformationTransfer.h"
#include "../../Shared/ChessTimeline/ChessTurnLogTransfer.h"
#include "iostream"

string ChessTimelineMapper::playerToColorMap[2] = {"-white", "-black"};

void ChessTimelineMapper::mapEndTurnInformationTransferToChessTurnLog(
    EndTurnInformationTransfer endTurnInformationTransfer,
    ChessTurnLog &chessTurnLog
) {
    auto chessPieceLogs = new vector<ChessPieceLog *>();
    for (auto &chessPieceStateTransfer :endTurnInformationTransfer.getChessPieceStateTransfers()) {
        chessPieceLogs->push_back(this->mapChessPieceStateTransferToChessPieceLog(
            chessPieceStateTransfer
        ));
    }

    auto *chessGameStateTransfer = endTurnInformationTransfer.getChessGameStateTransfer();
    chessTurnLog.setCurrentGameState(chessGameStateTransfer->getCurrentGameState());
    chessTurnLog.setCurrentPlayer(chessGameStateTransfer->getCurrentPlayer());
    chessTurnLog.setCurrentOpponentPlayer(chessGameStateTransfer->getCurrentOpponentPlayer());
    chessTurnLog.setTurnCounter(chessGameStateTransfer->getTurnCounter());

    if (chessGameStateTransfer->getTurnCounter() > 0) {
        chessTurnLog.setCoordinateOfLastTurnClickedCell(
          chessGameStateTransfer->getLastTurnClickedCellCoordinate());
    }

    chessTurnLog.setChessPieceLogs(chessPieceLogs);
}

ChessPieceLog *ChessTimelineMapper::mapChessPieceStateTransferToChessPieceLog(
    ChessPieceStateTransfer *chessPieceStateTransfer
) {
    return new ChessPieceLog(
        chessPieceStateTransfer->getPlayerOfChessPiece(),
        this->getChessPieceColorForPlayer(chessPieceStateTransfer->getPlayerOfChessPiece()),
        chessPieceStateTransfer->getChessPieceType(),
        chessPieceStateTransfer->getState(),
        chessPieceStateTransfer->getStartCoordinate(),
        chessPieceStateTransfer->getEndCoordinate()
    );
}

string ChessTimelineMapper::getChessPieceColorForPlayer(int player) {
    return ChessTimelineMapper::playerToColorMap[player-1];
}

vector<ChessTurnLogTransfer *> ChessTimelineMapper::mapChessTurnLogsToChessTurnLogTransfers(
    vector<ChessTurnLog *> chessTurnLogs
) {
    vector<ChessTurnLogTransfer *> chessTurnLogsTransfers = {};

    for (auto &chessTurnLog :chessTurnLogs) {
        chessTurnLogsTransfers.push_back(
            this->mapChessTurnLogToChessTurnLogTransfer(chessTurnLog)
        );
    }

    return chessTurnLogsTransfers;
}

ChessTurnLogTransfer *ChessTimelineMapper::mapChessTurnLogToChessTurnLogTransfer(ChessTurnLog *chessTurnLog) {
      auto *chessTurnLogTransfer = new ChessTurnLogTransfer();

      chessTurnLogTransfer->setChessGameStateTransfer(
          this->mapChessTurnLogToChessGameStateTransfer(chessTurnLog)
      )->setChessPieceInformationTransfers(
          this->mapChessPieceLogsToChessPieceInformationTransfers(
              chessTurnLog->getChessPieceLogs()
          )
      );

      return chessTurnLogTransfer;
}

vector<ChessPieceInformationTransfer *> ChessTimelineMapper::mapChessPieceLogsToChessPieceInformationTransfers(
    vector<ChessPieceLog *> *chessPieceLogs
) {
    vector<ChessPieceInformationTransfer *> chessPieceInformationTransfers = {};

    for (auto &chessPieceLog: *chessPieceLogs) {
        chessPieceInformationTransfers.push_back(
          this->mapChessPieceLogToChessPieceInformationTransfer(
              chessPieceLog
          )
        );
    }

    return chessPieceInformationTransfers;
}

ChessPieceInformationTransfer *ChessTimelineMapper::mapChessPieceLogToChessPieceInformationTransfer(
    ChessPieceLog *chessPieceLog
) {
    auto *chessPieceInformationTransfer = new ChessPieceInformationTransfer();

    chessPieceInformationTransfer->setChessPieceColor(
        chessPieceLog->getChessPieceColor()
    )->setChessPieceStateTransfer(
        this->mapChessPieceLogToChessPieceStateTransfer(chessPieceLog)
    );

    return chessPieceInformationTransfer;
}

ChessPieceStateTransfer *ChessTimelineMapper::mapChessPieceLogToChessPieceStateTransfer(
    ChessPieceLog *chessPieceLog
) {
    auto *chessPieceStateTransfer = new ChessPieceStateTransfer();

    chessPieceStateTransfer->setPlayerOfChessPiece(
        chessPieceLog->getPlayerOfChessPiece()
    )->setChessPieceType(
        chessPieceLog->getChessPieceType()
    )->setState(
        chessPieceLog->getChessPieceState()
    )->setStartCoordinate(
        chessPieceLog->getStartingCellCoordinate()
    )->setEndCoordinate(
        chessPieceLog->getEndCellCoordinate()
    );

    return chessPieceStateTransfer;
}

ChessGameStateTransfer *ChessTimelineMapper::mapChessTurnLogToChessGameStateTransfer(
    ChessTurnLog *chessTurnLog
) {
    auto *chessGameStateTransfer = new ChessGameStateTransfer();
    chessGameStateTransfer->setCurrentGameState(chessTurnLog->getCurrentGameState())
        ->setCurrentPlayer(chessTurnLog->getCurrentPlayer())
        ->setCurrentOpponentPlayer(chessTurnLog->getCurrentOpponentPlayer())
        ->setTurnCounter(chessTurnLog->getTurnCounter());

    if (chessTurnLog->getTurnCounter() > 0) {
        chessGameStateTransfer->setLastTurnClickedCellCoordinate(
            chessTurnLog->getCoordinateOfLastTurnClickedCell()
        );
    }

    return chessGameStateTransfer;
}


