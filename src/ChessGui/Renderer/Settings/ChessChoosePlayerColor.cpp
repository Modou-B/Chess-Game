//
// Created by Modou on 05.10.23.
//

#include "ChessChoosePlayerColor.h"
#include "ChessSettingsRenderer.h"

ChessChoosePlayerColor::ChessChoosePlayerColor(
    ChessSettingsRenderer *chessSettingsRenderer,
    int player
) {
    this->chessSettingsRenderer = chessSettingsRenderer;
    this->player = player;

    connect(this, &QPushButton::released, this, &ChessChoosePlayerColor::setActivePlayerToChooseColorFor);
}

void ChessChoosePlayerColor::setActivePlayerToChooseColorFor() {
    this->chessSettingsRenderer->setPlayerToChooseColor(this->player);
}