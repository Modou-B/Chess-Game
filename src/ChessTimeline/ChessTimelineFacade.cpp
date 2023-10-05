//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTimelineFacade.h"
#include "../Shared/ChessTimeline/EndTurnInformationTransfer.h"

void ChessTimelineFacade::logCurrentTurnData(
    EndTurnInformationTransfer endTurnInformationTransfer
) {
    ChessTimelineFacade::getFactory()
        ->createChessTurnLogWriter()
        ->logChessPieceStateTransfers(endTurnInformationTransfer);
}

ChessTurnLogTransfer *ChessTimelineFacade::findChessTurnLogForTurn(int turn)
{
    return ChessTimelineFacade::getFactory()
        ->createChessTurnLogReader()
        ->getChessTurnLogForSpecificTurn(turn);
}

void ChessTimelineFacade::handleChessGridUpdateForGivenTurn(int turn)
{
    ChessTimelineFacade::getFactory()
        ->createChessGridUpdater()
        ->handleChessGridUpdateForGivenTurn(turn);
}

ChessTimelineFactory *ChessTimelineFacade::getFactory()
{
    return static_cast<ChessTimelineFactory*>(this->findFactory(typeid(ChessTimelineFactory).name()));
}