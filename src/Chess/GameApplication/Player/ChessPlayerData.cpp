//
// Created by Julian Sommer on 22.09.23.
//

#include "ChessPlayerData.h"
#include "../../../Shared/Chess/ChessConstants.h"
#include "../../ChessPiece/BaseChessPiece.h"

ChessPlayerData::ChessPlayerData() {
    this->chessPieceAmount = 16;
    this->isInCheck = false;
    this->activePawnPieces = new std::vector<BaseChessPiece*>;
    this->activeRookPieces = new std::vector<BaseChessPiece*>;
    this->activeKnightPieces = new std::vector<BaseChessPiece*>;
    this->activeBishopPieces = new std::vector<BaseChessPiece*>;
    this->activeQueenPieces = new std::vector<BaseChessPiece*>;
}

void ChessPlayerData::addPieceByType(BaseChessPiece *chessPiece, std::string pieceType) {
    if (pieceType == ChessConstants::PAWN_PIECE_TYPE) {
        this->activePawnPieces->push_back(chessPiece);
    }

    if (pieceType == ChessConstants::ROOK_PIECE_TYPE) {
        this->activeRookPieces->push_back(chessPiece);
    }

    if (pieceType == ChessConstants::KNIGHT_PIECE_TYPE) {
        this->activeKnightPieces->push_back(chessPiece);
    }

    if (pieceType == ChessConstants::BISHOP_PIECE_TYPE) {
        this->activeBishopPieces->push_back(chessPiece);
    }

    if (pieceType == ChessConstants::QUEEN_PIECE_TYPE) {
        this->activeQueenPieces->push_back(chessPiece);
    }

    if (pieceType == ChessConstants::KING_PIECE_TYPE) {
        this->activeKingPiece = chessPiece;
    }
}

void ChessPlayerData::addPawnPiece(BaseChessPiece *pawnPiece) {
    this->activePawnPieces->push_back(pawnPiece);
}

void ChessPlayerData::addRookPiece(BaseChessPiece *rookPiece) {
    this->activeRookPieces->push_back(rookPiece);
}

void ChessPlayerData::addKnightPiece(BaseChessPiece *knightPiece) {
    this->activeKnightPieces->push_back(knightPiece);
}

void ChessPlayerData::addBishopPiece(BaseChessPiece *bishopPiece) {
    this->activeBishopPieces->push_back(bishopPiece);
}

void ChessPlayerData::addQueenPiece(BaseChessPiece *queenPiece) {
    this->activeQueenPieces->push_back(queenPiece);
}

void ChessPlayerData::setKingPiece(BaseChessPiece *kingPiece) {
    this->activeKingPiece = kingPiece;
}

void ChessPlayerData::setInCheckStatus(bool value) {
    this->isInCheck = value;
}

std::vector<BaseChessPiece*> ChessPlayerData::getAllPawnPieces() {
    return *this->activePawnPieces;
}

std::vector<BaseChessPiece*> ChessPlayerData::getAllRookPieces() {
    return *this->activeRookPieces;
}

std::vector<BaseChessPiece*> ChessPlayerData::getAllKnightPieces() {
    return *this->activeKnightPieces;
}

std::vector<BaseChessPiece *> ChessPlayerData::getAllBishopPieces() {
    return *this->activeBishopPieces;
}

std::vector<BaseChessPiece *> ChessPlayerData::getAllQueenPieces() {
    return *this->activeQueenPieces;
}

BaseChessPiece *ChessPlayerData::getKingPiece() {
    return this->activeKingPiece;
}

int ChessPlayerData::getChessPieceAmount() {
    return this->chessPieceAmount;
}

bool ChessPlayerData::isPlayerInCheck() {
    return this->isInCheck;
}

void ChessPlayerData::removePiece(BaseChessPiece *chessPiece) {
    auto *activeChessPieces = this->getChessPiecesForType(chessPiece->getType());

    for (int i = 0; i < activeChessPieces->size(); i++) {
        if (activeChessPieces->at(i) == chessPiece) {
            activeChessPieces->erase(activeChessPieces->begin()+ i);
            this->chessPieceAmount--;

            return;
        }
    }
}

std::vector<BaseChessPiece*> *ChessPlayerData::getChessPiecesForType(std::string pieceType) {
    if (pieceType == ChessConstants::PAWN_PIECE_TYPE) {
        return this->activePawnPieces;
    }

    if (pieceType == ChessConstants::ROOK_PIECE_TYPE) {
        return this->activeRookPieces;
    }

    if (pieceType == ChessConstants::KNIGHT_PIECE_TYPE) {
        return this->activeKnightPieces;
    }

    if (pieceType == ChessConstants::BISHOP_PIECE_TYPE) {
        return this->activeBishopPieces;
    }

    if (pieceType == ChessConstants::QUEEN_PIECE_TYPE) {
        return this->activeQueenPieces;
    }

    return {};
}