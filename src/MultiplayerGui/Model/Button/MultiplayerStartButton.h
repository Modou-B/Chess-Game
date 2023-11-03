//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERSTARTBUTTON_H
#define CHESSAPPLICATION_MULTIPLAYERSTARTBUTTON_H

#include <QPushButton>

using namespace std;

class MultiplayerFacade;
class LobbyRenderer;
class QJsonObject;

class MultiplayerStartButton: public QPushButton {
private:
    MultiplayerFacade *multiplayerFacade;
    LobbyRenderer *lobbyRenderer;

protected:
    void sendUsernameRequest();

public:
    MultiplayerStartButton(
        MultiplayerFacade *multiplayerFacade,
        LobbyRenderer *lobbyRenderer
    );

    void connectToServer();
};

#endif // CHESSAPPLICATION_MULTIPLAYERSTARTBUTTON_H
