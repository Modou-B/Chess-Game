//
// Created by Julian Sommer on 18.09.23.
//

#ifndef CHESSAPPLICATION_INSTALEMATESTATUSCHECKER_H
#define CHESSAPPLICATION_INSTALEMATESTATUSCHECKER_H

#include <utility>

class ChessField;

class InStalemateStatusChecker {
public:
    bool isKingInStalemate(ChessField *chessField, std::pair<int, int> kingPieceCoordinates, int currentPlayer);
};

#endif // CHESSAPPLICATION_INSTALEMATESTATUSCHECKER_H
