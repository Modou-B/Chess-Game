//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiFacade.h"

void ChessGuiFacade::initializeChessField(QWidget *mainWindow) {
    ChessGuiFacade::getFactory()->createChessGuiRenderer()->createChessField(mainWindow);
}

ChessGuiFactory *ChessGuiFacade::getFactory() {
    return static_cast<ChessGuiFactory*>(this->findFactory(typeid(ChessGuiFactory).name()));
}
