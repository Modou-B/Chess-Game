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

    ChessGuiFactory *getFactory() override;
};


#endif //CHESSAPPLICATION_CHESSGUIFACADE_H
