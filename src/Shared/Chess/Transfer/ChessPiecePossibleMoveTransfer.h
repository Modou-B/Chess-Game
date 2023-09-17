//
// Created by Julian Sommer on 17.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H

#include <string>

class ChessPiecePossibleMoveTransfer {
private:
    std::string moveType;

    int xCoordinate;
    int yCoordinate;

public:
    ChessPiecePossibleMoveTransfer &setMoveType(std::string moveType);
    ChessPiecePossibleMoveTransfer &setXCoordinate(int xCoordinate);
    ChessPiecePossibleMoveTransfer &setYCoordinate(int yCoordinate);

    std::string getMoveType();
    int getXCoordinate();
    int getYCoordinate();
};


#endif //CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H
