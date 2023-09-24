//
// Created by Julian Sommer on 24.09.23.
//

#include "ChessTimer.h"
#include "QTimer"
#include "string"

ChessTimer::ChessTimer(): QLCDNumber() {
    this->currentTime = 1000;

    auto *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &ChessTimer::showTime);

    timer->start(1000);
}

void ChessTimer::showTime() {
    this->display(QString::fromStdString(std::to_string(this->currentTime)));

    this->currentTime--;
}
