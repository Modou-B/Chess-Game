//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERFACTORY_H
#define CHESSAPPLICATION_MULTIPLAYERFACTORY_H

#include"../Application/Factory/AbstractFactory.h"
#include "../Multiplayer/Client/ChessClientResponseDelegator.h"

class ChessClientManager;
class ChessClientResponseDelegator;

class MultiplayerFactory: public AbstractFactory {
public:
    ChessClientManager *createChessClientManager();
    ChessClientResponseDelegator *createChessClientResponseDelegator();

    ChessFacade *getChessFacade();
    ChessGuiFacade *getChessGuiFacade();
};

#endif // CHESSAPPLICATION_MULTIPLAYERFACTORY_H
