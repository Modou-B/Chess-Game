//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCELL_H
#define CHESSAPPLICATION_CHESSCELL_H

#include <QPushButton>
#include "../ChessPiece//BaseChessPiece.h"

class ChessCell: public QPushButton {
private:
    BaseChessPiece *chessPiece;

public:
    explicit ChessCell(BaseChessPiece* chessPiece);

    void handleButton();
};


#endif //CHESSAPPLICATION_CHESSCELL_H
