//
// Created by Julian Sommer on 03.10.23.
//

#include "ChessPieceSelectionRenderer.h"
#include "../../Model/ChessSelectionPiece.h"
#include "../../Model/Generator/ChessGuiPieceIconGenerator.h"
#include <QHBoxLayout>
#include <QSize>
#include <QWidget>

QHBoxLayout *ChessPieceSelectionRenderer::hBoxChessPieceSelectionTop = new QHBoxLayout();
QHBoxLayout *ChessPieceSelectionRenderer::hBoxChessPieceSelectionBottom = new QHBoxLayout();

ChessPieceSelectionRenderer::ChessPieceSelectionRenderer(
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator
) {
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
}

void ChessPieceSelectionRenderer::createChessPieceSelectionHBoxes(
    ChessFacade *chessFacade,
    string chessPieceTypes[4]
) {
    for (int i = 0; i < 4; i++) {
        auto pieceType = chessPieceTypes[i];

        ChessPieceSelectionRenderer::hBoxChessPieceSelectionTop->addWidget(
            this->createChessSelectionPiece(chessFacade, pieceType, "-white")
        );

        ChessPieceSelectionRenderer::hBoxChessPieceSelectionBottom->addWidget(
            this->createChessSelectionPiece(chessFacade, pieceType, "-black")
        );
    }

    this->hideChessPieceSelectionHBoxForPlayer(1);
    this->hideChessPieceSelectionHBoxForPlayer(2);
}

void ChessPieceSelectionRenderer::hideChessPieceSelectionHBoxForPlayer(int player) {
    auto *ChessPieceSelectionHBox = this->getChessPieceSelectionHBoxForPlayer(player);
    for (int i = 0; i < 4; i++) {
        QWidget *chessSelectionPiece = ChessPieceSelectionHBox->itemAt(i)->widget();

        chessSelectionPiece->hide();
    }
}

void ChessPieceSelectionRenderer::renderChessPieceSelectionHBoxForPlayer(int player) {
    auto *ChessPieceSelectionHBox = this->getChessPieceSelectionHBoxForPlayer(player);
    for (int i = 0; i < 4; i++) {
        QWidget *chessSelectionPiece = ChessPieceSelectionHBox->itemAt(i)->widget();

        chessSelectionPiece->show();
    }
}

QHBoxLayout *ChessPieceSelectionRenderer::getChessPieceSelectionHBoxForPlayer(int player) {
    if (player == 1) {
        return ChessPieceSelectionRenderer::hBoxChessPieceSelectionTop;
    }

    return ChessPieceSelectionRenderer::hBoxChessPieceSelectionBottom;
}

ChessSelectionPiece *ChessPieceSelectionRenderer::createChessSelectionPiece(
    ChessFacade *chessFacade,
    string type,
    string iconColor
) {
    auto *chessSelectionPiece = new ChessSelectionPiece(chessFacade, type);

    auto pieceTypeFileName = type.append(iconColor);
    chessSelectionPiece->setIcon(
        this->chessGuiPieceIconGenerator->generateIconFromFile(pieceTypeFileName)
    );
    chessSelectionPiece->setIconSize(QSize(40, 40));

    return chessSelectionPiece;
}