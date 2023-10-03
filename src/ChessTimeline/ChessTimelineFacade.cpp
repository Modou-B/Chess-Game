//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTimelineFacade.h"
#include "../Shared/ChessTimeline/EndTurnInformationTransfer.h"

void ChessTimelineFacade::logCurrentTurnData(
    EndTurnInformationTransfer endTurnInformationTransfer
) {
    ChessTimelineFacade::getFactory()->createChessTurnLogWriter()->logChessPieceStateTransfers(endTurnInformationTransfer);
}

ChessTimelineFactory *ChessTimelineFacade::getFactory()
{
    return static_cast<ChessTimelineFactory*>(this->findFactory(typeid(ChessTimelineFactory).name()));
}