//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONDATAREADER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONDATAREADER_H

#include <string>
#include <vector>

using namespace std;

class ChessGameStateTransfer;
class ChessPiecePositionTransfer;
class GameApplicationDataMapper;
class ChessMovementResponseTransfer;

class GameApplicationDataReader {
private:
    GameApplicationDataMapper *gameApplicationDataMapper;

public:
    GameApplicationDataReader(GameApplicationDataMapper *gameApplicationDataMapper);

    ChessGameStateTransfer *getCurrentGameStateData();
    ChessPiecePositionTransfer getKingPiecePositionByPlayer(int player);
    ChessMovementResponseTransfer getSavedChessMovementResponseTransfer();

    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    int getTurnCounter();
    string getCurrentGameState();

    bool isMultiplayerMatch();
    bool isOpponentTurn();
};

#endif // CHESSAPPLICATION_GAMEAPPLICATIONDATAREADER_H
