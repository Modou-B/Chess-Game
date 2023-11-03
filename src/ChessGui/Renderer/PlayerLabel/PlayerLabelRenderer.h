//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_PLAYERLABELRENDERER_H
#define CHESSAPPLICATION_PLAYERLABELRENDERER_H

class PlayerLabel;
class MultiplayerChessGuiTransfer;

class PlayerLabelRenderer {
private:
    static PlayerLabel *playerLabel1;
    static PlayerLabel *playerLabel2;

public:
    void createPlayerLabels();
    PlayerLabel *getPlayerLabel(int player);
    void updatePlayerColor(int player);

    void updateLabelTextsWithUsername(
        MultiplayerChessGuiTransfer *multiplayerChessGuiTransfer
    );
};


#endif //CHESSAPPLICATION_PLAYERLABELRENDERER_H
