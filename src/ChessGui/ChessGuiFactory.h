//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIFACTORY_H
#define CHESSAPPLICATION_CHESSGUIFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Renderer/ChessGuiRenderer.h"
#include "../Chess/ChessFacade.h"
#include "../ChessTimeline/ChessTimelineFacade.h"
#include "Model/Generator/ChessGuiPieceIconGenerator.h"
#include "Renderer/ChessPieceSelection/ChessPieceSelectionRenderer.h"
#include "Model/ChessGuiCellManager.h"
#include "Renderer/Timeline/ChessTimelineRenderer.h"

class ChessGuiFactory: public AbstractFactory {
public:
    ChessGuiRenderer *createChessGuiRenderer();
    ChessPieceSelectionRenderer *createChessPieceSelectionRenderer();
    ChessTimelineRenderer *createChessTimelineRenderer();
    ChessGuiPieceIconGenerator *createChessGuiPieceIconGenerator();
    ChessGuiCellManager *createChessGuiCellManager();

    ChessFacade *getChessFacade();
    ChessTimelineFacade *getChessTimelineFacade();
};


#endif //CHESSAPPLICATION_CHESSGUIFACTORY_H
