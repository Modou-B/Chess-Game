//
// Created by Julian Sommer on 27.08.23.
//

#include "MainFacade.h"
#include "iostream"

MainFactory* MainFacade::getFactory() {
    return static_cast<MainFactory*>(this->findFactory(typeid(MainFactory).name()));
}

void MainFacade::initializeGui(QWidget *mainWindow) {
    this->getFactory()->getChessFacade()->createChessField(mainWindow);
}
