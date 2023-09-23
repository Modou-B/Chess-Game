//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H

#include <utility>

class ChessField;
class ChessCreator;
class ChessPieceMovementManager;
class CheckmateManager;
class ChessMovementResponseTransfer;

class GameApplicationManager {
private:
    ChessCreator *chessCreator;
    ChessPieceMovementManager *chessPieceMovementManager;
    CheckmateManager *checkmateManager;

protected:
    void updateStateLastTurnChessPieces();

public:
    GameApplicationManager(
      ChessCreator *chessCreator, ChessPieceMovementManager* chessPieceMovementManager, CheckmateManager *checkmateManager);

    void initiateChessApplication();

    ChessMovementResponseTransfer handleChessCellClick(std::pair<int, int> currentCellCoordinates);
    void handlePawnPieceSwitch(ChessMovementResponseTransfer chessMovementResponseTransfer, std::string switchedPieceType);

    void endCurrentTurn(ChessMovementResponseTransfer chessMovementResponseTransfer);
    void startNewTurn();
    int getCurrentPlayer();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
