//
// Created by Julian Sommer on 28.10.23.
//

#include "LobbyCreateButton.h"
#include "../../../Multiplayer/MultiplayerFacade.h"
#include "../../Renderer/Lobby/LobbyRenderer.h"
#include <QJsonObject>

LobbyCreateButton::LobbyCreateButton(
    MultiplayerFacade *multiplayerFacade,
    LobbyRenderer *lobbyRenderer
) {
    this->multiplayerFacade = multiplayerFacade;
    this->lobbyRenderer = lobbyRenderer;

    this->setText("Create Lobby");

    connect(this, &QPushButton::pressed, this, &LobbyCreateButton::createLobby);
}

void LobbyCreateButton::createLobby()
{
    QJsonObject json;
    json[QStringLiteral("requestType")] = QStringLiteral("openLobby");

    this->multiplayerFacade->sendJsonDataToServer(json);

    this->lobbyRenderer->refreshLobbyList();
}