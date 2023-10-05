//
// Created by Modou on 03.10.23.
//

#include "PauseGameTimerButton.h"
#include "../../../ChessTimeline/ChessTimelineFacade.h"
#include "Renderer/Timeline/ChessTimelineRenderer.h"

PauseGameTimerButton::PauseGameTimerButton(
    ChessTimelineRenderer *chessTimelineRenderer,
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiCellManager *chessGuiCellManager
) {
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessGuiCellManager = chessGuiCellManager;

    connect(this, &QPushButton::released, this, &PauseGameTimerButton::setPauseGameTimer);
}

void PauseGameTimerButton::setPauseGameTimer(){
    qDebug() << "Pause Game";
}