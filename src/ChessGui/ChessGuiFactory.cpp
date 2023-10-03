//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiFactory.h"

ChessGuiRenderer *ChessGuiFactory::createChessGuiRenderer() {
    return new ChessGuiRenderer(
        this->getChessFacade(),
        this->createChessGuiCellManager(),
        this->createChessPieceSelectionRenderer(),
        this->createChessGuiPieceIconGenerator()
    );
}

ChessPieceSelectionRenderer *ChessGuiFactory::createChessPieceSelectionRenderer() {
    return new ChessPieceSelectionRenderer(
        this->createChessGuiPieceIconGenerator()
    );
}

ChessGuiPieceIconGenerator *ChessGuiFactory::createChessGuiPieceIconGenerator() {
    return new ChessGuiPieceIconGenerator();
}

ChessGuiCellManager *ChessGuiFactory::createChessGuiCellManager() {
    return new ChessGuiCellManager();
}

ChessFacade *ChessGuiFactory::getChessFacade() {
    return static_cast<ChessFacade*>(this->findFacade(typeid(ChessFacade).name()));
}
