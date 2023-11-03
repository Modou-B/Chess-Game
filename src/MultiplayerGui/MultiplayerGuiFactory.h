//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERGUIFACTORY_H
#define CHESSAPPLICATION_MULTIPLAYERGUIFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "../Multiplayer/MultiplayerFacade.h"

class MultiplayerGuiModelCreator;
class LobbyRenderer;
class MultiplayerGuiDataHolder;

class MultiplayerGuiFactory : public AbstractFactory {
public:
    MultiplayerGuiModelCreator *createMultiplayerGuiModelCreator();
    LobbyRenderer *createLobbyRenderer();
    MultiplayerGuiDataHolder *createMultiplayerGuiDataHolder();

    MultiplayerFacade *getMultiPlayerFacade();
};

#endif // CHESSAPPLICATION_MULTIPLAYERGUIFACTORY_H
