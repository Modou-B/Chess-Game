//
// Created by Modou on 28.09.23.
//

#ifndef CHESSAPPLICATION_CHESSSTARTBUTTON_H
#define CHESSAPPLICATION_CHESSSTARTBUTTON_H

#include "QPushButton"

class ChessGuiRenderer;
class QWidget;

class ChessStartButton: public QPushButton{
private:
    ChessGuiRenderer *chessGuiRenderer;
    QWidget *mainWindow;

public:
    ChessStartButton(ChessGuiRenderer *chessGuiRenderer, QWidget *mainWindow);

    void startGame();
};


#endif //CHESSAPPLICATION_CHESSSTARTBUTTON_H
