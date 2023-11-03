//
// Created by Julian Sommer on 28.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERGUIDATAHOLDER_H
#define CHESSAPPLICATION_MULTIPLAYERGUIDATAHOLDER_H

class QVBoxLayout;

class MultiplayerGuiDataHolder {
private:
    static QVBoxLayout *lobbyLayout;

public:
    void saveLobbyLayout(QVBoxLayout *lobbyLayout);
    QVBoxLayout *getLobbyLayout();
};

#endif // CHESSAPPLICATION_MULTIPLAYERGUIDATAHOLDER_H
