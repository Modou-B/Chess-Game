//
// Created by Modou on 05.10.23.
//

#include "PlayerLabel.h"

#include "QPalette"

void PlayerLabel::setCurrentPlayerColor() {
    QPalette pal = this->palette();
    pal.setColor(this->foregroundRole(), Qt::red);
    this->setPalette(pal);
}

void PlayerLabel::removeCurrentPlayerColor() {
    QPalette pal = this->palette();
    pal.setColor(this->foregroundRole(), Qt::white);
    this->setPalette(pal);
}