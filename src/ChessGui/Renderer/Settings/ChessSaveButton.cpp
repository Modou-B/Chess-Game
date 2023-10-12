//
// Created by Modou on 12.10.23.
//

#include "ChessSaveButton.h"
#include "ChessSettingsRenderer.h"

ChessSaveButton::ChessSaveButton(ChessSettingsRenderer *chessSettingsRenderer, QWidget *settingsWindow) {
    this->chessSettingsRenderer = chessSettingsRenderer;
    this->settingsWindow = settingsWindow;

    connect(this, &QPushButton::released, this, &ChessSaveButton::saveSettings);
}

void ChessSaveButton::saveSettings() {
    setSavedPlayerColorToPlayerColor();
}

void ChessSaveButton::setSavedPlayerColorToPlayerColor() {
    this->chessSettingsRenderer->saveCustomColor();
    this->settingsWindow->close();
}