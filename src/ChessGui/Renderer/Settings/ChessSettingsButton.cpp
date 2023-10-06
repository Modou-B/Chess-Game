//
// Created by Modou on 05.10.23.
//

#include "ChessSettingsButton.h"
#include "ChessSettingsRenderer.h"

ChessSettingsButton::ChessSettingsButton(
    ChessSettingsRenderer *chessSettingsRenderer
) {
    this->chessSettingsRenderer = chessSettingsRenderer;

    connect(this, &QPushButton::released, this, &ChessSettingsButton::openSettings);
}

void ChessSettingsButton::openSettings() {
    this->chessSettingsRenderer->createSettingsView();
}