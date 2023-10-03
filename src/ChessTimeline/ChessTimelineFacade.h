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

class ChessTimelineFacade: public AbstractFacade {
public:
    void logCurrentTurnData(
        EndTurnInformationTransfer endTurnInformationTransfer
    );

    ChessTimelineFactory *getFactory() override;
};

#endif // CHESSAPPLICATION_CHESSTIMELINEFACADE_H
