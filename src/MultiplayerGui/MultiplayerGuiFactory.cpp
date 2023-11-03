//
// Created by Julian Sommer on 27.10.23.
//

#include "MultiplayerGuiFactory.h"
#include "Model/MultiplayerGuiModelCreator.h"
#include "Renderer/Lobby/LobbyRenderer.h"
#include "Renderer/DataHolder/MultiplayerGuiDataHolder.h"

MultiplayerGuiModelCreator *MultiplayerGuiFactory::createMultiplayerGuiModelCreator() {
    return new MultiplayerGuiModelCreator();
}

LobbyRenderer *MultiplayerGuiFactory::createLobbyRenderer() {
    return new LobbyRenderer(
      this->createMultiplayerGuiDataHolder(),
      this->getMultiPlayerFacade(),
      this->createMultiplayerGuiModelCreator()
    );
}

MultiplayerGuiDataHolder *MultiplayerGuiFactory::createMultiplayerGuiDataHolder() {
    return new MultiplayerGuiDataHolder();
}

MultiplayerFacade *MultiplayerGuiFactory::getMultiPlayerFacade()
{
    return static_cast<MultiplayerFacade*>(this->findFacade(typeid(MultiplayerFacade).name()));
}