//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIRENDERER_H
#define CHESSAPPLICATION_CHESSGUIRENDERER_H

#include <string>

class QWidget;
class QGridLayout;
class ChessFacade;
class QIcon;

class ChessGuiRenderer {
private:
    ChessFacade *chessFacade;

protected:
    QGridLayout *createChessGridLayout(QWidget *mainWindow);

    void fillFieldWithEmptyCells(QGridLayout *layout);

    void addPawnsToCells(QGridLayout *layout);
    void addQueensToCells(QGridLayout *layout);
    void addKingsToCells(QGridLayout *layout);
    void addBishopsToCells(QGridLayout *layout);
    void addKnightsToCells(QGridLayout *layout);
    void addRooksToCells(QGridLayout *layout);
    void addChessPieceToCells(QGridLayout *layout, QIcon icon, int column, int row);

    QIcon createIconFromFile(std::string fileName);
public:
    explicit ChessGuiRenderer(ChessFacade *chessFacade);

    void createChessField(QWidget *mainWindow);
};


#endif //CHESSAPPLICATION_CHESSGUIRENDERER_H
