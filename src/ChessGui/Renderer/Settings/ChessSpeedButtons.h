//
// Created by Modou on 28.09.23.
//

#ifndef CHESSAPPLICATION_CHESSSPEEDBUTTONS_H
#define CHESSAPPLICATION_CHESSSPEEDBUTTONS_H

#include "QPushButton"

class ChessGuiRenderer;
class QWidget;

class ChessSpeedButtons: public QPushButton{
private:
    ChessGuiRenderer *chessGuiRenderer;
    int speedModeTimerValue;

public:
    ChessSpeedButtons(ChessGuiRenderer *chessGuiRenderer, int speedModeTimerValue);

    void setPlayMode();
};


#endif //CHESSAPPLICATION_CHESSSPEEDBUTTONS_H
