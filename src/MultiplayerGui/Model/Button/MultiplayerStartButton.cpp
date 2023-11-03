//
// Created by Julian Sommer on 27.10.23.
//

#include "MultiplayerStartButton.h"
#include "../../../Multiplayer/MultiplayerFacade.h"
#include "../../Renderer/Lobby/LobbyRenderer.h"
#include <QJsonObject>

MultiplayerStartButton::MultiplayerStartButton(
    MultiplayerFacade *multiplayerFacade,
    LobbyRenderer *lobbyRenderer
) {
    this->multiplayerFacade = multiplayerFacade;
    this->lobbyRenderer = lobbyRenderer;

    this->setText("Multiplayer");

    connect(this, &QPushButton::pressed, this, &MultiplayerStartButton::connectToServer);
}

void MultiplayerStartButton::connectToServer()
{
    this->multiplayerFacade->initializeMultiplayerConnection();

    this->sendUsernameRequest();

    this->lobbyRenderer->showMultiplayerLobby();
    this->lobbyRenderer->refreshLobbyList();
}

void MultiplayerStartButton::sendUsernameRequest() {
    auto username = this->lobbyRenderer->showUsernameDialog(this);

    QJsonObject json;
    json[QStringLiteral("requestType")] = QStringLiteral("setUsername");
    json[QStringLiteral("username")] = username;

    this->multiplayerFacade->sendJsonDataToServer(json);
}