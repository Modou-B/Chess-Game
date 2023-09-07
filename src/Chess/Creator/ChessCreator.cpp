//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCreator.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include <utility>
#include "../Shared/Chess/ChessConstants.h"
#include "../ChessPiece/PawnPiece.h"

BaseChessPiece *ChessCreator::createChessPiece(std::string type, int player) {
    if (type == ChessConstants::PAWN_PIECE_TYPE) {
        return new PawnPiece(player);
    }

    return nullptr;
}

ChessCell *ChessCreator::createChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates) {
    return new ChessCell(chessPiece,coordinates);
}

ChessField *ChessCreator::createChessField() {
    return new ChessField();
}

ChessField *ChessCreator::initiateChessField() {
    ChessField *chessField = new ChessField();

    this->fillFieldWithEmptyCells(chessField);
    this->addChessPiecesToFieldCells(chessField);

    return chessField;
}

void ChessCreator::fillFieldWithEmptyCells(ChessField *chessField) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::pair<int, int> coordinates = std::make_pair(i, j);
            ChessCell *chessCell = this->createChessCell(nullptr, coordinates);

            chessField->addChessCell(chessCell);
        }
    }
}

void ChessCreator::addChessPiecesToFieldCells(ChessField *chessField) {
    this->fillFieldWithPawns(chessField);
    this->fillFieldWithQueens(chessField);
}

void ChessCreator::fillFieldWithPawns(ChessField *chessField) {
    for (int i = 0; i < 8; i++) {
        std::pair<int, int> topRowCoordinates = std::make_pair(1, i);
        std::pair<int, int> bottomRowCoordinates = std::make_pair(6, i);

        auto *pawnPiecePlayer1 = this->createChessPiece(ChessConstants::PAWN_PIECE_TYPE, 1);
        auto *pawnPiecePlayer2 = this->createChessPiece(ChessConstants::PAWN_PIECE_TYPE, 2);

        ChessCell *topRowChessCell = chessField->getChessCell(topRowCoordinates);
        ChessCell *bottomRowChessCell = chessField->getChessCell(bottomRowCoordinates);

        topRowChessCell->setChessPiece(pawnPiecePlayer2);
        bottomRowChessCell->setChessPiece(pawnPiecePlayer1);
    }
}

void ChessCreator::fillFieldWithQueens(ChessField *chessField) {
    return;
}




