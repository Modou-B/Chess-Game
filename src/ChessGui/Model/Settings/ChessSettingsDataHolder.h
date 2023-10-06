//
// Created by Julian Sommer on 06.10.23.
//

#ifndef CHESSAPPLICATION_CHESSSETTINGSDATAHOLDER_H
#define CHESSAPPLICATION_CHESSSETTINGSDATAHOLDER_H

class QColor;
class QGridLayout;

class ChessSettingsDataHolder {
private:
    static int selectedPlayer;
    static QColor player1Color;
    static QColor player2Color;
    static QGridLayout *chessGridPreviewLayout;

public:
    void setChoosePlayer(int player);
    void setPlayerColor(QColor playerColor);
    void setChessGridPreviewLayout(QGridLayout *chessGridPreviewLayout);

    QColor getColorForPlayer(int player);
    QGridLayout *getChessGridPreviewLayout();
};

#endif // CHESSAPPLICATION_CHESSSETTINGSDATAHOLDER_H
