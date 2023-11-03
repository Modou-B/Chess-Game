//
// Created by Julian Sommer on 27.10.23.
//

#include "MultiplayerGuiFacade.h"
#include "MultiplayerGuiFactory.h"
#include "Model/MultiplayerGuiModelCreator.h"
#include "Renderer/Lobby/LobbyRenderer.h"

MultiplayerStartButton *MultiplayerGuiFacade::createMultiplayerStartButton() {
    return MultiplayerGuiFacade::getFactory()->createMultiplayerGuiModelCreator()->createMultiplayerStartButton();
}

QVBoxLayout *MultiplayerGuiFacade::createLobbyLayout() {
    return MultiplayerGuiFacade::getFactory()->createLobbyRenderer()->createMultiplayerLobbyLayout();
}

MultiplayerGuiFactory *MultiplayerGuiFacade::getFactory() {
    return static_cast<MultiplayerGuiFactory*>(this->findFactory(typeid(MultiplayerGuiFactory).name()));
}
