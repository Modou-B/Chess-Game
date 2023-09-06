//
// Created by Julian Sommer on 27.08.23.
//

#include "MainFacade.h"

void MainFacade::initializeGui(QWidget *mainWindow) {
    this->getFactory()->getChessGuiFacade()->initializeChessField(mainWindow);
}

MainFactory* MainFacade::getFactory() {
    return static_cast<MainFactory*>(this->findFactory(typeid(MainFactory).name()));
}

void MainFacade::initializeChessGame() {
    this->getFactory()->getChessFacade()->initiateChessGame();
}

