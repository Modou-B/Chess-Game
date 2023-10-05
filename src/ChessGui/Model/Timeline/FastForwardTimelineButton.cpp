//
// Created by Modou on 03.10.23.
//

#include "FastForwardTimelineButton.h"
#include "../../../ChessTimeline/ChessTimelineFacade.h"
#include "Renderer/Timeline/ChessTimelineRenderer.h"
#include "../ChessGuiCellManager.h"
#include "../../../Shared/ChessTimeline/ChessTimelineConstants.h"

FastForwardTimelineButton::FastForwardTimelineButton(
    ChessTimelineRenderer *chessTimelineRenderer,
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiCellManager *chessGuiCellManager
) {
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessGuiCellManager = chessGuiCellManager;

    connect(this, &QPushButton::released, this, &FastForwardTimelineButton::setFastForwardTimeline);
}

void FastForwardTimelineButton::setFastForwardTimeline(){
    auto selectedTurn = this->chessTimelineRenderer->fastForwardTurn();

    auto *chessTurnLogTransfer = this->chessTimelineFacade->findChessTurnLogForTurn(selectedTurn);

    this->chessGuiCellManager->updateChessGrid(
        chessTurnLogTransfer,
        ChessTimelineConstants::MODE_FORWARD
    );
}