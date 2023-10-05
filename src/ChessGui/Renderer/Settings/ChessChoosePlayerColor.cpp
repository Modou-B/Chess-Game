//
// Created by Modou on 05.10.23.
//

#include "ChessChoosePlayerColor.h"
#include "ChessSettingsRenderer.h"
#include <QColor>

ChessChoosePlayerColor::ChessChoosePlayerColor(ChessSettingsRenderer *chessSettingsRenderer, int player) {
    this->player = player;
    this->chessSettingsRenderer = chessSettingsRenderer;

    connect(this, &QPushButton::released, this, &ChessChoosePlayerColor::setActivePlayerToChooseColorFor);
}

void ChessChoosePlayerColor::setActivePlayerToChooseColorFor() {
    this->chessSettingsRenderer->setChoosePlayer(this->player);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}