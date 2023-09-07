//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSCELLTRANSFER_H
#define CHESSAPPLICATION_CHESSCELLTRANSFER_H

class BaseChessPiece;
class ChessField;

class ChessCellTransfer {
private:
    ChessField *chessField;
    BaseChessPiece *chessPiece;
    int xPosition;
    int yPosition;

public:
    ChessCellTransfer();

    ChessField *getChessField();

    BaseChessPiece *getChessPiece();

    int getXPosition();

    int getYPosition();

    ChessCellTransfer &setChessField(ChessField *chessField);

    ChessCellTransfer &setChessPiece(BaseChessPiece *chessPiece);

    ChessCellTransfer &setXPosition(int xPosition);

    ChessCellTransfer &setYPosition(int yPosition);
};


#endif //CHESSAPPLICATION_CHESSCELLTRANSFER_H
