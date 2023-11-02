//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIFACTORY_H
#define CHESSAPPLICATION_CHESSGUIFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Renderer/ChessGuiRenderer.h"
#include "../Chess/ChessFacade.h"
#include "../MultiplayerGui/MultiplayerGuiFacade.h"
#include "../ChessTimeline/ChessTimelineFacade.h"
#include "Model/Generator/ChessGuiPieceIconGenerator.h"
#include "Renderer/ChessPieceSelection/ChessPieceSelectionRenderer.h"
#include "Model/ChessGuiCellManager.h"
#include "Renderer/Timeline/ChessTimelineRenderer.h"
#include "Renderer/PlayerLabel/PlayerLabelRenderer.h"
#include "Renderer/Settings/ChessSettingsRenderer.h"
#include "Renderer/ChessGrid/ChessGridRenderer.h"
#include "Model/Settings/ChessSettingsDataHolder.h"

class ChessGuiFactory: public AbstractFactory {
public:
    ChessGuiRenderer *createChessGuiRenderer();
    ChessPieceSelectionRenderer *createChessPieceSelectionRenderer();
    ChessTimelineRenderer *createChessTimelineRenderer();
    ChessGuiPieceIconGenerator *createChessGuiPieceIconGenerator();
    ChessGuiCellManager *createChessGuiCellManager();

    ChessFacade *getChessFacade();
    MultiplayerGuiFacade *getMultiplayerGuiFacade();

    ChessTimelineFacade *getChessTimelineFacade();
    PlayerLabelRenderer *createChessPlayerLabelRenderer();
    ChessSettingsRenderer *createChessSettingsRenderer();
    ChessGridRenderer *createChessGridRenderer();
    ChessSettingsDataHolder *createChessSettingsDataHolder();
};


#endif //CHESSAPPLICATION_CHESSGUIFACTORY_H
