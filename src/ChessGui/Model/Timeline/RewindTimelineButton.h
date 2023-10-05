//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_REWINDTIMELINEBUTTON_H
#define CHESSAPPLICATION_REWINDTIMELINEBUTTON_H

#include "../../../ChessTimeline/Reader/ChessTurnLogReader.h"
#include "QPushButton"

class ChessTimelineRenderer;
class ChessTimelineFacade;
class ChessGuiCellManager;

class RewindTimelineButton: public QPushButton{
private:
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;

public:
    RewindTimelineButton(
      ChessTimelineRenderer *chessTimelineRenderer,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager
    );

    void setRewindTimeline();
};


#endif //CHESSAPPLICATION_REWINDTIMELINEBUTTON_H
