//
// Created by Modou on 12.10.23.
//

#include "ChessExitButton.h"

ChessExitButton::ChessExitButton(ChessSettingsRenderer *chessSettingsRenderer, QWidget *settingsWindow) {
    this->chessSettingsRenderer = chessSettingsRenderer;
    this->settingsWindow = settingsWindow;

    connect(this, &QPushButton::released, this, &ChessExitButton::exitWindow);
}

void ChessExitButton::exitWindow() {
    this->settingsWindow->close();
}