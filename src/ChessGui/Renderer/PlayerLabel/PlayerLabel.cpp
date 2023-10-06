//
// Created by Modou on 05.10.23.
//

#include "PlayerLabel.h"
#include "QPalette"

PlayerLabel::PlayerLabel(string labelText) {
    this->labelText = labelText;

    this->setText(QString::fromStdString(labelText));
}

void PlayerLabel::setCurrentPlayerColor() {
    this->setText(QString::fromStdString("<font color='red'>"+this->labelText+"</font>"));
}

void PlayerLabel::removeCurrentPlayerColor() {
    this->setText(QString::fromStdString("<font color='white'>"+this->labelText+"</font>"));
}