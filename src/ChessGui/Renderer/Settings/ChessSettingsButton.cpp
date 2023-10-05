//
// Created by Modou on 05.10.23.
//

#include "ChessSettingsButton.h"
#include "ChessSettingsRenderer.h"

ChessSettingsButton::ChessSettingsButton() {
    connect(this, &QPushButton::released, this, &ChessSettingsButton::openSettings);
}

void ChessSettingsButton::openSettings() {
    this->chessSettingsRenderer->onPressSettingsButton();
}