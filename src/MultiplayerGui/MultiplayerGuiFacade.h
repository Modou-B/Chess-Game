//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERGUIFACADE_H
#define CHESSAPPLICATION_MULTIPLAYERGUIFACADE_H

#include "../Application/Facade/AbstractFacade.h"
#include "MultiplayerGuiFactory.h"

class MultiplayerStartButton;
class QVBoxLayout;

class MultiplayerGuiFacade: public AbstractFacade {
public:
    MultiplayerStartButton *createMultiplayerStartButton();
    QVBoxLayout *createLobbyLayout();

    MultiplayerGuiFactory *getFactory() override;
};

#endif // CHESSAPPLICATION_MULTIPLAYERGUIFACADE_H
