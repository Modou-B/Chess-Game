//
// Created by Julian Sommer on 06.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUICELL_H
#define CHESSAPPLICATION_CHESSGUICELL_H

#include <QPushButton>
#include <utility>
#include <string>

using namespace std;

class ChessFacade;
class ChessMovementResponseTransfer;
class ChessPiecePositionTransfer;
class ChessGuiPieceIconGenerator;
class ChessPieceSelectionRenderer;
class ChessTimelineRenderer;
class QIcon;
class QHBoxLayout;
class QGridLayout;

class ChessGuiCell: public QPushButton {
private:
    QGridLayout *gridLayout;
    ChessFacade *chessFacade;
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer;
    ChessTimelineRenderer *chessTimelineRenderer;

    pair<int, int> coordinates;

    Qt::GlobalColor currentColor;

    string chessPieceType;
    string chessPieceIconState;

protected:
    ChessPiecePositionTransfer createCurrentChessPiecePositionTransfer();

public:
    ChessGuiCell(
            QGridLayout *gridLayout,
            ChessFacade *chessFacade,
            ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
            ChessTimelineRenderer *chessTimelineRenderer,
            pair<int, int> coordinates,
            ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator
    );

    void handleCellClick();
    void handleChessPieceMovement(ChessMovementResponseTransfer chessMovementResponseTransfer);
    void handlePawnPieceSwitch(string pieceType);

    Qt::GlobalColor getCellColor();
    string getChessPieceIconState();
    string getChessPieceType();

    void setBaseCellSize();
    void setCellColor(QColor color);
    void setChessPieceType(string pieceType);

    void renderPossibleMovesForPiece(ChessMovementResponseTransfer chessMovementResponseTransfer);
    void clearPossibleMovesForPreviousPieceClick(ChessMovementResponseTransfer chessMovementResponseTransfer);

    void setChessPieceIcon(string iconState, QIcon chessPieceIcon);
    void addListWidgetItem();

    void clearCurrentChessPiece();
    void addChessPiece(string pieceType, string color);
};


#endif //CHESSAPPLICATION_CHESSGUICELL_H
