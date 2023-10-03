//
// Created by Julian Sommer on 03.10.23.
//

#ifndef CHESSAPPLICATION_ENDTURNINFORMATIONTRANSFER_H
#define CHESSAPPLICATION_ENDTURNINFORMATIONTRANSFER_H

#include <vector>

using namespace std;

class ChessPieceStateTransfer;

class EndTurnInformationTransfer {
private:
    int currentPlayer;
    int turnCounter;
    vector<ChessPieceStateTransfer*> chessPieceStateTransfers;

public:
    EndTurnInformationTransfer *setCurrentPlayer(int currentPlayer);
    EndTurnInformationTransfer *setTurnCounter(int turnCounter);
    EndTurnInformationTransfer *setChessPieceStateTransfers(vector<ChessPieceStateTransfer*> chessPieceStateTransfers);

    int getCurrentPlayer();
    int getTurnCounter();
    vector<ChessPieceStateTransfer*> getChessPieceStateTransfers();
};

#endif // CHESSAPPLICATION_ENDTURNINFORMATIONTRANSFER_H
