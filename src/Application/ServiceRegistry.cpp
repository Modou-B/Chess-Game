//
// Created by Julian Sommer on 27.08.23.
//

#include "ServiceRegistry.h"
#include "../Chess/ChessFactory.h"
#include "../Chess/ChessFacade.h"
#include "../ChessGui/ChessGuiFactory.h"
#include "../ChessGui/ChessGuiFacade.h"
#include "../ChessTimeline/ChessTimelineFactory.h"
#include "../ChessTimeline/ChessTimelineFacade.h"
#include "../MultiplayerGui/MultiplayerGuiFacade.h"
#include "../MultiplayerGui/MultiplayerGuiFactory.h"
#include "../Multiplayer/MultiplayerFacade.h"
#include "../Multiplayer/MultiplayerFactory.h"
#include "../MainFactory.h"

void ServiceRegistry::registerServices()
{
    Container serviceContainer = Container();

    ServiceRegistry::addFactories(&serviceContainer);
    ServiceRegistry::addFacades(&serviceContainer);

    AbstractResolver::setContainer(&serviceContainer);
}

void ServiceRegistry::addFactories(Container *serviceContainer)
{
    serviceContainer->setFactory(typeid(ChessFactory).name(), []() { return std::make_shared<ChessFactory>(); });
    serviceContainer->setFactory(typeid(ChessGuiFactory).name(), []() { return std::make_shared<ChessGuiFactory>(); });
    serviceContainer->setFactory(typeid(ChessTimelineFactory).name(), []() { return std::make_shared<ChessTimelineFactory>(); });
    serviceContainer->setFactory(typeid(MainFactory).name(), []() { return std::make_shared<MainFactory>(); });
    serviceContainer->setFactory(typeid(MultiplayerGuiFactory).name(), []() { return std::make_shared<MultiplayerGuiFactory>(); });
    serviceContainer->setFactory(typeid(MultiplayerFactory).name(), []() { return std::make_shared<MultiplayerFactory>(); });
}

void ServiceRegistry::addFacades(Container *serviceContainer)
{
    serviceContainer->setFacade(typeid(ChessFacade).name(), []() { return std::make_shared<ChessFacade>(); });
    serviceContainer->setFacade(typeid(ChessGuiFacade).name(), []() { return std::make_shared<ChessGuiFacade>(); });
    serviceContainer->setFacade(typeid(ChessTimelineFacade).name(), []() { return std::make_shared<ChessTimelineFacade>(); });
    serviceContainer->setFacade(typeid(MultiplayerGuiFacade).name(), []() { return std::make_shared<MultiplayerGuiFacade>(); });
    serviceContainer->setFacade(typeid(MultiplayerFacade).name(), []() { return std::make_shared<MultiplayerFacade>(); });
}


