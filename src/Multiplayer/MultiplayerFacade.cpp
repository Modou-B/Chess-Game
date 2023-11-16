//
// Created by Julian Sommer on 27.10.23.
//

#include "MultiplayerFacade.h"
#include "Client/ChessClientManager.h"
#include "Client/ChessClientResponseDelegator.h"
#include <QJsonObject>

void MultiplayerFacade::initializeMultiplayerConnection()
{
    MultiplayerFacade::getFactory()->createChessClientManager()->initializeChessClient(
          MultiplayerFacade::getFactory()->createChessClientResponseDelegator()
      );
}

void MultiplayerFacade::sendJsonDataToServer(QJsonObject jsonData) {
    MultiplayerFacade::getFactory()->createChessClientManager()->sendJsonData(jsonData);
}

QJsonObject MultiplayerFacade::requestJsonDataFromServer(QJsonObject jsonData) {
    return MultiplayerFacade::getFactory()->createChessClientManager()->requestJsonData(jsonData);
}

void MultiplayerFacade::startMultiplayerMatch()
{
    MultiplayerFacade::getFactory()->createChessClientManager()->handleMultiplayerLobbyJoin();
}

MultiplayerFactory *MultiplayerFacade::getFactory() {
    return static_cast<MultiplayerFactory*>(this->findFactory(typeid(MultiplayerFactory).name()));
}
