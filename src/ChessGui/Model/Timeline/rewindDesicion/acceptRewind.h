//
// Created by mberlemann on 16.11.2023.
//

#ifndef CHESSAPPLICATION_ACCEPTREWIND_H
#define CHESSAPPLICATION_ACCEPTREWIND_H

#include "QPushButton"

class QColor;
class ChessGuiRenderer;
class ChessSettingsRenderer;
class QWidget;
class ChessTimelineRenderer;
class ChessTimelineFacade;
class ChessGuiCellManager;
class TurnTakeBackButton;
class ChessFacade;


class acceptRewind: public QPushButton{
private:
    QWidget *checkmateWindow;
    QWidget *waitingWindow;
    bool isCheckmate;
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;
    TurnTakeBackButton *turnTakeBackButton;
    ChessFacade *chessFacade;
public:
    acceptRewind(QWidget *checkmateWindow,QWidget *waitingWindow,bool isCheckmate, ChessTimelineRenderer *chessTimelineRenderer, ChessTimelineFacade *chessTimelineFacade, ChessGuiCellManager *chessGuiCellManager, TurnTakeBackButton *turnTakeBackButton, ChessFacade *chessFacade);

    void accept();
};


#endif //CHESSAPPLICATION_ACCEPTREWIND_H
