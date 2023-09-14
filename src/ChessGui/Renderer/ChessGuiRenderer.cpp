//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiRenderer.h"
#include <QGridLayout>
#include "../Chess/ChessFacade.h"
#include "../Shared/Chess/ChessConstants.h"
#include "../Shared/ChessGui/ChessGuiConstants.h"
#include "../Model/ChessGuiCell.h"
#include "QWidget"
#include <utility>
#include "QImage"
#include "QPainter"
#include <filesystem>

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
void ChessGuiRenderer::addChessPieceToCells(QGridLayout *layout, QIcon icon, int row, int column) {
    ChessGuiCell *chessGuiCell = static_cast<ChessGuiCell*>(layout->itemAtPosition(row, column)->widget());

    chessGuiCell->setIcon(icon);
    chessGuiCell->setIconSize(QSize(50, 50));
}


void ChessGuiRenderer::addPawnsToCells(QGridLayout *layout) {

    for (int i = 0; i < 8; i++) {
        this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_PAWN_PIECE_FILENAME), 1, i);
        this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_PAWN_PIECE_FILENAME), 6, i);
    }
}

void ChessGuiRenderer::addQueensToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_QUEEN_PIECE_FILENAME), 0, 3);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_QUEEN_PIECE_FILENAME), 7, 3);
}

void ChessGuiRenderer::addKingsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_KING_PIECE_FILENAME), 0, 4);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_KING_PIECE_FILENAME), 7, 4);
}

void ChessGuiRenderer::addBishopsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_BISHOP_PIECE_FILENAME), 0, 2);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_BISHOP_PIECE_FILENAME), 0, 5);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_BISHOP_PIECE_FILENAME), 7, 2);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_BISHOP_PIECE_FILENAME), 7, 5);
}

void ChessGuiRenderer::addKnightsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_KNIGHT_PIECE_FILENAME), 0, 1);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_KNIGHT_PIECE_FILENAME), 0, 6);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_KNIGHT_PIECE_FILENAME), 7, 1);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_KNIGHT_PIECE_FILENAME), 7, 6);
}

void ChessGuiRenderer::addRooksToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_ROOK_PIECE_FILENAME), 0, 0);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::BLACK_ROOK_PIECE_FILENAME), 0, 7);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_ROOK_PIECE_FILENAME), 7, 0);
    this->addChessPieceToCells(layout, this->createIconFromFile(ChessConstants::WHITE_ROOK_PIECE_FILENAME), 7, 7);
}

QIcon ChessGuiRenderer::createIconFromFile(std::string fileName) {
    std::string pathToFile = std::filesystem::current_path();
    pathToFile.append("/../../public/");
    pathToFile.append(fileName);

    return QIcon(QString::fromStdString(pathToFile));
}

