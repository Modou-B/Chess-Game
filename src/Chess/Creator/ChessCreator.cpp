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
    this->fillFieldWithKings(chessField);
    this->fillFieldWithBishops(chessField);
    this->fillFieldWithKnights(chessField);
    this->fillFieldWithRooks(chessField);
}

void ChessCreator::fillFieldWithPieces(ChessField *chessField, std::string pieceType, int player, int row, int column) {
        std::pair<int, int> rowCoordinates = std::make_pair(row, column);
        auto *piecePlayer = this->createChessPiece(pieceType, player);

        ChessCell *rowChessCell = chessField->getChessCell(rowCoordinates);
        rowChessCell->setChessPiece(piecePlayer);
}

void ChessCreator::fillFieldWithPawns(ChessField *chessField) {
    for (int i = 0; i < 8; i++) {
        fillFieldWithPieces(chessField, ChessConstants::PAWN_PIECE_TYPE, 1, 1, i);
        fillFieldWithPieces(chessField, ChessConstants::PAWN_PIECE_TYPE, 2, 6,i);
    }
}

void ChessCreator::fillFieldWithQueens(ChessField *chessField) {
    fillFieldWithPieces(chessField, ChessConstants::QUEEN_PIECE_TYPE, 1, 0, 3);
    fillFieldWithPieces(chessField, ChessConstants::QUEEN_PIECE_TYPE, 2, 7, 3);
}

void ChessCreator::fillFieldWithKings(ChessField *chessField) {
    fillFieldWithPieces(chessField, ChessConstants::KING_PIECE_TYPE, 1, 0, 4);
    fillFieldWithPieces(chessField, ChessConstants::KING_PIECE_TYPE, 2, 7, 4);
}

void ChessCreator::fillFieldWithBishops(ChessField *chessField) {
    fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 1, 0, 3);
    fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 1, 0, 5);

    fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 2, 7, 3);
    fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 2, 7, 5);
}

void ChessCreator::fillFieldWithKnights(ChessField *chessField) {
    fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 1, 0, 1);
    fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 1, 0, 6);

    fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 2, 7, 1);
    fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 2, 7, 6);
}

void ChessCreator::fillFieldWithRooks(ChessField *chessField) {
    fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 1, 0, 0);
    fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 1, 0, 7);

    fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 2, 7, 0);
    fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 2, 7, 7);
}







