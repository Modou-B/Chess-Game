//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_MAINFACTORY_H
#define CHESSAPPLICATION_MAINFACTORY_H

#include "Application/Factory/AbstractFactory.h"
#include "Chess/ChessFacade.h"

class MainFactory: public AbstractFactory {
public:
    ChessFacade *getChessFacade();
};


#endif //CHESSAPPLICATION_MAINFACTORY_H
