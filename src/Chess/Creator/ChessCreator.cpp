//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCreator.h"
#include "../../Application/Resolver/FactoryResolverTrait.h"
#include "../ChessFactory.h"
#include "../ChessPiece/BishopPiece.h"
#include "../Movement/Mapper/ChessPieceMovementMapper.h"
#include "../ChessPiece/KingPiece.h"
#include "../ChessPiece/KnightPiece.h"
#include "../Movement/KingPiece/KingPieceMovementChecker.h"
#include "../ChessPiece/PawnPiece.h"
#include "../ChessPiece/QueenPiece.h"
#include "../ChessPiece/RookPiece.h"
#include "../GameApplication/Player/ChessPlayerData.h"
#include "../GameApplication/Reader/GameApplicationDataReader.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include "../Shared/Chess/ChessConstants.h"
#include <utility>

BaseChessPiece *ChessCreator::createChessPiece(std::string type, int player) {
    if (type == ChessConstants::PAWN_PIECE_TYPE) {
        return new PawnPiece(player, this->getChessPieceMovementMapper(), this->getKingPieceMovementChecker());
    }
    if (type == ChessConstants::KNIGHT_PIECE_TYPE) {
        return new KnightPiece(player, this->getChessPieceMovementMapper(), this->getKingPieceMovementChecker());
    }
    if (type == ChessConstants::KING_PIECE_TYPE) {
        return new KingPiece(player, this->getChessPieceMovementMapper(), this->getKingPieceMovementChecker());
    }
    if (type == ChessConstants::ROOK_PIECE_TYPE) {
        return new RookPiece(player, this->getChessPieceMovementMapper(), this->getKingPieceMovementChecker());
    }
    if (type == ChessConstants::QUEEN_PIECE_TYPE) {
        return new QueenPiece(player, this->getChessPieceMovementMapper(), this->getKingPieceMovementChecker());
    }
    if (type == ChessConstants::BISHOP_PIECE_TYPE) {
        return new BishopPiece(player, this->getChessPieceMovementMapper(), this->getKingPieceMovementChecker());
    }

    return nullptr;
}

ChessCell *ChessCreator::createChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates) {
    return new ChessCell(chessPiece,coordinates);
}

