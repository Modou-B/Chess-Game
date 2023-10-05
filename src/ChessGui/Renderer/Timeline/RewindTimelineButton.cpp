//
// Created by Modou on 03.10.23.
//

#include "RewindTimelineButton.h"
#include "../ChessGuiRenderer.h"

#include "QListWidget"

RewindTimelineButton::RewindTimelineButton(ChessGuiRenderer *chessGuiRenderer) {
    this->chessGuiRenderer = chessGuiRenderer;
    connect(this, &QPushButton::released, this, &RewindTimelineButton::setRewindTimeline);

}

void RewindTimelineButton::setRewindTimeline(){
    this->chessGuiRenderer->timelineList->setCurrentRow(this->chessGuiRenderer->timelineList->currentRow() - 1);
    //this->chessTurnLogReader->getChessTurnLogForSpecificTurn(LastEntry);
}