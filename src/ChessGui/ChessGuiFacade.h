//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIFACADE_H
#define CHESSAPPLICATION_CHESSGUIFACADE_H

#include "../Application/Facade/AbstractFacade.h"
#include "ChessGuiFactory.h"

class QWidget;
class QApplication;

class ChessGuiFacade: public AbstractFacade {
public:
    void initializeSettingsPage(QWidget *mainWindow);

    void initializeChessField(QWidget *mainWindow);

    void handlePawnPieceSwitch(
      pair<int, int> chessGuiCellCoordinate,
      string pieceTypeToSwitch
    );

    void updateTimelineTurnProperties(int currentTurn);

    ChessGuiFactory *getFactory() override;
};


#endif //CHESSAPPLICATION_CHESSGUIFACADE_H
