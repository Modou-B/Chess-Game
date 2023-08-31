//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"
#include "iostream"


void ChessFacade::createChessField(QWidget *mainWindow) {
    ChessFacade::getFactory()->createChessCreator().createChessField(mainWindow);
}

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}