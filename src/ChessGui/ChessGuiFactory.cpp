//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiFactory.h"

ChessGuiRenderer *ChessGuiFactory::createChessGuiRenderer() {
    return new ChessGuiRenderer(this->getChessFacade(), this->createChessGuiPieceIconGenerator());
}

ChessFacade *ChessGuiFactory::getChessFacade() {
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}

ChessGuiPieceIconGenerator *ChessGuiFactory::createChessGuiPieceIconGenerator() {
    return new ChessGuiPieceIconGenerator();
}
