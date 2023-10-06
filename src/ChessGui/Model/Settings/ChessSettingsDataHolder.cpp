//
// Created by Julian Sommer on 06.10.23.
//

#include "ChessSettingsDataHolder.h"
#include "../../../Shared/ChessGui/ChessGuiConstants.h"

int ChessSettingsDataHolder::selectedPlayer = 1;
QColor ChessSettingsDataHolder::player1Color = ChessGuiConstants::CELL_YELLOW_COLOR;
QColor ChessSettingsDataHolder::player2Color = ChessGuiConstants::CELL_GREEN_COLOR;
QGridLayout *ChessSettingsDataHolder::chessGridPreviewLayout = nullptr;

void ChessSettingsDataHolder::setChoosePlayer(int player)
{
    ChessSettingsDataHolder::selectedPlayer = player;
}

void ChessSettingsDataHolder::setPlayerColor(QColor playerColor)
{
    if (ChessSettingsDataHolder::selectedPlayer == 1) {
        ChessSettingsDataHolder::player1Color = playerColor;
        return;
    }

    ChessSettingsDataHolder::player2Color = playerColor;
}

void ChessSettingsDataHolder::setChessGridPreviewLayout(QGridLayout *chessGridPreviewLayout)
{
    ChessSettingsDataHolder::chessGridPreviewLayout = chessGridPreviewLayout;
}

QColor ChessSettingsDataHolder::getColorForPlayer(int player)
{
    if (player == 1) {
        return ChessSettingsDataHolder::player1Color;
    }

    return ChessSettingsDataHolder::player2Color;
}

QGridLayout *ChessSettingsDataHolder::getChessGridPreviewLayout()
{
    return ChessSettingsDataHolder::chessGridPreviewLayout;
}
