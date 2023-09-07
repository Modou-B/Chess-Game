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
    this->addQueensToCells(layout);
    this->addKingsToCells(layout);
    this->addBishopsToCells(layout);
    this->addKnightsToCells(layout);
    this->addRooksToCells(layout);
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
void ChessGuiRenderer::addChessPieceToCells(QGridLayout *layout, std::string pieceType, int row, int column) {
    QString str = QString::fromStdString(pieceType);

    ChessGuiCell *chessGuiCell = static_cast<ChessGuiCell*>(layout->itemAtPosition(row, column)->widget());
    chessGuiCell->setText(str);
}


void ChessGuiRenderer::addPawnsToCells(QGridLayout *layout) {
    for (int i = 0; i < 8; i++) {
        addChessPieceToCells(layout, ChessConstants::PAWN_PIECE_TYPE, 1, i);
        addChessPieceToCells(layout, ChessConstants::PAWN_PIECE_TYPE, 6, i);
    }
}

void ChessGuiRenderer::addQueensToCells(QGridLayout *layout) {
    addChessPieceToCells(layout, ChessConstants::QUEEN_PIECE_TYPE, 0, 3);
    addChessPieceToCells(layout, ChessConstants::QUEEN_PIECE_TYPE, 7, 3);
}

void ChessGuiRenderer::addKingsToCells(QGridLayout *layout) {
    addChessPieceToCells(layout, ChessConstants::KING_PIECE_TYPE, 0, 4);
    addChessPieceToCells(layout, ChessConstants::KING_PIECE_TYPE, 7, 4);
}

void ChessGuiRenderer::addBishopsToCells(QGridLayout *layout) {
    addChessPieceToCells(layout, ChessConstants::BISHOP_PIECE_TYPE, 0, 2);
    addChessPieceToCells(layout, ChessConstants::BISHOP_PIECE_TYPE, 0, 5);
    addChessPieceToCells(layout, ChessConstants::BISHOP_PIECE_TYPE, 7, 2);
    addChessPieceToCells(layout, ChessConstants::BISHOP_PIECE_TYPE, 7, 5);
}

void ChessGuiRenderer::addKnightsToCells(QGridLayout *layout) {
    addChessPieceToCells(layout, ChessConstants::KNIGHT_PIECE_TYPE, 0, 1);
    addChessPieceToCells(layout, ChessConstants::KNIGHT_PIECE_TYPE, 0, 6);
    addChessPieceToCells(layout, ChessConstants::KNIGHT_PIECE_TYPE, 7, 1);
    addChessPieceToCells(layout, ChessConstants::KNIGHT_PIECE_TYPE, 7, 6);
}

void ChessGuiRenderer::addRooksToCells(QGridLayout *layout) {
    addChessPieceToCells(layout, ChessConstants::ROOK_PIECE_TYPE, 0, 0);
    addChessPieceToCells(layout, ChessConstants::ROOK_PIECE_TYPE, 0, 7);
    addChessPieceToCells(layout, ChessConstants::ROOK_PIECE_TYPE, 7, 0);
    addChessPieceToCells(layout, ChessConstants::ROOK_PIECE_TYPE, 7, 7);
}

