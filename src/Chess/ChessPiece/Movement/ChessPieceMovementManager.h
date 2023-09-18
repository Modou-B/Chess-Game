//
// Created by Julian Sommer on 16.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTMANAGER_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTMANAGER_H

#include <utility>

class ChessField;
class ChessCreator;
class ChessCell;
class ChessMovementResponseTransfer;
class ChessPiecePossibleMoveTransfer;
class ChessPieceMovementGenerator;
class BaseChessPiece;

class ChessPieceMovementManager {
private:
    static std::vector<ChessPiecePossibleMoveTransfer*> previousPossibleMovesForClickedCell;
    static std::vector<ChessPiecePossibleMoveTransfer*> possibleMovesForClickedCell;

    ChessPieceMovementGenerator *chessPieceMovementGenerator;
protected:
    ChessMovementResponseTransfer handleMovementWithoutPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);
    ChessMovementResponseTransfer handleMovementWithPreviousClickedCell(ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);

    ChessMovementResponseTransfer moveChessPiece(
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPiecePossibleMoveTransfer *usedMove);

    ChessMovementResponseTransfer addEnPassantChessPieceMovement(
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);

    ChessMovementResponseTransfer saveClickedCellCoordinates(std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer);
    ChessMovementResponseTransfer savePossibleMovesForClickedPiece(BaseChessPiece *clickedChessPiece, std::pair<int, int> currentCellCoordinates, ChessMovementResponseTransfer chessMovementResponseTransfer);

    bool doesChessPieceBelongToCurrentPlayer(BaseChessPiece *currentChessPiece);

public:
    ChessPieceMovementManager(ChessPieceMovementGenerator *chessPieceMovementGenerator);

    ChessMovementResponseTransfer handleChessMovement(std::pair<int, int> currentCellCoordinates);

    void clearPossibleMoveCollections();
};


#endif //CHESSAPPLICATION_CHESSPIECEMOVEMENTMANAGER_H
