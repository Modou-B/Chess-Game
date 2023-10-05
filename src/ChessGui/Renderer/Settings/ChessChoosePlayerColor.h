//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSCHOOSEPLAYERCOLOR_H
#define CHESSAPPLICATION_CHESSCHOOSEPLAYERCOLOR_H

#include "QPushButton"
class QColor;

class ChessSettingsRenderer;

class ChessChoosePlayerColor: public QPushButton{
private:
    int player;
    ChessSettingsRenderer *chessSettingsRenderer;
public:
    ChessChoosePlayerColor(ChessSettingsRenderer *chessSettingsRenderer,int player);

    void setActivePlayerToChooseColorFor();
};


#endif //CHESSAPPLICATION_CHESSCHOOSEPLAYERCOLOR_H
