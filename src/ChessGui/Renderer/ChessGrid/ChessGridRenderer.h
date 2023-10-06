//
// Created by Julian Sommer on 06.10.23.
//

#ifndef CHESSAPPLICATION_CHESSGRIDRENDERER_H
#define CHESSAPPLICATION_CHESSGRIDRENDERER_H

#include <string>
#include <utility>

using namespace std;

class QGridLayout;
class ChessFacade;
class ChessPieceSelectionRenderer;
class ChessTimelineRenderer;
class ChessGuiPieceIconGenerator;
class ChessSettingsDataHolder;

class ChessGridRenderer {
private:
    ChessFacade *chessFacade;
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer;
    ChessTimelineRenderer *chessTimelineRenderer;
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;
    ChessSettingsDataHolder *chessSettingsDataHolder;

    int minCellWidth;
    int minCellHeight;

protected:
    void fillFieldWithEmptyCells(QGridLayout *chessGridlayout);

    void addPawnsToCells(QGridLayout *chessGridlayout);
    void addQueensToCells(QGridLayout *chessGridlayout);
    void addKingsToCells(QGridLayout *chessGridlayout);
    void addBishopsToCells(QGridLayout *chessGridlayout);
    void addKnightsToCells(QGridLayout *chessGridlayout);
    void addRooksToCells(QGridLayout *chessGridlayout);
    void addChessPieceToCells(QGridLayout *chessGridlayout, string iconFileName, string pieceType, int column, int row);

public:
    ChessGridRenderer(
      ChessFacade *chessFacade,
      ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
      ChessTimelineRenderer *chessTimelineRenderer,
      ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator,
      ChessSettingsDataHolder *chessSettingsDataHolder
    );

    QGridLayout *createEmptyChessField();
    QGridLayout *createChessFieldWithPieces();

    void updateChessGridCellColor(QGridLayout *chessGridPreviewLayout);

    void setCellSize(int minWidth, int minHeight);
};

#endif // CHESSAPPLICATION_CHESSGRIDRENDERER_H
