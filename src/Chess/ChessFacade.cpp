//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"
#include "Model/ChessCell.h"

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}

void ChessFacade::initiateChessGame() {
    ChessFacade::getFactory()->createGameApplicationManager()->initiateChessApplication();
}
