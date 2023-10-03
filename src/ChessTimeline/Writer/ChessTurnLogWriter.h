//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTURNLOGWRITER_H
#define CHESSAPPLICATION_CHESSTURNLOGWRITER_H

#include <vector>

using namespace std;

class ChessPieceStateTransfer;
class ChessTimelineMapper;
class EndTurnInformationTransfer;

class ChessTurnLogWriter {
private:
    ChessTimelineMapper *chessTimelineMapper;

public:
    ChessTurnLogWriter(ChessTimelineMapper *chessTimelineMapper);

    void logChessPieceStateTransfers(
        EndTurnInformationTransfer endTurnInformationTransfer
    );
};

#endif // CHESSAPPLICATION_CHESSTURNLOGWRITER_H
