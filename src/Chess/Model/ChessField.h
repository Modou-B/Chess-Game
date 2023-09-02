//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSFIELD_H
#define CHESSAPPLICATION_CHESSFIELD_H

class ChessCell;

class ChessField {
private:
    ChessCell *chessField[8][8];

public:
    ChessCell *getChessCell(int xPosition, int yPosition);

    void addChessCell(ChessCell *chessCell);
};


#endif //CHESSAPPLICATION_CHESSFIELD_H
