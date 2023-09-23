//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSFIELD_H
#define CHESSAPPLICATION_CHESSFIELD_H

#include <utility>

class ChessCell;

class ChessField {
private:
    ChessCell *chessField[8][8];
public:
    ChessCell *getChessCell(std::pair<int, int> coordinates);

    void addChessCell(ChessCell *chessCell);

    ChessField *getCopy();
};


#endif //CHESSAPPLICATION_CHESSFIELD_H
