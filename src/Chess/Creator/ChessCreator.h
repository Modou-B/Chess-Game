//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCREATOR_H
#define CHESSAPPLICATION_CHESSCREATOR_H

#include <string>

class ChessField;
class ChessPlayerData;
class ChessCell;
class BaseChessPiece;
class ChessPieceMovementGenerator;
class KingPieceMovementChecker;

class ChessCreator {
protected:
    ChessPieceMovementGenerator *createChessPieceMovementGenerator();
    KingPieceMovementChecker *createKingPieceMovementChecker();

public:
    BaseChessPiece *createChessPiece(std::string type, int player);

    ChessCell *createChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates);

    void initiateChessData(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);

    void fillFieldWithEmptyCells(ChessField *chessField);
    void addChessPiecesToFieldCellsAndPlayerData(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);

    void fillFieldAndPlayerDataWithPawns(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);
    void fillFieldAndPlayerDataWithQueens(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);
    void fillFieldAndPlayerDataWithKings(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);
    void fillFieldAndPlayerDataWithBishops(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);
    void fillFieldAndPlayerDataWithKnights(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);
    void fillFieldAndPlayerDataWithRooks(ChessField *chessField, ChessPlayerData *chessPlayerData1, ChessPlayerData *chessPlayerData2);
    BaseChessPiece *addPieceToField(ChessField *chessField, std::string pieceType, int player, int column, int row);

};

#endif //CHESSAPPLICATION_CHESSCREATOR_H
