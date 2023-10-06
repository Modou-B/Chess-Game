//
// Created by Julian Sommer on 05.10.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECECREATOR_H
#define CHESSAPPLICATION_CHESSPIECECREATOR_H

class BaseChessPiece;
class ChessPieceStateTransfer;
class ChessPieceMovementMapper;
class KingPieceMovementChecker;

class ChessPieceCreator {
private:
    ChessPieceMovementMapper *chessPieceMovementMapper;
    KingPieceMovementChecker *kingPieceMovementChecker;

public:
    ChessPieceCreator(
      ChessPieceMovementMapper *chessPieceMovementMapper,
      KingPieceMovementChecker *kingPieceMovementChecker
    );

    BaseChessPiece *createChessPiece(
      ChessPieceStateTransfer *chessPieceStateTransfer
    );
};

#endif // CHESSAPPLICATION_CHESSPIECECREATOR_H
