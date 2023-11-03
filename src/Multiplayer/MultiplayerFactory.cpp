//
// Created by Julian Sommer on 27.10.23.
//

#include "MultiplayerFactory.h"
#include "Client/ChessClientManager.h"

ChessClientManager *MultiplayerFactory::createChessClientManager() {
    return new ChessClientManager(
      this->getChessFacade()
    );
}

ChessFacade *MultiplayerFactory::getChessFacade()
{
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}