//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCELL_H
#define CHESSAPPLICATION_CHESSCELL_H

#include <utility>

class BaseChessPiece;

class ChessCell {
private:
    BaseChessPiece *chessPiece;
    std::pair<int, int> coordinates;

public:
    ChessCell(BaseChessPiece* chessPiece, std::pair<int, int> coordinates);

    void handleCellClick();

    void setChessPiece(BaseChessPiece *baseChessPiece);

    std::pair<int, int> getCoordinates();

    BaseChessPiece *getChessPiece();
};


#endif //CHESSAPPLICATION_CHESSCELL_H
