//
// Created by Julian Sommer on 06.09.23.
//

#include "ChessGuiCell.h"


ChessGuiCell::ChessGuiCell(QGridLayout *gridLayout, ChessFacade *chessFacade, std::pair<int, int> coordinates) {
    this->gridLayout = gridLayout;
    this->chessFacade = chessFacade;
    this->coordinates = coordinates;

    connect(this, &QPushButton::released, this, &ChessGuiCell::handleCellClick);
}

void ChessGuiCell::handleCellClick() {
    return;
}

Qt::GlobalColor ChessGuiCell::getCellColor() {
    return this->currentColor;
}

QGridLayout *ChessGuiCell::getGridLayout() {
    return this->gridLayout;
}

void ChessGuiCell::setBaseCellSize() {
    this->setMinimumSize(50,50);
    this->setMaximumSize(1000,1000);
}

void ChessGuiCell::setCellColor(Qt::GlobalColor color) {
    this->currentColor = color;

    QPalette pal = this->palette();

    pal.setColor(QPalette::Button, QColor(color));

    if (Qt::black == color) {
        pal.setColor(QPalette::ButtonText, QColor(Qt::white));
    }

    if (Qt::white == color) {
        pal.setColor(QPalette::ButtonText, QColor(Qt::black));
    }

    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}
