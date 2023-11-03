//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERFACTORY_H
#define CHESSAPPLICATION_MULTIPLAYERFACTORY_H

#include"../Application/Factory/AbstractFactory.h"
#include "../Chess/ChessFacade.h"

class ChessClientManager;

class MultiplayerFactory: public AbstractFactory {
public:
    ChessClientManager *createChessClientManager();

    ChessFacade *getChessFacade();
};

#endif // CHESSAPPLICATION_MULTIPLAYERFACTORY_H
