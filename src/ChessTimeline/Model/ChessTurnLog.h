//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTURNLOG_H
#define CHESSAPPLICATION_CHESSTURNLOG_H

#include <vector>
#include <utility>
#include <string>

using namespace std;

class ChessPieceLog;

class ChessTurnLog {
private:
    string currentGameState;
    int currentPlayer;
    int currentOpponentPlayer;
    int turnCounter;
    pair<int, int> coordinateOfLastTurnClickedCell;
    vector<ChessPieceLog *> *chessPieceLogs;

public:
    ChessTurnLog(
      string currentGameState,
      int currentPlayer,
      int currentOpponentPlayer,
      int turnCounter,
      vector<ChessPieceLog*> *chessPieceLogs
    );
    ChessTurnLog();

    void setCurrentGameState(string gameState);
    void setCurrentPlayer(int player);
    void setCurrentOpponentPlayer(int player);
    void setTurnCounter(int turnCounter);
    void setCoordinateOfLastTurnClickedCell(
        pair<int, int> coordinateOfLastTurnClickedCell
    );
    void setChessPieceLogs(vector<ChessPieceLog *> *chessPieceLogs);

    string getCurrentGameState();
    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    int getTurnCounter();
    pair<int, int> getCoordinateOfLastTurnClickedCell();
    vector<ChessPieceLog*> *getChessPieceLogs();
};

#endif // CHESSAPPLICATION_CHESSTURNLOG_H
