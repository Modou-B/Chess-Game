//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCELL_H
#define CHESSAPPLICATION_CHESSCELL_H

#include <QPushButton>
#include <utility>

class ChessField;
class BaseChessPiece;

class ChessCell: public QPushButton {
private:
    BaseChessPiece *chessPiece;
    ChessField *chessFieldModel;
    std::pair<int, int> coordinates;

public:
    ChessCell(ChessField *chessFieldModel, BaseChessPiece* chessPiece, std::pair<int, int> coordinates);

    void handleButton();

    void setChessPiece(BaseChessPiece *baseChessPiece);

    std::pair<int, int> getCoordinates();
};


#endif //CHESSAPPLICATION_CHESSCELL_H
