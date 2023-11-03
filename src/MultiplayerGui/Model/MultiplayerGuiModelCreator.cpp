//
// Created by Julian Sommer on 28.10.23.
//

#include "MultiplayerGuiModelCreator.h"
#include "../../Application/Resolver/FactoryResolverTrait.h"
#include "../MultiplayerGuiFactory.h"
#include "Button/MultiplayerStartButton.h"
#include "Button/LobbyCreateButton.h"
#include "Button/RefreshLobbyButton.h"
#include "Button/LobbyJoinButton.h"

MultiplayerStartButton *MultiplayerGuiModelCreator::createMultiplayerStartButton()
{
    return new MultiplayerStartButton(
        this->getFactory()->getMultiPlayerFacade(),
        this->getFactory()->createLobbyRenderer()
    );
}

LobbyCreateButton *MultiplayerGuiModelCreator::createLobbyCreateButton()
{
    return new LobbyCreateButton(
        this->getFactory()->getMultiPlayerFacade(),
        this->getFactory()->createLobbyRenderer()
    );
}

RefreshLobbyButton *MultiplayerGuiModelCreator::createRefreshLobbyButton()
{
    return new RefreshLobbyButton(
        this->getFactory()->createLobbyRenderer()
    );
}

LobbyJoinButton *MultiplayerGuiModelCreator::createLobbyJoinButton(string userIdentifier)
{
    return new LobbyJoinButton(
        this->getFactory()->getMultiPlayerFacade(),
        userIdentifier
    );
}

MultiplayerGuiFactory *MultiplayerGuiModelCreator::getFactory()
{
    return static_cast<MultiplayerGuiFactory*>(FactoryResolverTrait::findFactory(typeid(MultiplayerGuiFactory).name()));
}