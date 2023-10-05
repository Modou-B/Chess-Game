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

    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}