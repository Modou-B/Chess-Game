//
// Created by Julian Sommer on 02.11.23.
//

#include "LobbyJoinButton.h"
#include "../../../Multiplayer/MultiplayerFacade.h"
#include <QJsonObject>

LobbyJoinButton::LobbyJoinButton(
    MultiplayerFacade *multiplayerFacade,
    string userIdentifier
) {
    this->multiplayerFacade = multiplayerFacade;
    this->userIdentifier = userIdentifier;

    connect(this, &QPushButton::pressed, this, &LobbyJoinButton::joinLobby);
}

void LobbyJoinButton::joinLobby() {
    QJsonObject json;
    json[QStringLiteral("requestType")] = QStringLiteral("joinOpenLobby");
    json[QStringLiteral("opponentIdentifier")] = QString::fromStdString(this->userIdentifier);

    this->multiplayerFacade->sendJsonDataToServer(json);
}