//
// Created by Julian Sommer on 06.09.23.
//

#include "ChessGuiCell.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Chess/ChessFacade.h"
#include "QGridLayout"
#include "QString"
#include "iostream"

ChessGuiCell::ChessGuiCell(QGridLayout *gridLayout, ChessFacade *chessFacade, std::pair<int, int> coordinates) {
    this->gridLayout = gridLayout;
    this->chessFacade = chessFacade;
    this->coordinates = coordinates;

    connect(this, &QPushButton::released, this, &ChessGuiCell::handleCellClick);
}

void ChessGuiCell::handleCellClick() {
    ChessMovementResponseTransfer chessMovementResponseTransfer = this->chessFacade->handleChessMovement(this->coordinates);

    if (!chessMovementResponseTransfer.wasPieceMoved()) {
        return;
    }

    this->handleChessPieceMovement(chessMovementResponseTransfer);
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

void ChessGuiCell::setCellColor(QColor color) {
    QPalette pal = this->palette();

    pal.setColor(QPalette::Button, color);

    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}

void ChessGuiCell::handleChessPieceMovement(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    std::pair<int, int> previousGuiCellCoordinates = chessMovementResponseTransfer.getPreviousCellCoordinates();

    ChessGuiCell *previousChessGuiCell = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
            previousGuiCellCoordinates.first, previousGuiCellCoordinates.second)->widget());

    this->setIcon(previousChessGuiCell->icon());
    this->setIconSize(previousChessGuiCell->iconSize());

    previousChessGuiCell->setIcon(QIcon());
}

void ChessGuiCell::setChessPiece(std::string pieceType) {
    QString str = QString::fromStdString(pieceType);

    this->setText(str);
}
