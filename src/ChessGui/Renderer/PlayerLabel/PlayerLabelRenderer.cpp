//
// Created by Modou on 05.10.23.
//

#include "PlayerLabelRenderer.h"
#include "QLabel"
#include "PlayerLabel.h"
PlayerLabel *PlayerLabelRenderer::playerLabel1 = nullptr;
PlayerLabel *PlayerLabelRenderer::playerLabel2 = nullptr;

void PlayerLabelRenderer::createPlayerLabels() {
    PlayerLabelRenderer::playerLabel1 = new PlayerLabel();
    PlayerLabelRenderer::playerLabel1->setText("Player 1");


    PlayerLabelRenderer::playerLabel2 = new PlayerLabel();
    PlayerLabelRenderer::playerLabel2->setText("Player 2");
}

PlayerLabel *PlayerLabelRenderer::getPlayerLabel(int player) {
    if (player == 1) {
        return PlayerLabelRenderer::playerLabel1;
    }

    return PlayerLabelRenderer::playerLabel2;
}

void PlayerLabelRenderer::updatePlayerColor(int player) {
    if (player == 1) {
         PlayerLabelRenderer::playerLabel1->setCurrentPlayerColor();
        PlayerLabelRenderer::playerLabel2->removeCurrentPlayerColor();
        return;
    }
    PlayerLabelRenderer::playerLabel2->setCurrentPlayerColor();
    PlayerLabelRenderer::playerLabel1->removeCurrentPlayerColor();

}