//
// Created by Julian Sommer on 29.08.23.
//

#ifndef CHESSAPPLICATION_PAWNPIECE_H
#define CHESSAPPLICATION_PAWNPIECE_H

#include "BaseChessPiece.h"
#include <vector>
#include <utility>

class ChessPieceMovementGenerator;
class ChessPiecePossibleMoveTransfer;

class PawnPiece: public BaseChessPiece {
private:
    bool usedDoubleMove;

protected:
    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForPlayer1(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForPlayer2(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);

    std::vector<ChessPiecePossibleMoveTransfer*> checkForDoubleMove(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<ChessPiecePossibleMoveTransfer*> checkForDiagonalPieces(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);

    std::vector<ChessPiecePossibleMoveTransfer*> checkForEnPassant(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate, int yValueToAdd);

    bool isEnPassantPossible(ChessField *chessField, int xCoordinate, int yCoordinate);

    bool wasDoubleMoveUsed();
public:
    PawnPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator);

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) override;

    void handleMovement(ChessPiecePossibleMoveTransfer *usedMove) override;
};


#endif //CHESSAPPLICATION_PAWNPIECE_H
