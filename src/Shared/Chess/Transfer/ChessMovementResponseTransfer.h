//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
#define CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H

#include <utility>
#include <string>
#include <vector>

class ChessPieceMovementTransfer;
class ChessPiecePossibleMoveTransfer;

class ChessMovementResponseTransfer {
private:
    std::string state;

    bool hasPieceMoved;
    std::pair<int, int> currentCellCoordinates;

    bool hasPossibleMoves;
    std::vector<ChessPiecePossibleMoveTransfer*> *previousPossibleMoves;
    std::vector<ChessPiecePossibleMoveTransfer*> *possibleMoves;

    std::vector<ChessPieceMovementTransfer*> *chessPiecesToMove;
public:
    ChessMovementResponseTransfer();

    bool wasPieceMoved();
    bool doesPieceHasPossibleMoves();

    std::pair<int, int> getCurrentCellCoordinates();
    std::vector<ChessPiecePossibleMoveTransfer*> *getPossibleMoves();
    std::vector<ChessPiecePossibleMoveTransfer*> *getPreviousPossibleMoves();
    std::vector<ChessPieceMovementTransfer*> *getChessPiecesToMove();

    std::string getState();

    void togglePieceMovementValue();
    void togglePossibleMovesCheckValue();

    ChessMovementResponseTransfer &addChessPieceMovementTransfer(ChessPieceMovementTransfer *chessPieceMovementTransfer);
    ChessMovementResponseTransfer &setCurrentCellCoordinates(std::pair<int, int> currentCellCoordinates);

    void setState(std::string state);

    void setPossibleMoves(std::vector<ChessPiecePossibleMoveTransfer*> *possibleMoves);
    void setPreviousPossibleMoves(std::vector<ChessPiecePossibleMoveTransfer*> *previousPossibleMoves);
};


#endif //CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
