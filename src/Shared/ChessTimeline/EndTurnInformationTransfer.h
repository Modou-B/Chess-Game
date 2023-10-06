//
// Created by Julian Sommer on 03.10.23.
//

#ifndef CHESSAPPLICATION_ENDTURNINFORMATIONTRANSFER_H
#define CHESSAPPLICATION_ENDTURNINFORMATIONTRANSFER_H

#include <vector>

using namespace std;

class ChessPieceStateTransfer;
class ChessGameStateTransfer;

class EndTurnInformationTransfer {
private:
    ChessGameStateTransfer *chessGameStateTransfer;
    vector<ChessPieceStateTransfer*> chessPieceStateTransfers;

public:
    EndTurnInformationTransfer *setChessGameStateTransfer(ChessGameStateTransfer *chessGameStateTransfer);
    EndTurnInformationTransfer *setChessPieceStateTransfers(vector<ChessPieceStateTransfer*> chessPieceStateTransfers);

    ChessGameStateTransfer *getChessGameStateTransfer();
    vector<ChessPieceStateTransfer*> getChessPieceStateTransfers();
};

#endif // CHESSAPPLICATION_ENDTURNINFORMATIONTRANSFER_H
