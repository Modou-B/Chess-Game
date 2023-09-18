//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiRenderer.h"
#include <QGridLayout>
#include "../Chess/ChessFacade.h"
#include "../Shared/Chess/ChessConstants.h"
#include "../Shared/ChessGui/ChessGuiConstants.h"
#include "../Model/Generator/ChessGuiPieceIconGenerator.h"
#include "../Model/ChessGuiCell.h"
#include "QWidget"
#include <utility>
#include "QImage"
#include "QPainter"

ChessGuiRenderer::ChessGuiRenderer(ChessFacade *chessFacade, ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator) {
    this->chessFacade = chessFacade;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    auto mainLayout = new QHBoxLayout(mainWindow);
    auto *layout = this->createChessGridLayout(mainWindow);
    mainLayout->addLayout(layout);

    this->fillFieldWithEmptyCells(layout);
    this->addPawnsToCells(layout);
    this->addQueensToCells(layout);
    this->addKingsToCells(layout);
    this->addBishopsToCells(layout);
    this->addKnightsToCells(layout);
    this->addRooksToCells(layout);
}


QGridLayout *ChessGuiRenderer::createChessGridLayout(QWidget *mainWindow) {
    return new QGridLayout();
}


void ChessGuiRenderer::fillFieldWithEmptyCells(QGridLayout *layout) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::pair<int, int> coordinates = std::make_pair(i, j);
            ChessGuiCell *chessGuiCell = new ChessGuiCell(layout, this->chessFacade, coordinates, this->chessGuiPieceIconGenerator);

            if (j % 2 - counter == 0) {
                chessGuiCell->setCellColor(ChessGuiConstants::CELL_YELLOW_COLOR);
            } else {
                chessGuiCell->setCellColor(ChessGuiConstants::CELL_GREEN_COLOR);
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
void ChessGuiRenderer::addChessPieceToCells(QGridLayout *layout, std::string iconFileName, std::string pieceType, int row, int column) {
    ChessGuiCell *chessGuiCell = static_cast<ChessGuiCell*>(layout->itemAtPosition(row, column)->widget());

    auto icon = this->chessGuiPieceIconGenerator->generateIconFromFile(iconFileName);

    chessGuiCell->setChessPieceIcon(ChessGuiConstants::STATE_REAL_CHESS_PIECE_ICON, icon);
    chessGuiCell->setIconSize(QSize(50, 50));
    chessGuiCell->setChessPieceType(pieceType);
}


void ChessGuiRenderer::addPawnsToCells(QGridLayout *layout) {
    for (int i = 0; i < 8; i++) {
        this->addChessPieceToCells(layout, ChessConstants::BLACK_PAWN_PIECE_FILENAME, ChessConstants::PAWN_PIECE_TYPE, 1, i);
        this->addChessPieceToCells(layout, ChessConstants::WHITE_PAWN_PIECE_FILENAME, ChessConstants::PAWN_PIECE_TYPE, 6, i);
    }
}

void ChessGuiRenderer::addQueensToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_QUEEN_PIECE_FILENAME, ChessConstants::QUEEN_PIECE_TYPE, 0, 3);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_QUEEN_PIECE_FILENAME, ChessConstants::QUEEN_PIECE_TYPE, 7, 3);
}

void ChessGuiRenderer::addKingsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_KING_PIECE_FILENAME, ChessConstants::KING_PIECE_TYPE, 0, 4);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_KING_PIECE_FILENAME, ChessConstants::KING_PIECE_TYPE, 7, 4);
}

void ChessGuiRenderer::addBishopsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 0, 2);
    this->addChessPieceToCells(layout, ChessConstants::BLACK_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 0, 5);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 7, 2);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 7, 5);
}

void ChessGuiRenderer::addKnightsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 0, 1);
    this->addChessPieceToCells(layout, ChessConstants::BLACK_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 0, 6);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 7, 1);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 7, 6);
}

void ChessGuiRenderer::addRooksToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 0, 0);
    this->addChessPieceToCells(layout, ChessConstants::BLACK_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 0, 7);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 7, 0);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 7, 7);
}