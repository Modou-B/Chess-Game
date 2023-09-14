//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCreator.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include <utility>
#include "../Shared/Chess/ChessConstants.h"
#include "../ChessPiece/PawnPiece.h"
#include "../ChessPiece/KnightPiece.h"
#include "../ChessPiece/BishopPiece.h"
#include "../ChessPiece/RookPiece.h"
#include "../ChessPiece/QueenPiece.h"
#include "../ChessPiece/KingPiece.h"

BaseChessPiece *ChessCreator::createChessPiece(std::string type, int player) {
    if (type == ChessConstants::PAWN_PIECE_TYPE) {
        return new PawnPiece(player);
    }
    if (type == ChessConstants::KNIGHT_PIECE_TYPE) {
        return new KnightPiece(player);
    }
    if (type == ChessConstants::KING_PIECE_TYPE) {
        return new KingPiece(player);
    }
    if (type == ChessConstants::ROOK_PIECE_TYPE) {
        return new RookPiece(player);
    }
    if (type == ChessConstants::QUEEN_PIECE_TYPE) {
        return new QueenPiece(player);
    }
    if (type == ChessConstants::BISHOP_PIECE_TYPE) {
        return new BishopPiece(player);
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
        std::pair<int, int> coordinates = std::make_pair(row, column);
        auto *piecePlayer = this->createChessPiece(pieceType, player);

        ChessCell *rowChessCell = chessField->getChessCell(coordinates);
        rowChessCell->setChessPiece(piecePlayer);
}

void ChessCreator::fillFieldWithPawns(ChessField *chessField) {
    for (int i = 0; i < 8; i++) {
        this->fillFieldWithPieces(chessField, ChessConstants::PAWN_PIECE_TYPE, 2, 1, i);
        this->fillFieldWithPieces(chessField, ChessConstants::PAWN_PIECE_TYPE, 1, 6, i);
    }
}

void ChessCreator::fillFieldWithQueens(ChessField *chessField) {
    this->fillFieldWithPieces(chessField, ChessConstants::QUEEN_PIECE_TYPE, 2, 0, 3);
    this->fillFieldWithPieces(chessField, ChessConstants::QUEEN_PIECE_TYPE, 1, 7, 3);
}

void ChessCreator::fillFieldWithKings(ChessField *chessField) {
    this->fillFieldWithPieces(chessField, ChessConstants::KING_PIECE_TYPE, 2, 0, 4);
    this->fillFieldWithPieces(chessField, ChessConstants::KING_PIECE_TYPE, 1, 7, 4);
}

void ChessCreator::fillFieldWithBishops(ChessField *chessField) {
    this->fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 2, 0, 2);
    this->fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 2, 0, 5);

    this->fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 1, 7, 2);
    this->fillFieldWithPieces(chessField, ChessConstants::BISHOP_PIECE_TYPE, 1, 7, 5);
}

void ChessCreator::fillFieldWithKnights(ChessField *chessField) {
    this->fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 2, 0, 1);
    this->fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 2, 0, 6);

    this->fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 1, 7, 1);
    this->fillFieldWithPieces(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 1, 7, 6);
}

void ChessCreator::fillFieldWithRooks(ChessField *chessField) {
    this->fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 2, 0, 0);
    this->fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 2, 0, 7);

    this->fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 1, 7, 0);
    this->fillFieldWithPieces(chessField, ChessConstants::ROOK_PIECE_TYPE, 1, 7, 7);
}







