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

    static bool wasCellWithChessPieceClickedValue;

    static std::pair<int, int> previouslyClickedCell;

public:
    static int getCurrentPlayer();
    static ChessCell* getChessCell(std::pair<int, int> cellCoordinates);
    static bool wasCellWithChessPieceClicked();
    static std::pair<int, int> getPreviouslyClickedCellCoordinates();

    static void setChessField(ChessField* chessField);
    static void setCurrentPlayer(int player);

    void toggleCellWithChessPieceClickedValue();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATION_H
