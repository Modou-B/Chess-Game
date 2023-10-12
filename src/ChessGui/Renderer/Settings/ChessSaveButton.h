//
// Created by Modou on 12.10.23.
//

#ifndef CHESSAPPLICATION_CHESSSAVEBUTTON_H
#define CHESSAPPLICATION_CHESSSAVEBUTTON_H


#include "QPushButton"
class ChessGuiRenderer;
class ChessChooseCellColor;
class ChessSettingsRenderer;
class QWidget;

class ChessSaveButton: public QPushButton{
private:
    ChessSettingsRenderer *chessSettingsRenderer;
    QWidget *settingsWindow;

public:
    ChessSaveButton(ChessSettingsRenderer *chessSettingsRenderer, QWidget *settingsWindow);

    void saveSettings();
    void setSavedPlayerColorToPlayerColor();
};


#endif //CHESSAPPLICATION_CHESSSAVEBUTTON_H
