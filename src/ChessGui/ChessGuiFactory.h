//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIFACTORY_H
#define CHESSAPPLICATION_CHESSGUIFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Renderer/ChessGuiRenderer.h"
#include "../Chess/ChessFacade.h"
#include "Model/Generator/ChessGuiPieceIconGenerator.h"
#include "Renderer/ChessPieceSelection/ChessPieceSelectionRenderer.h"
#include "Model/ChessGuiCellManager.h"

class ChessGuiFactory: public AbstractFactory {
public:
    ChessGuiRenderer *createChessGuiRenderer();
    ChessPieceSelectionRenderer *createChessPieceSelectionRenderer();
    ChessGuiPieceIconGenerator *createChessGuiPieceIconGenerator();
    ChessGuiCellManager *createChessGuiCellManager();

    ChessFacade *getChessFacade();
};


#endif //CHESSAPPLICATION_CHESSGUIFACTORY_H
