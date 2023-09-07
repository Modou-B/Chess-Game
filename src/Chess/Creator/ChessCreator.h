//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCREATOR_H
#define CHESSAPPLICATION_CHESSCREATOR_H

#include <string>

class ChessField;
class ChessCell;
class BaseChessPiece;

class ChessCreator {
public:
    BaseChessPiece *createChessPiece(std::string type, int player);

    ChessCell *createChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates);

    ChessField *createChessField();

    ChessField *initiateChessField();

    void fillFieldWithEmptyCells(ChessField *chessField);
    void addChessPiecesToFieldCells(ChessField *chessField);

    void fillFieldWithPawns(ChessField *chessField);
    void fillFieldWithQueens(ChessField *chessField);
};

#endif //CHESSAPPLICATION_CHESSCREATOR_H
