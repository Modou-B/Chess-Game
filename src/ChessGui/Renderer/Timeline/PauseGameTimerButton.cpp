//
// Created by Modou on 03.10.23.
//

#include "PauseGameTimerButton.h"
#include "../ChessGuiRenderer.h"

#include "QListWidget"

PauseGameTimerButton::PauseGameTimerButton(ChessGuiRenderer *chessGuiRenderer) {
    this->chessGuiRenderer = chessGuiRenderer;
    connect(this, &QPushButton::released, this, &PauseGameTimerButton::setPauseGameTimer);

}

void PauseGameTimerButton::setPauseGameTimer(){
    qDebug() << "Pause Game";
}