//
// Created by Julian Sommer on 18.09.23.
//

#include "InStalemateStatusChecker.h"
#include "../../GameApplication/Player/ChessPlayerData.h"
#include "../../Model/ChessField.h"
#include "../../Model/ChessCell.h"
#include "../../ChessPiece/BaseChessPiece.h"

bool InStalemateStatusChecker::isKingInStalemate(
    ChessField *chessField, ChessPlayerData *chessPlayerData, std::pair<int, int> kingPieceCoordinates) {

    if (this->hasKingPossibleMoves(chessField, kingPieceCoordinates)) {
        return false;
    }

    if (this->hasPlayerAnyMovesLeft(chessField, chessPlayerData)) {
        return false;
    }

    return true;
}

bool InStalemateStatusChecker::hasKingPossibleMoves(ChessField *chessField, std::pair<int, int> kingPieceCoordinates) {
    auto possibleMovesForKingPiece = chessField->getChessCell(kingPieceCoordinates)->getChessPiece()->determinePossibleMoves(chessField, kingPieceCoordinates);

    if (possibleMovesForKingPiece.empty()) {
        return false;
    }

    return true;
}

bool InStalemateStatusChecker::hasPlayerAnyMovesLeft(ChessField *chessField, ChessPlayerData *chessPlayerData) {
    auto queenPieces = chessPlayerData->getAllQueenPieces();
    if (this->checkPossibleMovesForSpecificPieces(chessField, queenPieces)) {
        return true;
    }

    auto knightPieces = chessPlayerData->getAllKnightPieces();
    if (this->checkPossibleMovesForSpecificPieces(chessField, knightPieces)) {
        return true;
    }

    auto bishopPieces = chessPlayerData->getAllBishopPieces();
    if (this->checkPossibleMovesForSpecificPieces(chessField, bishopPieces)) {
        return true;
    }

    auto rookPieces = chessPlayerData->getAllRookPieces();
    if (this->checkPossibleMovesForSpecificPieces(chessField, rookPieces)) {
        return true;
    }

    auto pawnPieces = chessPlayerData->getAllPawnPieces();
    if (this->checkPossibleMovesForSpecificPieces(chessField, pawnPieces)) {
        return true;
    }

    return false;
}

bool InStalemateStatusChecker::checkPossibleMovesForSpecificPieces(ChessField *chessField, std::vector<BaseChessPiece*> specificPieces) {
    for (auto &specificPiece : specificPieces) {
        if (!specificPiece->determinePossibleMoves(chessField, specificPiece->getCurrentCoordinates()).empty()) {
            return true;
        }
    }

    return false;
}