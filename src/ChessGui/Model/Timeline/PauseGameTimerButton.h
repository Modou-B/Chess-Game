//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_PAUSEGAMETIMERBUTTON_H
#define CHESSAPPLICATION_PAUSEGAMETIMERBUTTON_H

#include "../../../ChessTimeline/Reader/ChessTurnLogReader.h"
#include "QPushButton"

class ChessTimelineRenderer;
class ChessTimelineFacade;
class ChessGuiCellManager;

class PauseGameTimerButton: public QPushButton{
private:
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;

public:
    PauseGameTimerButton(
      ChessTimelineRenderer *chessTimelineRenderer,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager
    );

    void setPauseGameTimer();
};


#endif //CHESSAPPLICATION_PAUSEGAMETIMERBUTTON_H
