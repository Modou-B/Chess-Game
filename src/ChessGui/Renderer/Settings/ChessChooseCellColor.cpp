//
// Created by Modou on 05.10.23.
//

#include "ChessChooseCellColor.h"
#include "ChessSettingsRenderer.h"

ChessChooseCellColor::ChessChooseCellColor(ChessSettingsRenderer *chessSettingsRenderer, QColor playerColor) {
    this->playerColor = playerColor;
    this->chessSettingsRenderer = chessSettingsRenderer;

    connect(this, &QPushButton::released, this, &ChessChooseCellColor::setColorForCell);
}

void ChessChooseCellColor::setColorForCell() {
    this->chessSettingsRenderer->setPlayerColor(this->playerColor);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}