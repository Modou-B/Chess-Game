//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSSETTINGSBUTTON_H
#define CHESSAPPLICATION_CHESSSETTINGSBUTTON_H


#include "QPushButton"

class ChessGuiRenderer;
class QWidget;
class ChessSettingsRenderer;

class ChessSettingsButton: public QPushButton{
private:
    ChessSettingsRenderer *chessSettingsRenderer;

public:
    ChessSettingsButton();

    void openSettings();
};


#endif //CHESSAPPLICATION_CHESSSETTINGSBUTTON_H
