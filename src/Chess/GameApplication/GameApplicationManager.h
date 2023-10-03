//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H

#include <utility>
#include <string>

using namespace std;

class ChessField;
class ChessCreator;
class ChessPieceMovementManager;
class CheckmateManager;
class ChessMovementResponseTransfer;
class ChessPiecePositionTransfer;
class GameApplicationDataReader;
class ChessTimelineFacade;

class GameApplicationManager {
private:
    ChessCreator *chessCreator;
    ChessPieceMovementManager *chessPieceMovementManager;
    CheckmateManager *checkmateManager;
    GameApplicationDataReader *gameApplicationDataReader;
    ChessTimelineFacade *chessTimelineFacade;

protected:
    void updateStateLastTurnChessPieces();
    void expandChessMovementResponseTransferWithPlayers(
        ChessMovementResponseTransfer &chessMovementResponseTransfer
    );

    void logCurrentTurn(ChessMovementResponseTransfer chessMovementResponseTransfer);

public:
    GameApplicationManager(
      ChessCreator *chessCreator,
      ChessPieceMovementManager* chessPieceMovementManager,
      CheckmateManager *checkmateManager,
      GameApplicationDataReader *gameApplicationDataReader,
      ChessTimelineFacade *chessTimelineFacade
    );

    void initiateChessApplication();

    ChessMovementResponseTransfer handleChessCellClick(pair<int, int> currentCellCoordinates);
    void handlePawnPieceSwitch(ChessPiecePositionTransfer chessPiecePositionTransfer, string switchedPieceType);

    void endCurrentTurn(
        ChessMovementResponseTransfer chessMovementResponseTransfer,
        ChessPiecePositionTransfer chessPiecePositionTransfer
    );
    void startNewTurn();
    int getCurrentPlayer();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
