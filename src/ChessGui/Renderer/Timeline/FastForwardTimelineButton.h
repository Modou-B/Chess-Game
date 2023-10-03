//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_FASTFORWARDTIMELINEBUTTON_H
#define CHESSAPPLICATION_FASTFORWARDTIMELINEBUTTON_H


#include "QPushButton"

class ChessGuiRenderer;
class QWidget;

class FastForwardTimelineButton: public QPushButton{
private:
    ChessGuiRenderer *chessGuiRenderer;
    int speedModeTimerValue;

public:
    FastForwardTimelineButton(ChessGuiRenderer *chessGuiRenderer);

    void setFastForwardTimeline();
};

#endif //CHESSAPPLICATION_FASTFORWARDTIMELINEBUTTON_H
