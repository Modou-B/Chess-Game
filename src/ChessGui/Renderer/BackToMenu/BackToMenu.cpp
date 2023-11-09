//
// Created by modou on 03.11.2023.
//

#include "BackToMenu.h"
#include "../ChessGuiRenderer.h"
#include "../../../MainFacade.h"
#include "QWidget"

BackToMenu::BackToMenu(ChessGuiRenderer *chessGuiRenderer,QWidget *mainWindow) {
    this->chessGuiRenderer = chessGuiRenderer;
    this->mainWindow = mainWindow;

    connect(this, &QPushButton::released, this, &BackToMenu::goBackToMainMenu);
}

void BackToMenu::goBackToMainMenu() {
    auto *window = new QWidget;
    MainFacade mainFacade = MainFacade();

    mainFacade.initializeChessGame();
    mainFacade.initializeGui(window);
    window->setFixedSize(500,400);
    window->show();
    this->mainWindow->close();
}