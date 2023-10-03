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

class GameApplicationDataReader {
private:
    GameApplicationDataMapper *gameApplicationDataMapper;

public:
    GameApplicationDataReader(GameApplicationDataMapper *gameApplicationDataMapper);

    ChessGameStateTransfer getCurrentGameStateData();
    ChessPiecePositionTransfer getKingPiecePositionByPlayer(int player);

    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    int getTurnCounter();
};

#endif // CHESSAPPLICATION_GAMEAPPLICATIONDATAREADER_H
