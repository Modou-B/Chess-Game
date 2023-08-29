//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_CHESSFACADE_H
#define CHESSAPPLICATION_CHESSFACADE_H

#include <string>
#include "../Application/Facade/AbstractFacade.h"
#include "ChessFactory.h"

class ChessFacade: public AbstractFacade {
public:
    std::string test();

    ChessFactory *getFactory() override;
};


#endif //CHESSAPPLICATION_CHESSFACADE_H
