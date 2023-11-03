//
// Created by Julian Sommer on 28.10.23.
//

#include "MultiplayerGuiDataHolder.h"
#include <QVBoxLayout>

QVBoxLayout *MultiplayerGuiDataHolder::lobbyLayout = nullptr;

void MultiplayerGuiDataHolder::saveLobbyLayout(QVBoxLayout *lobbyLayout) {
    MultiplayerGuiDataHolder::lobbyLayout = lobbyLayout;
}

QVBoxLayout *MultiplayerGuiDataHolder::getLobbyLayout() {
    return MultiplayerGuiDataHolder::lobbyLayout;
}