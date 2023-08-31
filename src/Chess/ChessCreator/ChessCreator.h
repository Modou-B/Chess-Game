//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCREATOR_H
#define CHESSAPPLICATION_CHESSCREATOR_H

class QWidget;

class ChessCreator {
private:
    int chessField[8][8];

public:
    void createChessField(QWidget *mainWindow);
};


#endif //CHESSAPPLICATION_CHESSCREATOR_H
