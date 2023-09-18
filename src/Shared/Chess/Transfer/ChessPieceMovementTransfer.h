//
// Created by Julian Sommer on 16.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTTRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTTRANSFER_H

#include <utility>
#include <string>

class ChessPieceMovementTransfer {
private:
    std::string action;

    std::pair<int, int> oldCoordinates;
    std::pair<int, int> newCoordinates;
public:
    ChessPieceMovementTransfer &setAction(std::string action);
    ChessPieceMovementTransfer &setOldCoordinates(std::pair<int, int> oldCoordinates);
    ChessPieceMovementTransfer &setNewCoordinates(std::pair<int, int> newCoordinates);

    std::string getAction();
    std::pair<int, int> getOldCoordinates();
    std::pair<int, int> getNewCoordinates();
};


#endif //CHESSAPPLICATION_CHESSPIECEMOVEMENTTRANSFER_H
