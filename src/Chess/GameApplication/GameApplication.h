//
// Created by Julian Sommer on 06.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATION_H
#define CHESSAPPLICATION_GAMEAPPLICATION_H

#include <utility>
#include <string>

using namespace std;

class ChessField;
class ChessCell;
class ChessPlayerData;
class ChessMovementResponseTransfer;

class GameApplication {
private:
    static ChessField *chessField;
    static ChessPlayerData *chessPlayer1Data;
    static ChessPlayerData *chessPlayer2Data;

    static ChessMovementResponseTransfer savedChessMovementResponseTransfer;
    static string currentGameState;
    
    static int currentPlayer;
    static int currentOpponentPlayer;

    static int turnCounter;

    static pair<int, int> previouslyClickedCell;
    static bool hasPreviousClickedCell;

    static pair<int, int> coordinatesOfLastTurnClickedCell;
public:
    static ChessCell* getChessCell(pair<int, int> cellCoordinates);
    static ChessField* getChessField();
    static pair<int, int> getPreviouslyClickedCellCoordinates();
    static pair<int, int> getCoordinatesOfLastTurnClickedCell();
    static ChessPlayerData *getCurrentChessPlayerData();
    static ChessPlayerData *getOpponentChessPlayerData();
    static ChessPlayerData *getChessPlayerDataForPlayer(int player);

    static bool wasPreviousCellClicked();

    static void setChessField(ChessField* chessField);
    static void setChessPlayer1Data(ChessPlayerData* chessPlayerData);
    static void setChessPlayer2Data(ChessPlayerData* chessPlayerData);
    static void setCurrentPlayer(int currentPlayer);
    static void setCurrentOpponentPlayer(int currentOpponentPlayer);
    static void setTurnCounter(int turnCounter);
    static void setCurrentGameState(string gameState);
    static void saveChessMovementResponseTransfer(
        ChessMovementResponseTransfer chessMovementResponseTransfer
    );
    static void setHasPreviousClickedCell(bool value);
    
    static void setPreviouslyClickedCellCoordinates(pair<int, int> currentCellCoordinates);
    static void setCoordinatesOfLastTurnClickedCell(pair<int, int> lastTurnClickedCell);

    static void togglePreviousClickedCellValue();
    static void toggleCurrentPlayer();
    static void switchPlayers();

    static void increaseTurnCounter();

    static string getCurrentGameState();
    static ChessMovementResponseTransfer getSavedChessMovementResponseTransfer();
    static int getCurrentPlayer();
    static int getCurrentOpponentPlayer();
    static int getTurnCounter();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATION_H
