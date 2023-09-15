//
// Created by Julian Sommer on 14.09.23.
//

#ifndef CHESSAPPLICATION_CHESSGUIPIECEICONGENERATOR_H
#define CHESSAPPLICATION_CHESSGUIPIECEICONGENERATOR_H

#include <string>

class QIcon;

class ChessGuiPieceIconGenerator {
private:
    std::string getFullPathToFile(std::string fileName);

public:
    QIcon generateIconFromFile(std::string fileName);

    QIcon generateTransparentIconFromFile(std::string fileName);
};


#endif //CHESSAPPLICATION_CHESSGUIPIECEICONGENERATOR_H
