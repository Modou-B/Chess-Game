//
// Created by Julian Sommer on 06.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUICELL_H
#define CHESSAPPLICATION_CHESSGUICELL_H

#include <QPushButton>
#include <utility>
#include <string>

class ChessFacade;
class ChessMovementResponseTransfer;
class ChessGuiPieceIconGenerator;
class QIcon;
class QHBoxLayout;
class ChessGridLayout;

class ChessGuiCell: public QPushButton {
private:
    ChessGridLayout *gridLayout;
    ChessFacade *chessFacade;
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;
    QHBoxLayout *hBoxChessPieceSelectionTop;
    QHBoxLayout *hBoxChessPieceSelectionBottom;

    std::pair<int, int> coordinates;

    Qt::GlobalColor currentColor;

    std::string chessPieceType;
    std::string chessPieceIconState;

protected:
    void renderPieceSwitchLayout();
    void handlePawnPieceSwitch(ChessMovementResponseTransfer chessMovementResponseTransfer);

public:
    ChessGuiCell(
            ChessGridLayout *gridLayout,
            ChessFacade *chessFacade,
            std::pair<int, int> coordinates,
            ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator,
            QHBoxLayout *hBoxChessPieceSelectionTop,
            QHBoxLayout *hBoxChessPieceSelectionBottom
    );

    void handleCellClick();
    void handleChessPieceMovement(ChessMovementResponseTransfer chessMovementResponseTransfer);

    Qt::GlobalColor getCellColor();
    std::string getChessPieceIconState();
    std::string getChessPieceType();

    void setBaseCellSize();
    void setCellColor(QColor color);
    void setChessPieceType(std::string pieceType);

    void renderPossibleMovesForPiece(ChessMovementResponseTransfer chessMovementResponseTransfer);
    void clearPossibleMovesForPreviousPieceClick(ChessMovementResponseTransfer chessMovementResponseTransfer);

    void setChessPieceIcon(std::string iconState, QIcon chessPieceIcon);
    void addListWidgetItem(std::pair<int, int> currentCellCoordinates);
};


#endif //CHESSAPPLICATION_CHESSGUICELL_H
