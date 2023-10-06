//
// Created by Julian Sommer on 03.10.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONDATAWRITER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONDATAWRITER_H

#include <string>

using namespace std;

class GameApplicationDataMapper;
class ChessGameStateTransfer;
class ChessMovementResponseTransfer;
class ChessTurnLogTransfer;
class BaseChessPiece;

class GameApplicationDataWriter {
private:
    GameApplicationDataMapper *gameApplicationDataMapper;

public:
    GameApplicationDataWriter(
      GameApplicationDataMapper *gameApplicationDataMapper
    );

    void updateGameApplicationData(ChessGameStateTransfer *chessGameStateTransfer);

    void updateGameApplicationCurrentGameState(string gameState);

    void saveChessMovementResponseTransfer(ChessMovementResponseTransfer chessMovementResponseTransfer);
    void saveChessPieceForChessPlayerData(
        BaseChessPiece *chessPiece,
        string type,
        int player
    );
};

#endif // CHESSAPPLICATION_GAMEAPPLICATIONDATAWRITER_H
