//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIFACTORY_H
#define CHESSAPPLICATION_CHESSGUIFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Renderer/ChessGuiRenderer.h"
#include "../Chess/ChessFacade.h"
#include "Model/Generator/ChessGuiPieceIconGenerator.h"

class ChessGuiFactory: public AbstractFactory {
public:
    ChessGuiRenderer *createChessGuiRenderer();
    ChessGuiPieceIconGenerator *createChessGuiPieceIconGenerator();

    ChessFacade *getChessFacade();
};


#endif //CHESSAPPLICATION_CHESSGUIFACTORY_H
