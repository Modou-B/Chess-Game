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
class GameApplicationDataWriter;
class GameApplicationDataReader;
class ChessTimelineFacade;
class ChessGuiFacade;
class ChessTurnLogTransfer;

class GameApplicationManager {
private:
    ChessCreator *chessCreator;
    ChessPieceMovementManager *chessPieceMovementManager;
    CheckmateManager *checkmateManager;
    GameApplicationDataWriter *gameApplicationDataWriter;
    GameApplicationDataReader *gameApplicationDataReader;
    ChessTimelineFacade *chessTimelineFacade;
    ChessGuiFacade *chessGuiFacade;

protected:
    void updateStateLastTurnChessPieces();
    void expandChessMovementResponseTransfer(
        ChessMovementResponseTransfer &chessMovementResponseTransfer
    );

    void expandChessMovementResponseTransferWithCurrentGameState(
        ChessMovementResponseTransfer &chessMovementResponseTransfer
    );
    void expandChessMovementResponseTransferWithPlayers(
        ChessMovementResponseTransfer &chessMovementResponseTransfer
    );

    void logCurrentTurn(ChessMovementResponseTransfer chessMovementResponseTransfer);

public:
    GameApplicationManager(
      ChessCreator *chessCreator,
      ChessPieceMovementManager* chessPieceMovementManager,
      CheckmateManager *checkmateManager,
      GameApplicationDataWriter *gameApplicationDataWriter,
      GameApplicationDataReader *gameApplicationDataReader,
      ChessTimelineFacade *chessTimelineFacade,
      ChessGuiFacade *chessGuiFacade
    );

    void initiateChessApplication();

    ChessMovementResponseTransfer handleChessCellClick(pair<int, int> currentCellCoordinates);
    void handlePawnPieceSwitch(string switchedPieceType);

    void endCurrentTurn(
        ChessMovementResponseTransfer chessMovementResponseTransfer,
        ChessPiecePositionTransfer chessPiecePositionTransfer
    );

    void rewindCurrentTurn(ChessTurnLogTransfer *chessTurnLogTransferToRewind);

    void startNewTurn();
    int getCurrentPlayer();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
