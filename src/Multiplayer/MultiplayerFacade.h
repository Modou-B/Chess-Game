//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERFACADE_H
#define CHESSAPPLICATION_MULTIPLAYERFACADE_H

#include "../Application/Facade/AbstractFacade.h"
#include "MultiplayerFactory.h"

class QJsonObject;

class MultiplayerFacade: public AbstractFacade {
public:
    void initializeMultiplayerConnection();
    void sendJsonDataToServer(QJsonObject jsonData);
    QJsonObject requestJsonDataFromServer(QJsonObject jsonData);

    void startMultiplayerMatch();

    MultiplayerFactory *getFactory() override;
};

#endif // CHESSAPPLICATION_MULTIPLAYERFACADE_H
