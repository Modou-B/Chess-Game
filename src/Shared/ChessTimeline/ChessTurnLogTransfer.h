//
// Created by Julian Sommer on 25.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTURNLOGTRANSFER_H
#define CHESSAPPLICATION_CHESSTURNLOGTRANSFER_H

#include <vector>

using namespace std;

class ChessPieceInformationTransfer;
class ChessGameStateTransfer;

class ChessTurnLogTransfer {
private:
    ChessGameStateTransfer *chessGameStateTransfer;
    vector<ChessPieceInformationTransfer*> chessPieceInformationTransfers;

public:
    ChessTurnLogTransfer();

    ChessTurnLogTransfer *setChessGameStateTransfer(
        ChessGameStateTransfer *chessGameStateTransfer
    );
    ChessTurnLogTransfer *setChessPieceInformationTransfers(
        vector<ChessPieceInformationTransfer*> chessPieceInformationTransfers
    );

    void addChessPieceInformationTransfer(ChessPieceInformationTransfer *chessPieceInformationTransfer);

    ChessGameStateTransfer *getChessGameStateTransfer();
    vector<ChessPieceInformationTransfer*> getChessPieceInformationTransfers();
};

#endif // CHESSAPPLICATION_CHESSTURNLOGTRANSFER_H
