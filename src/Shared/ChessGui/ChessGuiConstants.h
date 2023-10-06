//
// Created by Julian Sommer on 10.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUICONSTANTS_H
#define CHESSAPPLICATION_CHESSGUICONSTANTS_H

#include <QColor>
#include <string>

namespace ChessGuiConstants
{
    const QColor CELL_YELLOW_COLOR = QColor(255, 250, 225);
    const QColor CELL_GREEN_COLOR = QColor(23, 87, 23);
    const QColor CELL_BLACK_COLOR = QColor(0,0,0,120);

    const QColor CELL_RED_COLOR = QColor(255,0,0);

    const std::string STATE_REAL_CHESS_PIECE_ICON = "STATE_REAL_CHESS_PIECE_ICON";
    const std::string STATE_PREVIEW_CHESS_PIECE_ICON = "STATE_PREVIEW_CHESS_PIECE_ICON";
    const std::string STATE_EMPTY_CHESS_PIECE_ICON = "STATE_EMPTY_CHESS_PIECE_ICON";
}

#endif //CHESSAPPLICATION_CHESSGUICONSTANTS_H
