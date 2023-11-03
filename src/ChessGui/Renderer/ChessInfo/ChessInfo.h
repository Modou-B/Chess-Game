//
// Created by modou on 03.11.2023.
//

#ifndef CHESSAPPLICATION_CHESSINFO_H
#define CHESSAPPLICATION_CHESSINFO_H


#include "QPushButton"
#include "QUrl"
#include "QDesktopServices"

class QColor;

class ChessInfo: public QPushButton{
private:

public:
    ChessInfo();

    void getChessInfo();
};

#endif //CHESSAPPLICATION_CHESSINFO_H
