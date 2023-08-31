//
// Created by Julian Sommer on 27.08.23.
//

#include "MainFacade.h"


void MainFacade::testResolver() {
    this->getFactory()->testFactory();
}

MainFactory* MainFacade::getFactory() {
    return static_cast<MainFactory*>(this->findFactory(typeid(MainFactory).name()));
}