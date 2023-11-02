//
// Created by Julian Sommer on 01.11.23.
//

#ifndef CHESSAPPLICATION_REFRESHLOBBYBUTTON_H
#define CHESSAPPLICATION_REFRESHLOBBYBUTTON_H

#include <QPushButton>

class LobbyRenderer;

class RefreshLobbyButton: public QPushButton {
private:
    LobbyRenderer *lobbyRenderer;

public:
    RefreshLobbyButton(
        LobbyRenderer *lobbyRenderer
    );

    void refreshLobbyData();
};

#endif // CHESSAPPLICATION_REFRESHLOBBYBUTTON_H
