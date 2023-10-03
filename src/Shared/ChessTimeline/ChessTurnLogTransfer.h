//
// Created by Julian Sommer on 25.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTURNLOGTRANSFER_H
#define CHESSAPPLICATION_CHESSTURNLOGTRANSFER_H

#include <vector>

using namespace std;

class ChessPieceInformationTransfer;

class ChessTurnLogTransfer {
private:
    int currentPlayer;
    int turnCounter;
    vector<ChessPieceInformationTransfer*> chessPieceInformationTransfers;

public:
    ChessTurnLogTransfer();

    ChessTurnLogTransfer *setCurrentPlayer(int currentPlayer);
    ChessTurnLogTransfer *setTurnCounter(int turnCounter);
    ChessTurnLogTransfer *setChessPieceInformationTransfers(
        vector<ChessPieceInformationTransfer*> chessPieceInformationTransfers
    );

    void addChessPieceInformationTransfer(ChessPieceInformationTransfer *chessPieceInformationTransfer);

    int getCurrentPlayer();
    int getTurnCounter();
    vector<ChessPieceInformationTransfer*> getChessPieceInformationTransfers();
};

#endif // CHESSAPPLICATION_CHESSTURNLOGTRANSFER_H