void ChessCreator::initiateChessData(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    this->fillFieldWithEmptyCells(chessField);
    this->addChessPiecesToFieldCellsAndPlayerData(chessField, chessPlayerData1, chessPlayerData2);
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

void ChessCreator::addChessPiecesToFieldCellsAndPlayerData(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    this->fillFieldAndPlayerDataWithPawns(chessField, chessPlayerData1, chessPlayerData2);
    this->fillFieldAndPlayerDataWithQueens(chessField, chessPlayerData1, chessPlayerData2);
    this->fillFieldAndPlayerDataWithKings(chessField, chessPlayerData1, chessPlayerData2);
    this->fillFieldAndPlayerDataWithBishops(chessField, chessPlayerData1, chessPlayerData2);
    this->fillFieldAndPlayerDataWithKnights(chessField, chessPlayerData1, chessPlayerData2);
    this->fillFieldAndPlayerDataWithRooks(chessField, chessPlayerData1, chessPlayerData2);
}

BaseChessPiece *ChessCreator::addPieceToField(ChessField *chessField, std::string pieceType, int player, int row, int column) {
        std::pair<int, int> coordinates = std::make_pair(row, column);
        auto *piecePlayer = this->createChessPiece(pieceType, player);
        piecePlayer->setCurrentCoordinates(coordinates);

        ChessCell *rowChessCell = chessField->getChessCell(coordinates);
        rowChessCell->setChessPiece(piecePlayer);

        return piecePlayer;
}

void ChessCreator::fillFieldAndPlayerDataWithPawns(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    for (int i = 0; i < 8; i++) {
        auto pawnPiece = this->addPieceToField(chessField, ChessConstants::PAWN_PIECE_TYPE, 2, 1, i);
        chessPlayerData2->addPawnPiece(pawnPiece);

        pawnPiece = this->addPieceToField(chessField, ChessConstants::PAWN_PIECE_TYPE, 1, 6, i);
        chessPlayerData1->addPawnPiece(pawnPiece);
    }
}

void ChessCreator::fillFieldAndPlayerDataWithQueens(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    auto queenPiece = this->addPieceToField(chessField, ChessConstants::QUEEN_PIECE_TYPE, 2, 0, 3);
    chessPlayerData2->addQueenPiece(queenPiece);

    queenPiece = this->addPieceToField(chessField, ChessConstants::QUEEN_PIECE_TYPE, 1, 7, 3);
    chessPlayerData1->addQueenPiece(queenPiece);

}

void ChessCreator::fillFieldAndPlayerDataWithKings(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    auto kingPiece = this->addPieceToField(chessField, ChessConstants::KING_PIECE_TYPE, 2, 0, 4);
    chessPlayerData2->setKingPiece(kingPiece);

    kingPiece = this->addPieceToField(chessField, ChessConstants::KING_PIECE_TYPE, 1, 7, 4);
    chessPlayerData1->setKingPiece(kingPiece);
}

void ChessCreator::fillFieldAndPlayerDataWithBishops(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    auto bishopPiece = this->addPieceToField(chessField, ChessConstants::BISHOP_PIECE_TYPE, 2, 0, 2);
    chessPlayerData2->addBishopPiece(bishopPiece);

    bishopPiece = this->addPieceToField(chessField, ChessConstants::BISHOP_PIECE_TYPE, 2, 0, 5);
    chessPlayerData2->addBishopPiece(bishopPiece);

    bishopPiece = this->addPieceToField(chessField, ChessConstants::BISHOP_PIECE_TYPE, 1, 7, 2);
    chessPlayerData1->addBishopPiece(bishopPiece);

    bishopPiece = this->addPieceToField(chessField, ChessConstants::BISHOP_PIECE_TYPE, 1, 7, 5);
    chessPlayerData1->addBishopPiece(bishopPiece);
}

void ChessCreator::fillFieldAndPlayerDataWithKnights(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    auto knightPiece = this->addPieceToField(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 2, 0, 1);
    chessPlayerData2->addKnightPiece(knightPiece);

    knightPiece = this->addPieceToField(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 2, 0, 6);
    chessPlayerData2->addKnightPiece(knightPiece);

    knightPiece = this->addPieceToField(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 1, 7, 1);
    chessPlayerData1->addKnightPiece(knightPiece);

    knightPiece = this->addPieceToField(chessField, ChessConstants::KNIGHT_PIECE_TYPE, 1, 7, 6);
    chessPlayerData1->addKnightPiece(knightPiece);
}

void ChessCreator::fillFieldAndPlayerDataWithRooks(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2) {
    auto rookPiece = this->addPieceToField(chessField, ChessConstants::ROOK_PIECE_TYPE, 2, 0, 0);
    chessPlayerData2->addRookPiece(rookPiece);

    rookPiece = this->addPieceToField(chessField, ChessConstants::ROOK_PIECE_TYPE, 2, 0, 7);
    chessPlayerData2->addRookPiece(rookPiece);

    rookPiece = this->addPieceToField(chessField, ChessConstants::ROOK_PIECE_TYPE, 1, 7, 0);
    chessPlayerData1->addRookPiece(rookPiece);

    rookPiece = this->addPieceToField(chessField, ChessConstants::ROOK_PIECE_TYPE, 1, 7, 7);
    chessPlayerData1->addRookPiece(rookPiece);
}

ChessPieceMovementMapper *ChessCreator::getChessPieceMovementMapper() {
    return this->getFactory()->createChessPieceMovementMapper();
}

KingPieceMovementChecker *ChessCreator::getKingPieceMovementChecker() {
    return this->getFactory()->createKingPieceMovementChecker();
}

ChessFactory *ChessCreator::getFactory() {
    return static_cast<ChessFactory*>(FactoryResolverTrait::findFactory(typeid(ChessFactory).name()));
}