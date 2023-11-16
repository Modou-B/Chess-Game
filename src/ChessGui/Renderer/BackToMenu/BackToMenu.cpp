//
// Created by modou on 03.11.2023.
//

#include "BackToMenu.h"
#include "QWidget"

BackToMenu::BackToMenu(QWidget *mainWindow, QWidget *checkmateWindow,bool isCheckmate) {
    this->mainWindow = mainWindow;
    this->checkmateWindow = checkmateWindow;
    this->isCheckmate = isCheckmate;

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

    if (this->isCheckmate == true) {
        checkmateWindow->close();
    }






}