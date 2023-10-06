//
// Created by Julian Sommer on 06.10.23.
//

#include "ChessGridRenderer.h"
#include "../../Model/ChessGuiCell.h"
#include "../../Model/Generator/ChessGuiPieceIconGenerator.h"
#include "../../../Shared/Chess/ChessConstants.h"
#include "../../../Shared/ChessGui/ChessGuiConstants.h"
#include "../../../Chess/ChessFacade.h"
#include "../ChessPieceSelection/ChessPieceSelectionRenderer.h"
#include "../Timeline/ChessTimelineRenderer.h"
#include "../../Model/Settings/ChessSettingsDataHolder.h"
#include <QGridLayout>

ChessGridRenderer::ChessGridRenderer(
    ChessFacade *chessFacade,
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
    ChessTimelineRenderer *chessTimelineRenderer,
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator,
    ChessSettingsDataHolder *chessSettingsDataHolder
) {
    this->chessFacade = chessFacade;
    this->chessPieceSelectionRenderer = chessPieceSelectionRenderer;
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
    this->chessSettingsDataHolder = chessSettingsDataHolder;

    this->minCellWidth = 80;
    this->minCellHeight = 80;
}

QGridLayout *ChessGridRenderer::createChessFieldWithPieces() {
    auto *emptyChessGridLayout = this->createEmptyChessField();

    this->addPawnsToCells(emptyChessGridLayout);
    this->addRooksToCells(emptyChessGridLayout);
    this->addKnightsToCells(emptyChessGridLayout);
    this->addBishopsToCells(emptyChessGridLayout);
    this->addQueensToCells(emptyChessGridLayout);
    this->addKingsToCells(emptyChessGridLayout);

    return emptyChessGridLayout;
}

QGridLayout *ChessGridRenderer::createEmptyChessField() {
    auto emptyChessGridLayout = new QGridLayout();

    this->fillFieldWithEmptyCells(emptyChessGridLayout);

    return emptyChessGridLayout;
}

void ChessGridRenderer::fillFieldWithEmptyCells(QGridLayout *chessGridlayout) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pair<int, int> coordinates = make_pair(i, j);
            ChessGuiCell *chessGuiCell = new ChessGuiCell(
                    chessGridlayout,
                    this->chessFacade,
                    this->chessPieceSelectionRenderer,
                    this->chessTimelineRenderer,
                    coordinates,
                    this->chessGuiPieceIconGenerator
            );

            if (j % 2 - counter == 0) {
                chessGuiCell->setCellColor(this->chessSettingsDataHolder->getColorForPlayer(1));
            } else {
                chessGuiCell->setCellColor(this->chessSettingsDataHolder->getColorForPlayer(2));
            }

            chessGuiCell->setBaseCellSize(this->minCellWidth, this->minCellHeight);

            chessGridlayout->addWidget(chessGuiCell, i, j);
        }

        counter++;
        if (counter > 1) {
            counter = 0;
        }
    }

    chessGridlayout->setSpacing(0);
}


void ChessGridRenderer::addPawnsToCells(QGridLayout *chessGridlayout) {
    for (int i = 0; i < 8; i++) {
        this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_PAWN_PIECE_FILENAME, ChessConstants::PAWN_PIECE_TYPE, 1, i);
        this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_PAWN_PIECE_FILENAME, ChessConstants::PAWN_PIECE_TYPE, 6, i);
    }
}

void ChessGridRenderer::addQueensToCells(QGridLayout *chessGridlayout) {
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_QUEEN_PIECE_FILENAME, ChessConstants::QUEEN_PIECE_TYPE, 0, 3);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_QUEEN_PIECE_FILENAME, ChessConstants::QUEEN_PIECE_TYPE, 7, 3);
}

void ChessGridRenderer::addKingsToCells(QGridLayout *chessGridlayout) {
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_KING_PIECE_FILENAME, ChessConstants::KING_PIECE_TYPE, 0, 4);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_KING_PIECE_FILENAME, ChessConstants::KING_PIECE_TYPE, 7, 4);
}

void ChessGridRenderer::addBishopsToCells(QGridLayout *chessGridlayout) {
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 0, 2);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 0, 5);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 7, 2);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 7, 5);
}

void ChessGridRenderer::addKnightsToCells(QGridLayout *chessGridlayout) {
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 0, 1);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 0, 6);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 7, 1);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 7, 6);
}

void ChessGridRenderer::addRooksToCells(QGridLayout *chessGridlayout) {
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 0, 0);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::BLACK_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 0, 7);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 7, 0);
    this->addChessPieceToCells(chessGridlayout, ChessConstants::WHITE_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 7, 7);
}

void ChessGridRenderer::addChessPieceToCells(QGridLayout *chessGridlayout, string iconFileName, string pieceType, int row, int column) {
    ChessGuiCell *chessGuiCell = static_cast<ChessGuiCell*>(chessGridlayout->itemAtPosition(row, column)->widget());

    auto icon = this->chessGuiPieceIconGenerator->generateIconFromFile(iconFileName);

    chessGuiCell->setChessPieceIcon(ChessGuiConstants::STATE_REAL_CHESS_PIECE_ICON, icon);
    chessGuiCell->setIconSize(QSize(50, 50));
    chessGuiCell->setChessPieceType(pieceType);
}

void ChessGridRenderer::updateChessGridCellColor(QGridLayout *chessGridPreviewLayout)
{
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ChessGuiCell *chessGuiCell = static_cast<ChessGuiCell*>(
                chessGridPreviewLayout->itemAtPosition(i, j)->widget());

            if (j % 2 - counter == 0) {
                chessGuiCell->setCellColor(this->chessSettingsDataHolder->getColorForPlayer(1));
            } else {
                chessGuiCell->setCellColor(this->chessSettingsDataHolder->getColorForPlayer(2));
            }
        }

        counter++;
        if (counter > 1) {
            counter = 0;
        }
    }
}

void ChessGridRenderer::setCellSize(int minWidth, int minHeight)
{
    this->minCellWidth = minWidth;
    this->minCellHeight = minHeight;
}
