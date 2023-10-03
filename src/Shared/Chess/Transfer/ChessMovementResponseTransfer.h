//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
#define CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H

#include <utility>
#include <string>
#include <vector>

using namespace std;

class ChessPieceMovementTransfer;
class ChessPiecePossibleMoveTransfer;
class ChessPieceStateTransfer;

class ChessMovementResponseTransfer {
private:
    string state;
    int currentPlayer;
    int currentOpponentPlayer;

    vector<ChessPiecePossibleMoveTransfer *> previousPossibleMoveTransfers;
    vector<ChessPiecePossibleMoveTransfer *> possibleMoveTransfers;

    vector<ChessPieceStateTransfer *> chessPieceStateTransfers;

public:
    ChessMovementResponseTransfer();

    ChessMovementResponseTransfer *setState(string state);
    ChessMovementResponseTransfer *setCurrentPlayer(int player);
    ChessMovementResponseTransfer *setCurrentOpponentPlayer(int player);
    ChessMovementResponseTransfer *setPreviousPossibleMoveTransfers(vector<ChessPiecePossibleMoveTransfer *> possibleMoves);
    ChessMovementResponseTransfer *setPossibleMoveTransfers(vector<ChessPiecePossibleMoveTransfer *> possibleMoves);
    ChessMovementResponseTransfer *setChessPieceStateTransfers(vector<ChessPieceStateTransfer *> chessPieceStateTransfers);

    void addChessPieceStateTransfer(ChessPieceStateTransfer *chessPieceStateTransfer);

    string getState();
    int getCurrentPlayer();
    int getCurrentOpponentPlayer();
    vector<ChessPiecePossibleMoveTransfer *> getPreviousPossibleMoveTransfers();
    vector<ChessPiecePossibleMoveTransfer *> getPossibleMoveTransfers();
    vector<ChessPieceStateTransfer *> getChessPieceStateTransfers();

};


#endif //CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
