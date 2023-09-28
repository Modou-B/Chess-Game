//
// Created by Modou on 28.09.23.
//

#ifndef CHESSAPPLICATION_CHESSSELECTIONPIECE_H
#define CHESSAPPLICATION_CHESSSELECTIONPIECE_H



#include "QPushButton"
#include "string"

class ChessGuiRenderer;
class QWidget;
class ChessGridLayout;

class ChessSelectionPiece: public QPushButton{
private:
    ChessGridLayout *gridLayout;
    std::string pieceType;

public:
    ChessSelectionPiece(ChessGridLayout *gridLayout, std::string pieceType);

    void setSelectionPiece();
};

#endif //CHESSAPPLICATION_CHESSSELECTIONPIECE_H
