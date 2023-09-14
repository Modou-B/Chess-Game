//
// Created by Julian Sommer on 06.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATION_H
#define CHESSAPPLICATION_GAMEAPPLICATION_H

#include <utility>

class ChessField;
class ChessCell;

class GameApplication {
private:
    static ChessField *chessField;
    static int currentPlayer;
    static bool isTurnFinished;

    static bool wasCellWithChessPieceClickedValue;

    static std::pair<int, int> previouslyClickedCell;
    static bool hasPreviousClickedCell;

public:
    static int getCurrentPlayer();
    static ChessCell* getChessCell(std::pair<int, int> cellCoordinates);
    static ChessField* getChessField();
    static std::pair<int, int> getPreviouslyClickedCellCoordinates();

    static bool wasCellWithChessPieceClicked();
    static bool wasPreviousCellClicked();

    static void setChessField(ChessField* chessField);
    static void setPreviouslyClickedCellCoordinates(std::pair<int, int> currentCellCoordinates);

    void toggleCellWithChessPieceClickedValue();
    static void togglePreviousClickedCellValue();
    static void toggleCurrentPlayer();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATION_H
