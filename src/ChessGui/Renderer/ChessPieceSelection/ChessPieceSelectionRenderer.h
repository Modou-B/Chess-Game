//
// Created by Julian Sommer on 03.10.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECESELECTIONRENDERER_H
#define CHESSAPPLICATION_CHESSPIECESELECTIONRENDERER_H

#include <string>

using namespace std;

class QHBoxLayout;
class ChessGuiPieceIconGenerator;
class ChessSelectionPiece;
class ChessFacade;

class ChessPieceSelectionRenderer {
private:
    static QHBoxLayout *hBoxChessPieceSelectionTop;
    static QHBoxLayout *hBoxChessPieceSelectionBottom;

    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;

protected:
    ChessSelectionPiece *createChessSelectionPiece(
        ChessFacade *chessFacade,
        string type,
        string iconColor
    );

public:
    ChessPieceSelectionRenderer(ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator);

    void createChessPieceSelectionHBoxes(ChessFacade *chessFacade, string chessPieceTypes[4]);

    void renderChessPieceSelectionHBoxForPlayer(int player);
    void hideChessPieceSelectionHBoxForPlayer(int player);

    QHBoxLayout *getChessPieceSelectionHBoxForPlayer(int player);
};

#endif // CHESSAPPLICATION_CHESSPIECESELECTIONRENDERER_H
