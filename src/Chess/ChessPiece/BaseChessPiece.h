//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_BASECHESSPIECE_H
#define CHESSAPPLICATION_BASECHESSPIECE_H

#include <string>

class BaseChessPiece {
private:
    std::string type;
    int player;
    std::pair<int, int> possibleMoves[25];
public:
    BaseChessPiece(std::string type, int player);

    void determinePossibleMoves();

    std::string getType();
};


#endif //CHESSAPPLICATION_BASECHESSPIECE_H
