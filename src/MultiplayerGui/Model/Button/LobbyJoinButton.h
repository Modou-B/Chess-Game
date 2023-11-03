//
// Created by Julian Sommer on 02.11.23.
//

#ifndef CHESSAPPLICATION_LOBBYJOINBUTTON_H
#define CHESSAPPLICATION_LOBBYJOINBUTTON_H

#include <QPushButton>

using namespace std;

class MultiplayerFacade;

class LobbyJoinButton: public QPushButton  {
private:
    MultiplayerFacade *multiplayerFacade;
    string userIdentifier;

public:
    LobbyJoinButton(
        MultiplayerFacade *multiplayerFacade,
        string userIdentifier
    );

    void joinLobby();
};

#endif // CHESSAPPLICATION_LOBBYJOINBUTTON_H
