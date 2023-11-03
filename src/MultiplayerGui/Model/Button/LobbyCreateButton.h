//
// Created by Julian Sommer on 28.10.23.
//

#ifndef CHESSAPPLICATION_LOBBYCREATEBUTTON_H
#define CHESSAPPLICATION_LOBBYCREATEBUTTON_H

#include <QPushButton>

class MultiplayerFacade;
class LobbyRenderer;

class LobbyCreateButton: public QPushButton {
private:
    MultiplayerFacade *multiplayerFacade;
    LobbyRenderer *lobbyRenderer;

public:
    LobbyCreateButton(
        MultiplayerFacade *multiplayerFacade,
        LobbyRenderer *lobbyRenderer
    );

    void createLobby();
};

#endif // CHESSAPPLICATION_LOBBYCREATEBUTTON_H
