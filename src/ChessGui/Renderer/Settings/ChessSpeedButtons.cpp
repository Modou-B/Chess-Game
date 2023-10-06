//
// Created by Modou on 28.09.23.
//

#include "ChessSpeedButtons.h"
#include "../ChessGuiRenderer.h"

ChessSpeedButtons::ChessSpeedButtons(ChessGuiRenderer *chessGuiRenderer, int speedModeTimerValue) {
    this->chessGuiRenderer = chessGuiRenderer;
    this->speedModeTimerValue = speedModeTimerValue;

    connect(this, &QPushButton::released, this, &ChessSpeedButtons::setPlayMode);
}

void ChessSpeedButtons::setPlayMode() {
    this->chessGuiRenderer->onPressSpeedButton(this->speedModeTimerValue);
}