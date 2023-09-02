//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECETRANSFER_H
#define CHESSAPPLICATION_CHESSPIECETRANSFER_H

#include <string>

class ChessPieceTransfer {
private:
    std::string type;
    int player;

public:
    std::string getType();

    int getPlayer();

    ChessPieceTransfer &setType(std::string type);

    ChessPieceTransfer &setPlayer(int player);
};


#endif //CHESSAPPLICATION_CHESSPIECETRANSFER_H
