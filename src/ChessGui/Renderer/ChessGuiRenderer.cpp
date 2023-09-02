//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiRenderer.h"
#include <QGridLayout>
#include "../Chess/ChessFacade.h"
#include "../Chess/Model/ChessField.h"
#include "../Chess/Model/ChessCell.h"
#include "../Shared/Chess/Transfer/ChessPieceTransfer.h"
#include "../Shared/Chess/Transfer/ChessCellTransfer.h"
#include "../Shared/Chess/ChessConstants.h"
#include "../Chess/ChessPiece/PawnPiece.h"
#include <utility>
#include "typeinfo"
#include "iostream"

ChessGuiRenderer::ChessGuiRenderer(ChessFacade *chessFacade) {
    this->chessFacade = chessFacade;
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    auto *layout = this->createChessGridLayout(mainWindow);

    auto *chessFieldModel = this->chessFacade->createChessField();
    this->fillFieldWithEmptyCells(layout, chessFieldModel);

    this->addPawnsToCells(chessFieldModel);
}


QGridLayout *ChessGuiRenderer::createChessGridLayout(QWidget *mainWindow) {
    return new QGridLayout(mainWindow);
}


void ChessGuiRenderer::fillFieldWithEmptyCells(QGridLayout *layout, ChessField *chessFieldModel) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ChessCellTransfer chessCellTransfer = ChessCellTransfer();
            chessCellTransfer.setXPosition(i).setYPosition(j);

            ChessCell *chessCell = this->chessFacade->createChessCell(&chessCellTransfer);

            QPalette pal = chessCell->palette();
            if (j % 2 - counter == 0) {
                pal.setColor(QPalette::Button, QColor(Qt::black));
            } else {
                pal.setColor(QPalette::Button, QColor(Qt::white));
                pal.setColor(QPalette::ButtonText, QColor(Qt::black));

            }

            chessCell->setAutoFillBackground(true);
            chessCell->setPalette(pal);
            chessCell->update();
            chessCell->setMinimumSize(50,50);
            chessCell->setMaximumSize(1000,1000);

            layout->addWidget(chessCell, i, j);

            chessFieldModel->addChessCell(chessCell);
        }

        counter++;
        if (counter > 1) {
            counter = 0;
        }
    }

    layout->setSpacing(0);
}


void ChessGuiRenderer::addPawnsToCells(ChessField *chessFieldModel) {
    auto chessPieceTransfer = (ChessPieceTransfer()).setType(ChessConstants::PAWN_PIECE_TYPE);

    for (int i = 0; i < 8; i++) {
        auto *pawnForPlayer1 = (
                this->chessFacade
                    ->createChessPiece(&chessPieceTransfer.setPlayer(1))
                );

        auto *pawnForPlayer2 = (
                this->chessFacade
                    ->createChessPiece(&chessPieceTransfer.setPlayer(2))
                    );

        QString str = QString::fromStdString(ChessConstants::PAWN_PIECE_TYPE);

        auto chessCellTop = chessFieldModel->getChessCell(1, i);
        auto chessCellBottom = chessFieldModel->getChessCell(6, i);

        chessCellTop->setChessPiece(pawnForPlayer1);
        chessCellTop->setText(str);

        chessCellBottom->setChessPiece(pawnForPlayer2);
        chessCellBottom->setText(str);
    }
}

