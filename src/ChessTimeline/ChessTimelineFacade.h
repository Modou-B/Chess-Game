//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTIMELINEFACADE_H
#define CHESSAPPLICATION_CHESSTIMELINEFACADE_H

#include "../Application/Facade/AbstractFacade.h"
#include "ChessTimelineFactory.h"
#include <vector>

using namespace std;

class EndTurnInformationTransfer;
class ChessTurnLogTransfer;

class ChessTimelineFacade: public AbstractFacade {
public:
    void logCurrentTurnData(
        EndTurnInformationTransfer endTurnInformationTransfer
    );

    ChessTurnLogTransfer *findChessTurnLogForTurn(int turn);
    vector<ChessTurnLogTransfer *> findChessTurnLogsForTurnRange(int startTurn, int endTurn);

    void handleChessGridUpdateForGivenTurn(int turn);

    void deleteLastTurnLog();

    ChessTimelineFactory *getFactory() override;
};

#endif // CHESSAPPLICATION_CHESSTIMELINEFACADE_H
