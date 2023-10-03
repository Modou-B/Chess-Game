//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEINFORMATIONTRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEINFORMATIONTRANSFER_H

#include <string>

class ChessPieceStateTransfer;

class ChessPieceInformationTransfer {
private:
    std::string chessPieceColor;
    ChessPieceStateTransfer *chessPieceStateTransfer;

public:
    ChessPieceInformationTransfer *setChessPieceColor(std::string chessPieceColor);
    ChessPieceInformationTransfer *setChessPieceStateTransfer(ChessPieceStateTransfer *chessPieceStateTransfer);

    std::string getChessPieceColor();
    ChessPieceStateTransfer *getChessPieceStateTransfer();
};

#endif // CHESSAPPLICATION_CHESSPIECEINFORMATIONTRANSFER_H
