//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIRENDERER_H
#define CHESSAPPLICATION_CHESSGUIRENDERER_H

#include <string>

class QWidget;
class QGridLayout;
class ChessFacade;
class ChessGuiPieceIconGenerator;
class QIcon;

class ChessGuiRenderer {
private:
    ChessFacade *chessFacade;
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator;

protected:
    QGridLayout *createChessGridLayout(QWidget *mainWindow);

    void fillFieldWithEmptyCells(QGridLayout *layout);

    void addPawnsToCells(QGridLayout *layout);
    void addQueensToCells(QGridLayout *layout);
    void addKingsToCells(QGridLayout *layout);
    void addBishopsToCells(QGridLayout *layout);
    void addKnightsToCells(QGridLayout *layout);
    void addRooksToCells(QGridLayout *layout);
    void addChessPieceToCells(QGridLayout *layout, std::string iconFileName, std::string pieceType, int column, int row);

public:
    ChessGuiRenderer(ChessFacade *chessFacade, ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator);

    void createChessField(QWidget *mainWindow);
};


#endif //CHESSAPPLICATION_CHESSGUIRENDERER_H
