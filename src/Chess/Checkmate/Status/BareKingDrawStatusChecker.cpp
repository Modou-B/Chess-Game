//
// Created by Julian Sommer on 18.09.23.
//

#include "BareKingDrawStatusChecker.h"
#include "../../GameApplication/Player/ChessPlayerData.h"

bool BareKingDrawStatusChecker::isCheckmateNotPossible(ChessPlayerData *currentChessPlayerData, ChessPlayerData *opponentChessPlayerData) {
    if (currentChessPlayerData->getChessPieceAmount() > 1) {
        return false;
    }

    if (currentChessPlayerData->getChessPieceAmount() == 1 && opponentChessPlayerData->getChessPieceAmount() == 1) {
        return true;
    }

    if (opponentChessPlayerData->getChessPieceAmount() == 2 && this->hasOpponentOnlyKnightOrBishopLeft(opponentChessPlayerData)) {
        return true;
    }

    return false;
}

bool BareKingDrawStatusChecker::hasOpponentOnlyKnightOrBishopLeft(ChessPlayerData *opponentChessPlayerData) {
    if (opponentChessPlayerData->getAllBishopPieces().size() == 1) {
        return true;
    }

    if (opponentChessPlayerData->getAllKnightPieces().size() == 1) {
        return true;
    }

    return false;
}

