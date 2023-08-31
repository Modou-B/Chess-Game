//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"

std::string ChessFacade::test() {
    return "das ist ein Test";
}

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}
