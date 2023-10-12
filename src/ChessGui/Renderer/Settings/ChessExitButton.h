//
// Created by Modou on 12.10.23.
//

#ifndef CHESSAPPLICATION_CHESSEXITBUTTON_H
#define CHESSAPPLICATION_CHESSEXITBUTTON_H


#include "QPushButton"
class ChessGuiRenderer;
class ChessChooseCellColor;
class ChessSettingsRenderer;
class QWidget;

class ChessExitButton: public QPushButton{
private:
    ChessSettingsRenderer *chessSettingsRenderer;
    QWidget *settingsWindow;

public:
    ChessExitButton(ChessSettingsRenderer *chessSettingsRenderer, QWidget *settingsWindow);

    void exitWindow();

};


#endif //CHESSAPPLICATION_CHESSEXITBUTTON_H
