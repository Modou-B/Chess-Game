//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H

#include <utility>

class ChessField;
class ChessCreator;
class ChessCell;
class ChessMovementResponseTransfer;
class BaseChessPiece;

class GameApplicationManager {
private:
    ChessCreator *chessCreator;

    static std::vector<std::pair<int, int>> possibleMovesForClickedCell;

protected:
    void endCurrentTurn();

public:
    GameApplicationManager(ChessCreator *chessCreator);

    void initiateChessApplication();

    ChessMovementResponseTransfer handleChessMovement(std::pair<int, int> currentCellCoordinates);
    ChessMovementResponseTransfer handleMovementWithoutPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);
    ChessMovementResponseTransfer handleMovementWithPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);

    ChessMovementResponseTransfer moveChessPiece(ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);

    ChessMovementResponseTransfer saveClickedCellCoordinates(std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer);
    void savePossibleMovesForClickedPiece(BaseChessPiece *clickedChessPiece, std::pair<int, int> currentCellCoordinates);

    bool doesChessPieceBelongToCurrentPlayer(BaseChessPiece *currentChessPiece);
};


#endif //CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
