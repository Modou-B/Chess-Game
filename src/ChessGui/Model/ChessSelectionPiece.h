//
// Created by Modou on 28.09.23.
//

#ifndef CHESSAPPLICATION_CHESSSELECTIONPIECE_H
#define CHESSAPPLICATION_CHESSSELECTIONPIECE_H


#include "QPushButton"
#include "string"

using namespace std;

class ChessGuiRenderer;
class QWidget;
class ChessFacade;

class ChessSelectionPiece: public QPushButton{
private:
    ChessFacade *chessFacade;
    string pieceType;

public:
    ChessSelectionPiece(ChessFacade *chessFacade, string pieceType);

    void setSelectionPiece();
};

#endif //CHESSAPPLICATION_CHESSSELECTIONPIECE_H
