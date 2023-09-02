//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_MAINFACTORY_H
#define CHESSAPPLICATION_MAINFACTORY_H

#include "Application/Factory/AbstractFactory.h"
#include "ChessGui/ChessGuiFacade.h"

class MainFactory: public AbstractFactory {
public:
    ChessGuiFacade *getChessGuiFacade();
};


#endif //CHESSAPPLICATION_MAINFACTORY_H
