//
// Created by Julian Sommer on 24.09.23.
//

#include "ChessTimer.h"
#include "QTimer"
#include "string"
#include "../../Chess/GameApplication/GameApplication.h"

ChessTimer::ChessTimer(int player, int speedModeTimerValue): QLCDNumber() {
    this->currentTime = speedModeTimerValue;
    this->currentPlayer = player;

    auto *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &ChessTimer::showTime);

    timer->start(1000);
}

void ChessTimer::showTime() {
    this->display(QString::fromStdString(std::to_string(this->currentTime)));
    if (this->currentPlayer == GameApplication::getCurrentPlayer()) {
        this->currentTime--;
    }
}
