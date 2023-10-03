//
// Created by Modou on 28.09.23.
//

#include "ChessStartButton.h"
#include "../ChessGuiRenderer.h"

ChessStartButton::ChessStartButton(ChessGuiRenderer *chessGuiRenderer, QWidget *mainWindow) {
    this->chessGuiRenderer = chessGuiRenderer;
    this->mainWindow = mainWindow;

    connect(this, &QPushButton::released, this, &ChessStartButton::startGame);
}

void ChessStartButton::startGame() {
    this->chessGuiRenderer->onPressStartButton(this->mainWindow);
}