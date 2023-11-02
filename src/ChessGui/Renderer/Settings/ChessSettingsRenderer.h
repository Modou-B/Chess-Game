//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSSETTINGSRENDERER_H
#define CHESSAPPLICATION_CHESSSETTINGSRENDERER_H

class ChessGridRenderer;
class ChessSettingsDataHolder;
class QColor;
class QWidget;

class ChessSettingsRenderer {
private:
    ChessGridRenderer *chessGridRenderer;
    ChessSettingsDataHolder *chessSettingsDataHolder;
    static QWidget *settingsWindow;

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

    void setSettingsWindow(QWidget *settingsWindow);
    void closeSettingsWindow();
};


#endif //CHESSAPPLICATION_CHESSSETTINGSRENDERER_H
