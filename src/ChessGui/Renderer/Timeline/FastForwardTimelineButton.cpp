//
// Created by Modou on 03.10.23.
//

#include "FastForwardTimelineButton.h"
#include "../ChessGuiRenderer.h"
#include "../ChessTimeline/Reader/ChessTurnLogReader.h"
#include "QListWidget"

FastForwardTimelineButton::FastForwardTimelineButton(ChessGuiRenderer *chessGuiRenderer) {
    this->chessGuiRenderer = chessGuiRenderer;
    connect(this, &QPushButton::released, this, &FastForwardTimelineButton::setFastForwardTimeline);

}

void FastForwardTimelineButton::setFastForwardTimeline(){
    this->chessGuiRenderer->timelineList->setCurrentRow(this->chessGuiRenderer->timelineList->currentRow() + 1);
}