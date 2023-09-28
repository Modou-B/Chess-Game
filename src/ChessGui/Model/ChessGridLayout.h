//
// Created by Modou on 28.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGRIDLAYOUT_H
#define CHESSAPPLICATION_CHESSGRIDLAYOUT_H

#include "QGridLayout"
#include "string"

class ChessGridLayout: public QGridLayout {
private:
    std::string switchPieceType;
    bool switchPiecePieceSetCondition;

public:
    ChessGridLayout();

    std::string getChessPieceSwitchType();
    bool isChessPieceSwitchTypeSet();

    void setChessPieceSwitchType(std::string pieceType);
    void setChessPieceTypeSetCondition(bool isSet);
};


#endif //CHESSAPPLICATION_CHESSGRIDLAYOUT_H
