//
// Created by Modou on 03.10.23.
//

#ifndef CHESSAPPLICATION_TURNTAKEBACKBUTTON_H
#define CHESSAPPLICATION_TURNTAKEBACKBUTTON_H

#include "../../../ChessTimeline/Reader/ChessTurnLogReader.h"
#include "QPushButton"

class ChessTimelineRenderer;
class ChessTimelineFacade;
class ChessGuiCellManager;
class ChessFacade;

class TurnTakeBackButton : public QPushButton{
private:
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;
    ChessFacade *chessFacade;

protected:
    void updateChessGridGui(
      ChessTurnLogTransfer *lastChessTurnLogTransfer,
      int currentTurn
    );

public:
    TurnTakeBackButton(
      ChessTimelineRenderer *chessTimelineRenderer,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager,
      ChessFacade *chessFacade
    );

    void takeBackTurn();
};


#endif // CHESSAPPLICATION_TURNTAKEBACKBUTTON_H
