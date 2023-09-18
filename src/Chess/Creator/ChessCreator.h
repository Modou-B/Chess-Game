//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCREATOR_H
#define CHESSAPPLICATION_CHESSCREATOR_H

#include <string>

class ChessField;
class ChessCell;
class BaseChessPiece;
class ChessPieceMovementGenerator;

class ChessCreator {
protected:
    ChessPieceMovementGenerator *createChessPieceMovementGenerator();

public:
    BaseChessPiece *createChessPiece(std::string type, int player);

    ChessCell *createChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates);

    ChessField *createChessField();

    ChessField *initiateChessField();

    void fillFieldWithEmptyCells(ChessField *chessField);
    void addChessPiecesToFieldCells(ChessField *chessField);

    void fillFieldWithPawns(ChessField *chessField);
    void fillFieldWithQueens(ChessField *chessField);
    void fillFieldWithKings(ChessField *chessField);
    void fillFieldWithBishops(ChessField *chessField);
    void fillFieldWithKnights(ChessField *chessField);
    void fillFieldWithRooks(ChessField *chessField);
    void fillFieldWithPieces(ChessField *chessField, std::string pieceType, int player, int column, int row);

};

#endif //CHESSAPPLICATION_CHESSCREATOR_H
