//
// Created by Julian Sommer on 06.09.23.
//

#include "ChessGuiCell.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceStateTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "../../Shared/ChessGui/ChessGuiConstants.h"
#include "../../Chess/ChessFacade.h"
#include "Generator/ChessGuiPieceIconGenerator.h"
#include "../Renderer/ChessPieceSelection/ChessPieceSelectionRenderer.h"
#include "QGridLayout"
#include "QString"
#include "iostream"
#include "QGraphicsOpacityEffect"
#include "QListWidgetItem"
#include "../Renderer/ChessGuiRenderer.h"
#include "../Renderer/ChessCoordinateConverter.h"

ChessGuiCell::ChessGuiCell(
        QGridLayout *gridLayout,
        ChessFacade *chessFacade,
        ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
        pair<int, int> coordinates,
        ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator
) {
    this->gridLayout = gridLayout;
    this->chessFacade = chessFacade;
    this->coordinates = coordinates;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
    this->chessPieceSelectionRenderer = chessPieceSelectionRenderer;
    this->chessPieceIconState = ChessGuiConstants::STATE_EMPTY_CHESS_PIECE_ICON;

    connect(this, &QPushButton::released, this, &ChessGuiCell::handleCellClick);
}

void ChessGuiCell::handleCellClick() {
    ChessMovementResponseTransfer chessMovementResponseTransfer = this->chessFacade->handleChessCellClick(this->coordinates);

    if (chessMovementResponseTransfer.getState() == ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH_SELECTION) {
        return;
    }

    if (chessMovementResponseTransfer.getState() == ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH_SELECTION_START) {
        this->handleChessPieceMovement(chessMovementResponseTransfer);
        this->addListWidgetItem(this->coordinates);

        this->chessPieceSelectionRenderer->renderChessPieceSelectionHBoxForPlayer(
            chessMovementResponseTransfer.getCurrentPlayer()
        );

        this->chessFacade->updateCurrentGameState(ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH_SELECTION);

        return;
    }

    if (chessMovementResponseTransfer.getState() == ChessMovementConstants::MOVEMENT_STATE_SWITCHED_TO_OWN_PIECE) {
        this->clearPossibleMovesForPreviousPieceClick(chessMovementResponseTransfer);
    }

    if (!chessMovementResponseTransfer.getPossibleMoveTransfers().empty()) {
        this->renderPossibleMovesForPiece(chessMovementResponseTransfer);
    }

    if (chessMovementResponseTransfer.getState() == ChessMovementConstants::MOVEMENT_STATE_NOT_MOVED
        || (chessMovementResponseTransfer.getState() != ChessMovementConstants::MOVEMENT_STATE_MOVED
            && chessMovementResponseTransfer.getState() != ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH)) {
        return;
    }

    this->handleChessPieceMovement(chessMovementResponseTransfer);
    this->addListWidgetItem(this->coordinates);
    this->chessFacade->endCurrentTurn(chessMovementResponseTransfer, this->createCurrentChessPiecePositionTransfer());
    this->chessFacade->startNewTurn();
}

Qt::GlobalColor ChessGuiCell::getCellColor() {
    return this->currentColor;
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

    for (auto &chessPieceStateTransfer : chessMovementResponseTransfer.getChessPieceStateTransfers())
    {
        if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_DELETED) {
            continue;
        }

        ChessGuiCell *oldChessGuiCell = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                chessPieceStateTransfer->getStartCoordinate().first, chessPieceStateTransfer->getStartCoordinate().second)->widget());

        if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
            ChessGuiCell *newChessGuiCell = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                    chessPieceStateTransfer->getEndCoordinate().first, chessPieceStateTransfer->getEndCoordinate().second)->widget());

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
    for (auto &possibleCoordinates : chessMovementResponseTransfer.getPossibleMoveTransfers())
    {
        ChessGuiCell *possibleChessCellToMove = static_cast<ChessGuiCell*>(this->gridLayout->itemAtPosition(
                possibleCoordinates->getYCoordinate(), possibleCoordinates->getXCoordinate())->widget());

        if (possibleChessCellToMove->getChessPieceIconState() == ChessGuiConstants::STATE_EMPTY_CHESS_PIECE_ICON) {
            string pieceType = this->getChessPieceType();
            pieceType.append("-black");

            possibleChessCellToMove->setChessPieceIcon(
                    ChessGuiConstants::STATE_PREVIEW_CHESS_PIECE_ICON, this->chessGuiPieceIconGenerator->generateTransparentIconFromFile(pieceType));
            possibleChessCellToMove->setIconSize(QSize(40, 40));
        }
    }
}

void ChessGuiCell::clearPossibleMovesForPreviousPieceClick(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    for (auto &possibleCoordinates : chessMovementResponseTransfer.getPreviousPossibleMoveTransfers())
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

void ChessGuiCell::setChessPieceType(string pieceType) {
    this->chessPieceType = pieceType;
}

void ChessGuiCell::setChessPieceIcon(string iconState, QIcon chessPieceIcon) {
    this->chessPieceIconState = iconState;

    this->setIcon(chessPieceIcon);
}

string ChessGuiCell::getChessPieceIconState() {
    return this->chessPieceIconState;
}

string ChessGuiCell::getChessPieceType() {
    return this->chessPieceType;
}

void ChessGuiCell::handlePawnPieceSwitch(string pieceType) {
    string pieceTypeFilename = pieceType;
    int currentPlayer = this->chessFacade->getCurrentPlayer();

    if (currentPlayer == 1) {
          pieceTypeFilename.append("-white");
    } else {
          pieceTypeFilename.append("-black");
    }

    this->setChessPieceIcon(
        ChessGuiConstants::STATE_REAL_CHESS_PIECE_ICON,
        this->chessGuiPieceIconGenerator->generateIconFromFile(pieceTypeFilename)
    );
    this->setIconSize(QSize(50, 50));
    this->setChessPieceType(pieceType);
    
    this->chessPieceSelectionRenderer->hideChessPieceSelectionHBoxForPlayer(currentPlayer);
}

void ChessGuiCell::addListWidgetItem(pair<int, int> currentCellCoordinates) {
    QString entryStr = QString::fromStdString(
            ChessCoordinateConverter::GetConvertedChessMatrixValue(currentCellCoordinates) + " -> " +
            this->getChessPieceType());

    auto *rewindListEntry = new QListWidgetItem(entryStr);
    ChessGuiRenderer::timelineList->insertItem(ChessGuiRenderer::timelineList->count() + 1, rewindListEntry);
    ChessGuiRenderer::timelineList->setCurrentRow(ChessGuiRenderer::timelineList->count() - 1);
}

ChessPiecePositionTransfer ChessGuiCell::createCurrentChessPiecePositionTransfer()
{
    ChessPiecePositionTransfer chessPiecePositionTransfer = {};
    chessPiecePositionTransfer.setCurrentChessPieceCoordinates(this->coordinates);

    return chessPiecePositionTransfer;
}