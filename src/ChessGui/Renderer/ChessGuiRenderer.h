//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIRENDERER_H
#define CHESSAPPLICATION_CHESSGUIRENDERER_H


class QWidget;
class QGridLayout;
class ChessFacade;

class ChessGuiRenderer {
private:
    ChessFacade *chessFacade;

protected:
    QGridLayout *createChessGridLayout(QWidget *mainWindow);

    void fillFieldWithEmptyCells(QGridLayout *layout);

    void addPawnsToCells(QGridLayout *layout);

public:
    explicit ChessGuiRenderer(ChessFacade *chessFacade);

    void createChessField(QWidget *mainWindow);
};


#endif //CHESSAPPLICATION_CHESSGUIRENDERER_H
