//
// Created by Julian Sommer on 18.09.23.
//

#include "CheckmateManager.h"
#include "Status/InCheckStatusChecker.h"
#include "Status/InStalemateStatusChecker.h"
#include "Status/BareKingDrawStatusChecker.h"
#include "../Model/ChessField.h"
#include "../Model/ChessCell.h"
#include "../GameApplication/Player/ChessPlayerData.h"
#include "../ChessPiece/BaseChessPiece.h"
#include "../../Shared/Chess/Transfer/Checkmate/InCheckResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "iostream"

std::pair<int, int> CheckmateManager::player1KingPieceCoordinates;
std::pair<int, int> CheckmateManager::player2KingPieceCoordinates;

CheckmateManager::CheckmateManager(
    InCheckStatusChecker *inCheckStatusChecker, InStalemateStatusChecker *inStalemateStatusChecker, BareKingDrawStatusChecker *bareKingDrawStatusChecker) {

    this->inCheckStatusChecker = inCheckStatusChecker;
    this->inStalemateStatusChecker = inStalemateStatusChecker;
    this->bareKingDrawStatusChecker = bareKingDrawStatusChecker;
}


void CheckmateManager::determineCurrentGameState(ChessField *chessField, ChessPlayerData *currentChessPlayerData, ChessPlayerData *opponentChessPlayerData, int player) {
    auto kingPieceCoordinates = CheckmateManager::getKingPieceCoordinatesForPlayer(player);

    auto inCheckResponseTransfer = this->inCheckStatusChecker->getAmountOfPiecesThatCheckKing(
      chessField, kingPieceCoordinates, player);

    std::cout << inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() << std::endl;

    if (inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() > 0) {
        currentChessPlayerData->setInCheckStatus(true);

        this->isPlayerInCheckmate(chessField, kingPieceCoordinates, currentChessPlayerData, inCheckResponseTransfer, player);

        return;
    }

    currentChessPlayerData->setInCheckStatus(false);
    if (this->inStalemateStatusChecker->isKingInStalemate(
          chessField, currentChessPlayerData, CheckmateManager::getKingPieceCoordinatesForPlayer(player))
    ) {
        std::cout << "Stalemate" << std::endl;
        exit(1);
    }

    if (this->bareKingDrawStatusChecker->isCheckmateNotPossible(currentChessPlayerData, opponentChessPlayerData)) {
        std::cout << "Bare King" << std::endl;
        exit(1);
    }
}

void CheckmateManager::setKingPieceCoordinates(std::pair<int, int> kingPieceCoordinates, int player) {
    if (player == 1) {
        CheckmateManager::player1KingPieceCoordinates = kingPieceCoordinates;

        return;
    }

    CheckmateManager::player2KingPieceCoordinates = kingPieceCoordinates;
}

std::pair<int, int> CheckmateManager::getKingPieceCoordinatesForPlayer(int player) {
    if (player == 1) {
        return CheckmateManager::player1KingPieceCoordinates;
    }

    return CheckmateManager::player2KingPieceCoordinates;
}

bool CheckmateManager::isPlayerInCheckmate(
    ChessField *chessField, std::pair<int, int> kingPieceCoordinates, ChessPlayerData *chessPlayerData, InCheckResponseTransfer inCheckResponseTransfer, int currentPlayer) {
    auto possibleMovesForKingPiece = chessField->getChessCell(kingPieceCoordinates)->getChessPiece()->determinePossibleMoves(chessField, kingPieceCoordinates);

    int amountOfPiecesThatBlockCheck = this->inCheckStatusChecker->getAmountOfPiecesThatBlockCheck(chessField, chessPlayerData, inCheckResponseTransfer, kingPieceCoordinates, currentPlayer);
    if (possibleMovesForKingPiece.empty()) {
        if (inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() > 1) {
            std::cout << "Checkmate" << std::endl;
            exit(1);
        }

        if (amountOfPiecesThatBlockCheck == 0) {
            std::cout << "Checkmate2" << std::endl;
            exit(1);
        }
    }

    return false;
}