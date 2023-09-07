//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiRenderer.h"
#include <QGridLayout>
#include "../Chess/ChessFacade.h"
#include "../Shared/Chess/ChessConstants.h"
#include "../Model/ChessGuiCell.h"
#include "QWidget"
#include "QLayoutItem"
#include <utility>

ChessGuiRenderer::ChessGuiRenderer(ChessFacade *chessFacade) {
    this->chessFacade = chessFacade;
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    auto *layout = this->createChessGridLayout(mainWindow);

    this->fillFieldWithEmptyCells(layout);
    this->addPawnsToCells(layout);
}


QGridLayout *ChessGuiRenderer::createChessGridLayout(QWidget *mainWindow) {
    return new QGridLayout(mainWindow);
}


void ChessGuiRenderer::fillFieldWithEmptyCells(QGridLayout *layout) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::pair<int, int> coordinates = std::make_pair(i, j);
            ChessGuiCell *chessGuiCell = new ChessGuiCell(layout, this->chessFacade, coordinates);

            if (j % 2 - counter == 0) {
                chessGuiCell->setCellColor(Qt::black);
            } else {
                chessGuiCell->setCellColor(Qt::white);
            }

            chessGuiCell->setBaseCellSize();

            layout->addWidget(chessGuiCell, i, j);
        }

        counter++;
        if (counter > 1) {
            counter = 0;
        }
    }

    layout->setSpacing(0);
}


void ChessGuiRenderer::addPawnsToCells(QGridLayout *layout) {
    for (int i = 0; i < 8; i++) {
        QString str = QString::fromStdString(ChessConstants::PAWN_PIECE_TYPE);

        ChessGuiCell *chessGuiTopCell = static_cast<ChessGuiCell*>(layout->itemAtPosition(1, i)->widget());
        ChessGuiCell *chessGuiBottomCell = static_cast<ChessGuiCell*>(layout->itemAtPosition(6, i)->widget());

        chessGuiTopCell->setText(str);
        chessGuiBottomCell->setText(str);
    }
}

