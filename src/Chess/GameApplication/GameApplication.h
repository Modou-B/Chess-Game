//
// Created by Julian Sommer on 06.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATION_H
#define CHESSAPPLICATION_GAMEAPPLICATION_H

#include <utility>

class ChessField;
class ChessCell;
class ChessPlayerData;

class GameApplication {
private:
    static ChessField *chessField;
    static ChessPlayerData *chessPlayer1Data;
    static ChessPlayerData *chessPlayer2Data;

    static int currentPlayer;
    static int turnCounter;

    static std::pair<int, int> previouslyClickedCell;
    static bool hasPreviousClickedCell;

    static std::pair<int, int> coordinatesOfLastTurnClickedCell;
public:
    static int getCurrentPlayer();
    static ChessCell* getChessCell(std::pair<int, int> cellCoordinates);
    static ChessField* getChessField();
    static std::pair<int, int> getPreviouslyClickedCellCoordinates();
    static std::pair<int, int> getCoordinatesOfLastTurnClickedCell();
    static int getTurnCounter();
    static ChessPlayerData *getCurrentChessPlayerData();
    static ChessPlayerData *getOpponentChessPlayerData();
    static ChessPlayerData *getChessPlayerDataForPlayer(int player);

    static bool wasPreviousCellClicked();

    static void setChessField(ChessField* chessField);
    static void setChessPlayer1Data(ChessPlayerData* chessPlayerData);
    static void setChessPlayer2Data(ChessPlayerData* chessPlayerData);

    static void setPreviouslyClickedCellCoordinates(std::pair<int, int> currentCellCoordinates);
    static void setCoordinatesOfLastTurnClickedCell(std::pair<int, int> lastTurnClickedCell);

    static void togglePreviousClickedCellValue();
    static void toggleCurrentPlayer();
    static void increaseTurnCounter();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATION_H
