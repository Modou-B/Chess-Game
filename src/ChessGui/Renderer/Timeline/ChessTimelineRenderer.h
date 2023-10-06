//
// Created by Julian Sommer on 04.10.23.
//

#ifndef CHESSAPPLICATION_CHESSTIMELINERENDERER_H
#define CHESSAPPLICATION_CHESSTIMELINERENDERER_H

#include <utility>
#include <string>

using namespace std;

class QListWidget;
class QHBoxLayout;
class ChessTimelineFacade;
class ChessGuiCellManager;
class ChessFacade;

class ChessTimelineRenderer {
private:
    static QListWidget *timelineList;
    static int selectedTurn;
    static int currentTurn;

public:
    QHBoxLayout *createHBoxChessTimelineLayout();
    QHBoxLayout *createHBoxTimelineButtonsLayout(
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager,
      ChessFacade *chessFacade
    );

    void addListWidgetItem(pair<int, int> currentCellCoordinates, string chessPieceType);

    int fastForwardTurn();
    int rewindTurn();

    int getCurrentTurn();
    int getSelectedTurn();

    void updateTurnProperties(int turn);

    void removeLastTurn();
};

#endif // CHESSAPPLICATION_CHESSTIMELINERENDERER_H
