//
// Created by mberlemann on 16.11.2023.
//

#ifndef CHESSAPPLICATION_DECLINEREWIND_H
#define CHESSAPPLICATION_DECLINEREWIND_H


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


class declineRewind: public QPushButton{
private:
    QWidget *acceptWindow;
    QWidget *waitingWindow;
public:
    declineRewind(QWidget *acceptWindow, QWidget *waitingWindow);

    void decline();
};

#endif //CHESSAPPLICATION_DECLINEREWIND_H
