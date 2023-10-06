//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIRENDERER_H
#define CHESSAPPLICATION_CHESSGUIRENDERER_H

#include <string>

class QWidget;
class ChessFacade;
class ChessTimelineFacade;
class QIcon;
class QListWidget;
class QApplication;
class QHBoxLayout;
class QGridLayout;
class ChessPieceSelectionRenderer;
class ChessTimelineRenderer;
class ChessGuiCellManager;
class PlayerLabelRenderer;
class ChessSettingsRenderer;
class ChessGridRenderer;

class ChessGuiRenderer {
private:
    ChessFacade *chessFacade;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer;
    ChessTimelineRenderer *chessTimelineRenderer;
    PlayerLabelRenderer *playerLabelRenderer;
    ChessSettingsRenderer *chessSettingsRenderer;
    ChessGridRenderer *chessGridRenderer;

    int speedModeTimerValue;

protected:
    void createChessPieceSelectionHBoxes();

public:
    ChessGuiRenderer(
      ChessFacade *chessFacade,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager,
      ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
      ChessTimelineRenderer *chessTimelineRenderer,
      PlayerLabelRenderer *playerLabelRenderer,
      ChessSettingsRenderer *chessSettingsRenderer,
      ChessGridRenderer *chessGridRenderer
    );

    void createChessField(QWidget *mainWindow);
    void createSettingsPage(QWidget *mainWindow);

    void onPressStartButton(QWidget *mainWindow);
    void onPressSpeedButton(int speedModeTimerValue);

};


#endif //CHESSAPPLICATION_CHESSGUIRENDERER_H
