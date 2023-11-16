//
// Created by Julian Sommer on 27.10.23.
//

#include "MultiplayerFactory.h"
#include "Client/ChessClientManager.h"
#include "Client/ChessClientResponseDelegator.h"
#include "../Chess/ChessFacade.h"
#include "../ChessGui/ChessGuiFacade.h"

ChessClientManager *MultiplayerFactory::createChessClientManager()
{
    return new ChessClientManager(
      this->getChessFacade()
    );
}

ChessClientResponseDelegator *MultiplayerFactory::createChessClientResponseDelegator()
{
    return new ChessClientResponseDelegator(
      this->getChessFacade(),
      this->getChessGuiFacade()
    );
}

ChessFacade *MultiplayerFactory::getChessFacade()
{
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}

ChessGuiFacade *MultiplayerFactory::getChessGuiFacade()
{
    return static_cast<ChessGuiFacade*>(this->findFacade(typeid(ChessGuiFacade).name()));
}