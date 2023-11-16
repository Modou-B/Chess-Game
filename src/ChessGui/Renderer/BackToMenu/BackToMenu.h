//
// Created by modou on 03.11.2023.
//

#ifndef CHESSAPPLICATION_BACKTOMENU_H
#define CHESSAPPLICATION_BACKTOMENU_H

#include "QPushButton"
#include "../../../MainFacade.h"

class QColor;
class ChessGuiRenderer;
class ChessSettingsRenderer;
class QWidget;

class BackToMenu: public QPushButton{
private:
    QWidget *mainWindow;
public:
    BackToMenu(QWidget *mainWindow);

    void goBackToMainMenu();
};


#endif //CHESSAPPLICATION_BACKTOMENU_H
