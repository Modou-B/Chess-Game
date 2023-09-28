//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIRENDERER_H
#define CHESSAPPLICATION_CHESSGUIRENDERER_H

#include <string>

class QWidget;
class ChessFacade;
class ChessGuiPieceIconGenerator;
class QIcon;
class QListWidget;
class QApplication;
class QHBoxLayout;
class ChessGridLayout;

class ChessGuiRenderer {
private:
    ChessFacade *chessFacade;
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;
    int speedModeTimerValue;

protected:

    ChessGridLayout *createChessGridLayout(QWidget *mainWindow);

    void fillFieldWithEmptyCells(
            ChessGridLayout *layout,
            QHBoxLayout *hBoxChessPieceSelectionTop,
            QHBoxLayout *hBoxChessPieceSelectionBottom
    );

    void addPawnsToCells(ChessGridLayout *layout);
    void addQueensToCells(ChessGridLayout *layout);
    void addKingsToCells(ChessGridLayout *layout);
    void addBishopsToCells(ChessGridLayout *layout);
    void addKnightsToCells(ChessGridLayout *layout);
    void addRooksToCells(ChessGridLayout *layout);
    void addChessPieceToCells(ChessGridLayout *layout, std::string iconFileName, std::string pieceType, int column, int row);

public:
    ChessGuiRenderer(ChessFacade *chessFacade, ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator);

    void createChessField(QWidget *mainWindow);
    void createSettingsPage(QWidget *mainWindow);

    void onRewindButtonPress();
    void onPauseButtonPress();
    void onSkipButtonPress();
    static QListWidget *timelineList;
    void onPressStartButton(QWidget *mainWindow);
    void onPressSpeedButton(int speedModeTimerValue);

};


#endif //CHESSAPPLICATION_CHESSGUIRENDERER_H
