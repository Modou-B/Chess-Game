//
// Created by Julian Sommer on 06.09.23.
//

#include "ChessGuiCell.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPieceMovementTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "../../Shared/ChessGui/ChessGuiConstants.h"
#include "../../Chess/ChessFacade.h"
#include "Generator/ChessGuiPieceIconGenerator.h"
#include "QGridLayout"
#include "QString"
#include "iostream"
#include "QGraphicsOpacityEffect"

ChessGuiCell::ChessGuiCell(QGridLayout *gridLayout, ChessFacade *chessFacade, std::pair<int, int> coordinates, ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator) {
    this->gridLayout = gridLayout;
    this->chessFacade = chessFacade;
    this->coordinates = coordinates;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
    this->chessPieceIconState = ChessGuiConstants::STATE_EMPTY_CHESS_PIECE_ICON;

    connect(this, &QPushButton::released, this, &ChessGuiCell::handleCellClick);
}

void ChessGuiCell::handleCellClick() {
    ChessMovementResponseTransfer chessMovementResponseTransfer = this->chessFacade->handleChessCellClick(this->coordinates);

    if (chessMovementResponseTransfer.getState() == ChessConstants::STATE_SWITCHED_PIECE) {
        this->clearPossibleMovesForPreviousPieceClick(chessMovementResponseTransfer);
    }

    if (chessMovementResponseTransfer.doesPieceHasPossibleMoves()) {
        this->renderPossibleMovesForPiece(chessMovementResponseTransfer);
    }

    if (!chessMovementResponseTransfer.wasPieceMoved()) {
        return;
    }

    this->handleChessPieceMovement(chessMovementResponseTransfer);
    this->chessFacade->endCurrentTurn(chessMovementResponseTransfer);
    this->chessFacade->startNewTurn();
}

Qt::GlobalColor ChessGuiCell::getCellColor() {
    return this->currentColor;
}

QGridLayout *ChessGuiCell::getGridLayout() {
    return this->gridLayout;
}

void ChessGuiCell::setBaseCellSize() {
    this->setMinimumSize(80,80);
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
    this->clearPossibleMovesForPreviousPieceClick(chessMovementResponseTransfer);

    for (auto &chessPieceMovementTransfer : *chessMovementResponseTransfer.getChessPiecesToMove())
    {
        ChessGuiCell *oldChessGuiCell = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                chessPieceMovementTransfer->getOldCoordinates().first, chessPieceMovementTransfer->getOldCoordinates().second)->widget());

        if (chessPieceMovementTransfer->getAction() == ChessMovementConstants::ACTION_MOVE) {
            ChessGuiCell *newChessGuiCell = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                    chessPieceMovementTransfer->getNewCoordinates().first, chessPieceMovementTransfer->getNewCoordinates().second)->widget());

            newChessGuiCell->setChessPieceIcon(
                ChessGuiConstants::STATE_REAL_CHESS_PIECE_ICON, oldChessGuiCell->icon());
            newChessGuiCell->setIconSize(oldChessGuiCell->iconSize());
            newChessGuiCell->setChessPieceType(oldChessGuiCell->getChessPieceType());
        }

        oldChessGuiCell->setChessPieceIcon(
            ChessGuiConstants::STATE_EMPTY_CHESS_PIECE_ICON, this->chessGuiPieceIconGenerator->generateEmptyIcon());
        oldChessGuiCell->setChessPieceType(ChessConstants::EMPTY_PIECE_TYPE);
    }
}

void ChessGuiCell::renderPossibleMovesForPiece(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    for (auto &possibleCoordinates : *chessMovementResponseTransfer.getPossibleMoves())
    {
        ChessGuiCell *possibleChessCellToMove = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                possibleCoordinates->getYCoordinate(), possibleCoordinates->getXCoordinate())->widget());

        if (possibleChessCellToMove->getChessPieceIconState() == ChessGuiConstants::STATE_EMPTY_CHESS_PIECE_ICON) {
            std::string pieceType = this->getChessPieceType();
            pieceType.append("-black");

            possibleChessCellToMove->setChessPieceIcon(
                    ChessGuiConstants::STATE_PREVIEW_CHESS_PIECE_ICON, this->chessGuiPieceIconGenerator->generateTransparentIconFromFile(pieceType));
            possibleChessCellToMove->setIconSize(QSize(40, 40));
        }
    }
}

void ChessGuiCell::clearPossibleMovesForPreviousPieceClick(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    for (auto &possibleCoordinates : *chessMovementResponseTransfer.getPreviousPossibleMoves())
    {
        ChessGuiCell *possibleChessCellToMove = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                possibleCoordinates->getYCoordinate(), possibleCoordinates->getXCoordinate())->widget());

        if (possibleChessCellToMove->getChessPieceIconState() == ChessGuiConstants::STATE_PREVIEW_CHESS_PIECE_ICON) {
            possibleChessCellToMove->setChessPieceIcon(
                    ChessGuiConstants::STATE_EMPTY_CHESS_PIECE_ICON,this->chessGuiPieceIconGenerator->generateEmptyIcon());
            possibleChessCellToMove->setIconSize(QSize(40, 40));
        }
    }
}

void ChessGuiCell::setChessPieceType(std::string pieceType) {
    this->chessPieceType = pieceType;
}

void ChessGuiCell::setChessPieceIcon(std::string iconState, QIcon chessPieceIcon) {
    this->chessPieceIconState = iconState;

    this->setIcon(chessPieceIcon);
}

std::string ChessGuiCell::getChessPieceIconState() {
    return this->chessPieceIconState;
}

std::string ChessGuiCell::getChessPieceType() {
    return this->chessPieceType;
}
