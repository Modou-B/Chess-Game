//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSSETTINGSRENDERER_H
#define CHESSAPPLICATION_CHESSSETTINGSRENDERER_H

class ChessGridRenderer;
class ChessSettingsDataHolder;
class QColor;

class ChessSettingsRenderer {
private:
    ChessGridRenderer *chessGridRenderer;
    ChessSettingsDataHolder *chessSettingsDataHolder;

public:
    ChessSettingsRenderer(
      ChessGridRenderer *chessGridRenderer,
      ChessSettingsDataHolder *chessSettingsDataHolder
    );

    void createSettingsView();

    void updateCellColors();

    void setPlayerToChooseColor(int player);
    void setColorForSetPlayer(QColor color);

    void saveCustomColor();
};


#endif //CHESSAPPLICATION_CHESSSETTINGSRENDERER_H
