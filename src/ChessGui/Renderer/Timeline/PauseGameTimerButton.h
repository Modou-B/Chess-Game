//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_PAUSEGAMETIMERBUTTON_H
#define CHESSAPPLICATION_PAUSEGAMETIMERBUTTON_H


#include "QPushButton"
#include "../ChessTimeline/Reader/ChessTurnLogReader.h"

class ChessGuiRenderer;
class QWidget;

class PauseGameTimerButton: public QPushButton{
private:
    ChessGuiRenderer *chessGuiRenderer;
    ChessTurnLogReader *chessTurnLogReader;
    int speedModeTimerValue;

public:
    PauseGameTimerButton(ChessGuiRenderer *chessGuiRenderer);

    void setPauseGameTimer();
};


#endif //CHESSAPPLICATION_PAUSEGAMETIMERBUTTON_H
