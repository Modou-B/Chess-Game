//
// Created by Modou on 03.10.23.
//

#include "RewindTimelineButton.h"
#include "../../../ChessTimeline/ChessTimelineFacade.h"
#include "Renderer/Timeline/ChessTimelineRenderer.h"
#include "../ChessGuiCellManager.h"
#include "../../../Shared/ChessTimeline/ChessTimelineConstants.h"
#include "QLabel"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "rewindDesicion/acceptRewind.h"
#include "rewindDesicion/declineRewind.h"

RewindTimelineButton::RewindTimelineButton(
    ChessTimelineRenderer *chessTimelineRenderer,
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiCellManager *chessGuiCellManager
) {
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessGuiCellManager = chessGuiCellManager;

    connect(this, &QPushButton::released, this, &RewindTimelineButton::setRewindTimeline);
}

void RewindTimelineButton::setRewindTimeline(){
    auto selectedTurn = this->chessTimelineRenderer->rewindTurn();

    auto *chessTurnLogTransfer = this->chessTimelineFacade->findChessTurnLogForTurn(selectedTurn);

    this->chessGuiCellManager->updateChessGrid(
        chessTurnLogTransfer,
        ChessTimelineConstants::MODE_REWIND
    );
}