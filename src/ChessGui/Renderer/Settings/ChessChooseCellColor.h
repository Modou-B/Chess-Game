//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSCHOOSECELLCOLOR_H
#define CHESSAPPLICATION_CHESSCHOOSECELLCOLOR_H

#include "QPushButton"
class QColor;

class ChessSettingsRenderer;

class ChessChooseCellColor: public QPushButton{
private:
    QColor playerColor;
    ChessSettingsRenderer *chessSettingsRenderer;

public:
    ChessChooseCellColor(ChessSettingsRenderer *chessSettingsRenderer,QColor playerColor);

    void setColorForCell();
};


#endif //CHESSAPPLICATION_CHESSCHOOSECELLCOLOR_H
