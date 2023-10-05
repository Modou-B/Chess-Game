//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSSETTINGSRENDERER_H
#define CHESSAPPLICATION_CHESSSETTINGSRENDERER_H

class QColor;

class ChessSettingsRenderer {
private:
    static int selectedPlayer;
    static QColor player1Color;
    static QColor player2Color;

public:
    void createSettingsView();
    void onPressSettingsButton();
    void setChoosePlayer(int player);
    void setPlayerColor(QColor playerColor);
    QColor getColorForPlayer(int player);
};


#endif //CHESSAPPLICATION_CHESSSETTINGSRENDERER_H
