//
// Created by Julian Sommer on 27.08.23.
//

#include "MainFactory.h"

ChessGuiFacade *MainFactory::getChessGuiFacade() {
    return static_cast<ChessGuiFacade*>(this->findFacade(typeid(ChessGuiFacade).name()));
}

ChessFacade *MainFactory::getChessFacade() {
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}