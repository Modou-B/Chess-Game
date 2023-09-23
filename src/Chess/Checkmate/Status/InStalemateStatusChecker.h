//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_INSTALEMATESTATUSCHECKER_H
#define CHESSAPPLICATION_INSTALEMATESTATUSCHECKER_H

#include <utility>
#include <vector>

class ChessField;
class ChessPlayerData;
class BaseChessPiece;

class InStalemateStatusChecker {
protected:
    bool hasKingPossibleMoves(ChessField *chessField, std::pair<int, int> kingPieceCoordinates);

    bool hasPlayerAnyMovesLeft(ChessField *chessField, ChessPlayerData *chessPlayerData);

    bool checkPossibleMovesForSpecificPieces(ChessField *chessField, std::vector<BaseChessPiece*> specificPieces);

public:
    bool isKingInStalemate(ChessField *chessField, ChessPlayerData *chessPlayerData, std::pair<int, int> kingPieceCoordinates);
};

#endif // CHESSAPPLICATION_INSTALEMATESTATUSCHECKER_H
