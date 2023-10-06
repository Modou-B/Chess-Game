//
// Created by Modou on 05.10.23.
//

#include "ChessChooseCellColor.h"
#include "ChessSettingsRenderer.h"

ChessChooseCellColor::ChessChooseCellColor(
    ChessSettingsRenderer *chessSettingsRenderer,
    QColor playerColor
) {
    this->chessSettingsRenderer = chessSettingsRenderer;
    this->playerColor = playerColor;

    connect(this, &QPushButton::released, this, &ChessChooseCellColor::setColorForCell);
}

void ChessChooseCellColor::setColorForCell() {
    this->chessSettingsRenderer->setColorForSetPlayer(this->playerColor);

    this->chessSettingsRenderer->updateCellColors();
}