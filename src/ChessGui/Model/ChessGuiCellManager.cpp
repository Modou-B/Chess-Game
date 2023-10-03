//
// Created by Julian Sommer on 03.10.23.
//

#include "ChessGuiCellManager.h"
#include "ChessGuiCell.h"
#include <QGridLayout>
#include "iostream"

QGridLayout *ChessGuiCellManager::chessGuiCellGrid = new QGridLayout();

void ChessGuiCellManager::setChessGuiCellGrid(QGridLayout *chessGuiCellGrid) {
    ChessGuiCellManager::chessGuiCellGrid = chessGuiCellGrid;
}

void ChessGuiCellManager::handlePawnPieceSwitch(pair<int, int> chessGuiCellCoordinate, string pieceTypeToSwitch) {
    ChessGuiCell *currentChessGuiCell = static_cast<ChessGuiCell*>(
        ChessGuiCellManager::chessGuiCellGrid->itemAtPosition(
            chessGuiCellCoordinate.first, chessGuiCellCoordinate.second
        )->widget()
    );

    std::cout << "Here "<< std::endl;
    std::cout << chessGuiCellCoordinate.first << " " << chessGuiCellCoordinate.second << std::endl;
    std::cout << currentChessGuiCell->getChessPieceType() << std::endl;

    currentChessGuiCell->handlePawnPieceSwitch(pieceTypeToSwitch);
}