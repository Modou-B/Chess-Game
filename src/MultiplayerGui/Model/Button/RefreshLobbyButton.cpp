//
// Created by Julian Sommer on 01.11.23.
//

#include "RefreshLobbyButton.h"
#include "../../Renderer/Lobby/LobbyRenderer.h"

RefreshLobbyButton::RefreshLobbyButton(
    LobbyRenderer *lobbyRenderer
) {
    this->lobbyRenderer = lobbyRenderer;

    this->setText("Refresh Lobby");

    connect(this, &QPushButton::pressed, this, &RefreshLobbyButton::refreshLobbyData);
}

void RefreshLobbyButton::refreshLobbyData() {
    this->lobbyRenderer->refreshLobbyList();
}