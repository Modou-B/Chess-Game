//
// Created by modou on 03.11.2023.
//

#ifndef CHESSAPPLICATION_BACKTOMENU_H
#define CHESSAPPLICATION_BACKTOMENU_H

#include "QPushButton"
#include "ChessGuiFactory.h"
#include "../../../MainFacade.h"

class QColor;
class ChessGuiRenderer;
class ChessSettingsRenderer;
class QWidget;

class BackToMenu: public QPushButton{
private:
    ChessGuiRenderer *chessGuiRenderer;
    QWidget *mainWindow;
    ChessGuiFactory *chessGuiFactory;
public:
    BackToMenu(ChessGuiRenderer *chessGuiRenderer, QWidget *mainWindow);

    void goBackToMainMenu();
};


#endif //CHESSAPPLICATION_BACKTOMENU_H
