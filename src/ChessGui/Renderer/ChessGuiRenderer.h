//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIRENDERER_H
#define CHESSAPPLICATION_CHESSGUIRENDERER_H

#include <string>

class QWidget;
class ChessFacade;
class ChessTimelineFacade;
class ChessGuiPieceIconGenerator;
class QIcon;
class QListWidget;
class QApplication;
class QHBoxLayout;
class QGridLayout;
class ChessPieceSelectionRenderer;
class ChessTimelineRenderer;
class ChessGuiCellManager;

class ChessGuiRenderer {
private:
    ChessFacade *chessFacade;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiCellManager *chessGuiCellManager;
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer;
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;
    int speedModeTimerValue;

protected:
    void fillFieldWithEmptyCells(QGridLayout *layout);

    void addPawnsToCells(QGridLayout *layout);
    void addQueensToCells(QGridLayout *layout);
    void addKingsToCells(QGridLayout *layout);
    void addBishopsToCells(QGridLayout *layout);
    void addKnightsToCells(QGridLayout *layout);
    void addRooksToCells(QGridLayout *layout);
    void addChessPieceToCells(QGridLayout *layout, std::string iconFileName, std::string pieceType, int column, int row);

    void createChessPieceSelectionHBoxes();
    void createChessTimelineLayout();
public:
    ChessGuiRenderer(
      ChessFacade *chessFacade,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiCellManager *chessGuiCellManager,
      ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
      ChessTimelineRenderer *chessTimelineRenderer,
      ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator
    );

    void createChessField(QWidget *mainWindow);
    void createSettingsPage(QWidget *mainWindow);

    void onPressStartButton(QWidget *mainWindow);
    void onPressSpeedButton(int speedModeTimerValue);

};


#endif //CHESSAPPLICATION_CHESSGUIRENDERER_H
