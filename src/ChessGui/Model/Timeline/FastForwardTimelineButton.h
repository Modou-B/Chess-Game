//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_FASTFORWARDTIMELINEBUTTON_H
#define CHESSAPPLICATION_FASTFORWARDTIMELINEBUTTON_H


#include "QPushButton"

class ChessTimelineRenderer;
class ChessTimelineFacade;
class ChessGuiCellManager;

class FastForwardTimelineButton: public QPushButton{
private:
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;

public:
    FastForwardTimelineButton(
      ChessTimelineRenderer *chessTimelineRenderer,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager
    );

    void setFastForwardTimeline();
};

#endif //CHESSAPPLICATION_FASTFORWARDTIMELINEBUTTON_H
