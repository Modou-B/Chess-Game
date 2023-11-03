//
// Created by Julian Sommer on 28.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERGUIMODELCREATOR_H
#define CHESSAPPLICATION_MULTIPLAYERGUIMODELCREATOR_H

#include <string>

using namespace std;

class MultiplayerStartButton;
class LobbyCreateButton;
class RefreshLobbyButton;
class MultiplayerGuiFactory;
class LobbyJoinButton;

class MultiplayerGuiModelCreator {
protected:
    MultiplayerGuiFactory *getFactory();

public:
    MultiplayerStartButton *createMultiplayerStartButton();
    LobbyCreateButton *createLobbyCreateButton();
    RefreshLobbyButton *createRefreshLobbyButton();
    LobbyJoinButton *createLobbyJoinButton(string userIdentifier);
};

#endif // CHESSAPPLICATION_MULTIPLAYERGUIMODELCREATOR_H
