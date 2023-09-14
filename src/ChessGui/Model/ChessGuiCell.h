//
// Created by Julian Sommer on 06.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUICELL_H
#define CHESSAPPLICATION_CHESSGUICELL_H

#include <QPushButton>
#include <utility>
#include <string>

class ChessFacade;
class QGridLayout;
class ChessMovementResponseTransfer;

class ChessGuiCell: public QPushButton {
private:
    QGridLayout *gridLayout;
    ChessFacade *chessFacade;

    std::pair<int, int> coordinates;

    Qt::GlobalColor currentColor;

public:
    ChessGuiCell(QGridLayout *gridLayout, ChessFacade *chessFacade, std::pair<int, int> coordinates);

    void handleCellClick();
    void handleChessPieceMovement(ChessMovementResponseTransfer chessMovementResponseTransfer);

    Qt::GlobalColor getCellColor();
    QGridLayout *getGridLayout();

    void setBaseCellSize();
    void setCellColor(QColor color);
    void setChessPiece(std::string pieceType);
};


#endif //CHESSAPPLICATION_CHESSGUICELL_H
