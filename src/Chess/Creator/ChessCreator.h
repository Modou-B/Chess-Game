//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_CHESSCREATOR_H
#define CHESSAPPLICATION_CHESSCREATOR_H

class ChessField;
class ChessCell;
class BaseChessPiece;
class ChessCellTransfer;
class ChessPieceTransfer;

class ChessCreator {
public:
    BaseChessPiece *createChessPiece(ChessPieceTransfer *chessPieceTransfer);

    ChessCell *createChessCell(ChessCellTransfer *chessCellTransfer);

    ChessField *createChessField();
};


#endif //CHESSAPPLICATION_CHESSCREATOR_H
