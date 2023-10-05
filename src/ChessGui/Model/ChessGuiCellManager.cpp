//
// Created by Julian Sommer on 03.10.23.
//

#include "ChessGuiCellManager.h"
#include "ChessGuiCell.h"
#include <QGridLayout>
#include "iostream"
#include "../../Shared/ChessTimeline/ChessTurnLogTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceInformationTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPieceStateTransfer.h"
#include "../../Shared/ChessTimeline/ChessTimelineConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"

QGridLayout *ChessGuiCellManager::chessGuiCellGrid = new QGridLayout();

void ChessGuiCellManager::setChessGuiCellGrid(QGridLayout *chessGuiCellGrid) {
    ChessGuiCellManager::chessGuiCellGrid = chessGuiCellGrid;
}

void ChessGuiCellManager::handlePawnPieceSwitch(pair<int, int> chessGuiCellCoordinate, string pieceTypeToSwitch) {
    ChessGuiCell *currentChessGuiCell = this->getChessGuiCell(chessGuiCellCoordinate);

    currentChessGuiCell->handlePawnPieceSwitch(pieceTypeToSwitch);
}

void ChessGuiCellManager::forwardChessGridToLatestTurn(
    vector<ChessTurnLogTransfer *> chessTurnLogTransfers
) {
    for (auto &chessTurnLogTransfer: chessTurnLogTransfers) {
        this->updateChessGrid(chessTurnLogTransfer, ChessTimelineConstants::MODE_FORWARD);
    }
}

void ChessGuiCellManager::updateChessGrid(
    ChessTurnLogTransfer *chessTurnLogTransfer,
    string mode
) {
    vector<ChessPieceInformationTransfer *> chessPieceDeleteInformationStateTransfers;
    for (auto &chessPieceInformationTransfer: chessTurnLogTransfer->getChessPieceInformationTransfers()) {
        if (chessPieceInformationTransfer->getChessPieceStateTransfer()->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
            this->handleChessPieceStates(chessPieceInformationTransfer, mode);

            continue;
        }

        chessPieceDeleteInformationStateTransfers.push_back(chessPieceInformationTransfer);
    }

    for (auto &chessPieceInformationTransfer: chessPieceDeleteInformationStateTransfers) {
        this->handleChessPieceStates(chessPieceInformationTransfer, mode);
    }
}

void ChessGuiCellManager::handleChessPieceStates(
    ChessPieceInformationTransfer *chessPieceInformationTransfer,
    string mode
) {
    auto chessPieceColor = chessPieceInformationTransfer->getChessPieceColor();
    auto *chessPieceStateTransfer = chessPieceInformationTransfer->getChessPieceStateTransfer();
    auto *startChessGuiCell = this->getChessGuiCell(chessPieceStateTransfer->getStartCoordinate());

    if (mode == ChessTimelineConstants::MODE_REWIND) {
        startChessGuiCell->addChessPiece(
            chessPieceStateTransfer->getChessPieceType(),
            chessPieceInformationTransfer->getChessPieceColor()
        );

        if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
            auto *movedChessGuiCell = this->getChessGuiCell(chessPieceStateTransfer->getEndCoordinate());
            movedChessGuiCell->clearCurrentChessPiece();
        }

        return;
    }

    if (mode == ChessTimelineConstants::MODE_FORWARD) {
        if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_DELETED) {
            return;
        }

        startChessGuiCell->clearCurrentChessPiece();

        if (chessPieceStateTransfer->getState() == ChessMovementConstants::CHESS_PIECE_STATE_MOVED) {
            auto *movedChessGuiCell = this->getChessGuiCell(chessPieceStateTransfer->getEndCoordinate());
            movedChessGuiCell->addChessPiece(
                chessPieceStateTransfer->getChessPieceType(),
                chessPieceInformationTransfer->getChessPieceColor()
            );
        }
    }
}

ChessGuiCell *ChessGuiCellManager::getChessGuiCell(pair<int, int> chessCellCoordinate)
{
    return static_cast<ChessGuiCell*>(
          ChessGuiCellManager::chessGuiCellGrid->itemAtPosition(
              chessCellCoordinate.first, chessCellCoordinate.second
          )->widget()
    );
}