//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiFactory.h"

ChessGuiRenderer *ChessGuiFactory::createChessGuiRenderer() {
    return new ChessGuiRenderer(
        this->getChessFacade(),
        this->getChessTimelineFacade(),
        this->createChessGuiCellManager(),
        this->createChessPieceSelectionRenderer(),
        this->createChessTimelineRenderer(),
        this->createChessPlayerLabelRenderer(),
        this->createChessSettingsRenderer(),
        this->createChessGridRenderer()
    );
}

ChessPieceSelectionRenderer *ChessGuiFactory::createChessPieceSelectionRenderer() {
    return new ChessPieceSelectionRenderer(
        this->createChessGuiPieceIconGenerator()
    );
}

ChessTimelineRenderer *ChessGuiFactory::createChessTimelineRenderer() {
    return new ChessTimelineRenderer();
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

ChessTimelineFacade *ChessGuiFactory::getChessTimelineFacade() {
    return static_cast<ChessTimelineFacade*>(this->findFacade(typeid(ChessTimelineFacade).name()));
}

PlayerLabelRenderer *ChessGuiFactory::createChessPlayerLabelRenderer() {
    return new PlayerLabelRenderer();
}

ChessSettingsRenderer *ChessGuiFactory::createChessSettingsRenderer() {
    return new ChessSettingsRenderer(
      this->createChessGridRenderer(),
      this->createChessSettingsDataHolder()
    );
}

ChessGridRenderer *ChessGuiFactory::createChessGridRenderer()
{
    return new ChessGridRenderer(
        this->getChessFacade(),
        this->createChessPieceSelectionRenderer(),
        this->createChessTimelineRenderer(),
        this->createChessGuiPieceIconGenerator(),
        this->createChessSettingsDataHolder()
    );
}

ChessSettingsDataHolder *ChessGuiFactory::createChessSettingsDataHolder()
{
    return new ChessSettingsDataHolder();
}