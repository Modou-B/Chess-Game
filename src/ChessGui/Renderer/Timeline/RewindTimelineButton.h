//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_REWINDTIMELINEBUTTON_H
#define CHESSAPPLICATION_REWINDTIMELINEBUTTON_H

#include "QPushButton"
#include "../ChessTimeline/Reader/ChessTurnLogReader.h"

class ChessGuiRenderer;
class QWidget;

class RewindTimelineButton: public QPushButton{
private:
    ChessGuiRenderer *chessGuiRenderer;
    ChessTurnLogReader *chessTurnLogReader;
    int speedModeTimerValue;

public:
    RewindTimelineButton(ChessGuiRenderer *chessGuiRenderer);

    void setRewindTimeline();
};


#endif //CHESSAPPLICATION_REWINDTIMELINEBUTTON_H
