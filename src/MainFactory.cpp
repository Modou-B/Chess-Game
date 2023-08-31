//
// Created by Julian Sommer on 27.08.23.
//

#include "MainFactory.h"
#include "Chess/ChessFacade.h"
#include "iostream"

ChessFacade *MainFactory::getChessFacade() {
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}
