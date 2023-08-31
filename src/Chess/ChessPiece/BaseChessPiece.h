//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_BASECHESSPIECE_H
#define CHESSAPPLICATION_BASECHESSPIECE_H

#include <utility>
#include <string>

class Chess;

class BaseChessPiece {
private:
    std::string type;
    int player;
    int xCoordinate;
    int yCoordinate;
    std::pair<int, int> possibleMoves[25];
public:
    explicit BaseChessPiece(std::string type);

    void determinePossibleMoves();

    std::string getType();
};


#endif //CHESSAPPLICATION_BASECHESSPIECE_H
