//
// Created by Julian Sommer on 27.08.23.
//

#include "ServiceRegistry.h"
#include "../Chess/ChessFactory.h"
#include "../Chess/ChessFacade.h"
#include "../MainFactory.h"


void ServiceRegistry::registerServices() {
    Container serviceContainer = Container();

    ServiceRegistry::addFactories(&serviceContainer);
    ServiceRegistry::addFacades(&serviceContainer);

    AbstractResolver::setContainer(&serviceContainer);
}

void ServiceRegistry::addFactories(Container *serviceContainer) {
    serviceContainer->setFactory(typeid(ChessFactory).name(), []() { return std::make_shared<ChessFactory>(); });
    serviceContainer->setFactory(typeid(MainFactory).name(), []() { return std::make_shared<MainFactory>(); });
}

void ServiceRegistry::addFacades(Container *serviceContainer) {
    serviceContainer->setFacade(typeid(ChessFacade).name(), []() { return std::make_shared<ChessFacade>(); });
}


