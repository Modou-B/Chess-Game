//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_CHESSFACTORY_H
#define CHESSAPPLICATION_CHESSFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "ChessCreator/ChessCreator.h"

class ChessFactory: public AbstractFactory {
public:
    ChessCreator createChessCreator();
};


#endif //CHESSAPPLICATION_CHESSFACTORY_H
