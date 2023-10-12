//
// Created by Julian Sommer on 06.10.23.
//

#include "ChessSettingsDataHolder.h"
#include "../../../Shared/ChessGui/ChessGuiConstants.h"

int ChessSettingsDataHolder::selectedPlayer = 1;
QColor ChessSettingsDataHolder::player1Color = ChessGuiConstants::CELL_YELLOW_COLOR;
QColor ChessSettingsDataHolder::player2Color = ChessGuiConstants::CELL_GREEN_COLOR;
QColor ChessSettingsDataHolder::savedPlayer1Color = ChessGuiConstants::CELL_YELLOW_COLOR;
QColor ChessSettingsDataHolder::savedPlayer2Color = ChessGuiConstants::CELL_GREEN_COLOR;
QGridLayout *ChessSettingsDataHolder::chessGridPreviewLayout = nullptr;

void ChessSettingsDataHolder::setChoosePlayer(int player)
{
    ChessSettingsDataHolder::selectedPlayer = player;
}

void ChessSettingsDataHolder::setPlayerColor(QColor savedPlayerColor)
{
    if (ChessSettingsDataHolder::selectedPlayer == 1) {
        ChessSettingsDataHolder::savedPlayer1Color = savedPlayerColor;
        return;
    }

    ChessSettingsDataHolder::savedPlayer2Color = savedPlayerColor;
}

void ChessSettingsDataHolder::savePlayerColors() {
    ChessSettingsDataHolder::player1Color = ChessSettingsDataHolder::savedPlayer1Color;
    ChessSettingsDataHolder::player2Color = ChessSettingsDataHolder::savedPlayer2Color;
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

QColor ChessSettingsDataHolder::getPeviewColorForPlayer(int player)
{
    if (player == 1) {
        return ChessSettingsDataHolder::savedPlayer1Color;
    }

    return ChessSettingsDataHolder::savedPlayer2Color;
}

QGridLayout *ChessSettingsDataHolder::getChessGridPreviewLayout()
{
    return ChessSettingsDataHolder::chessGridPreviewLayout;
}
