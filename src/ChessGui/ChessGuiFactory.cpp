//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiFactory.h"

ChessGuiRenderer *ChessGuiFactory::createChessGuiRenderer() {
    return new ChessGuiRenderer(this->getChessFacade());
}

ChessFacade *ChessGuiFactory::getChessFacade() {
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}

