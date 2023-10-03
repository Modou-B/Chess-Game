//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTIMELINEMAPPER_H
#define CHESSAPPLICATION_CHESSTIMELINEMAPPER_H

#include <vector>
#include <string>
#include <utility>

using namespace std;

class ChessPieceStateTransfer;
class EndTurnInformationTransfer;
class ChessTurnLog;
class ChessPieceLog;
class ChessTurnLogTransfer;
class ChessPieceInformationTransfer;

class ChessTimelineMapper {
private:
    static string playerToColorMap[2];

protected:
    string getChessPieceColorForPlayer(int player);

public:
    void mapEndTurnInformationTransferToChessTurnLog(
        EndTurnInformationTransfer endTurnInformationTransfer,
        ChessTurnLog &chessTurnLog
    );

    ChessPieceLog *mapChessPieceStateTransferToChessPieceLog(
        ChessPieceStateTransfer *chessPieceStateTransfer
    );

    vector<ChessTurnLogTransfer *> mapChessTurnLogsToChessTurnLogTransfers(
        vector<ChessTurnLog *> chessTurnLogs
    );

    ChessTurnLogTransfer *mapChessTurnLogToChessTurnLogTransfer(ChessTurnLog *chessTurnLog);

    vector<ChessPieceInformationTransfer *> mapChessPieceLogsToChessPieceInformationTransfers(
        vector<ChessPieceLog *> *chessPieceLogs
    );

    ChessPieceInformationTransfer *mapChessPieceLogToChessPieceInformationTransfer(
        ChessPieceLog *chessPieceLog
    );

    ChessPieceStateTransfer *mapChessPieceLogToChessPieceStateTransfer(
        ChessPieceLog *chessPieceLog
    );
};

#endif // CHESSAPPLICATION_CHESSTIMELINEMAPPER_H
