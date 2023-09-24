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

    bool hasKingMoved;
    bool hasPieceMoved;
    bool hasPossibleMoves;

    std::pair<int, int> currentCellCoordinates;

    std::vector<ChessPiecePossibleMoveTransfer*> *previousPossibleMoves;
    std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves;
    std::vector<ChessPieceMovementTransfer*> *chessPiecesToMove;

public:
    ChessMovementResponseTransfer();

    bool wasPieceMoved();
    bool doesPieceHasPossibleMoves();

    std::pair<int, int> getCurrentCellCoordinates();
    std::vector<ChessPiecePossibleMoveTransfer*> *getPossibleMoves();
    std::vector<ChessPiecePossibleMoveTransfer*> *getPreviousPossibleMoves();
    std::vector<ChessPieceMovementTransfer*> *getChessPiecesToMove();
    bool getHasKingMoved();

    std::string getState();

    void togglePieceMovementValue();
    void togglePossibleMovesCheckValue();

    ChessMovementResponseTransfer &addChessPieceMovementTransfer(ChessPieceMovementTransfer *chessPieceMovementTransfer);
    ChessMovementResponseTransfer &setCurrentCellCoordinates(std::pair<int, int> currentCellCoordinates);
    ChessMovementResponseTransfer &setHasKingMoved(bool value);

    void setState(std::string state);

    void setPossibleMoves(std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves);
    void setPreviousPossibleMoves(std::vector<ChessPiecePossibleMoveTransfer*> *previousPossibleMoves);
    void setPossibleMovesCheckValue(bool value);

};


#endif //CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
