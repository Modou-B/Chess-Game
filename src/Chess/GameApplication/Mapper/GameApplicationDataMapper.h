//
// Created by Julian Sommer on 01.10.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONDATAMAPPER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONDATAMAPPER_H

class BaseChessPiece;
class ChessPiecePositionTransfer;

class GameApplicationDataMapper {
public:
    ChessPiecePositionTransfer mapChessPieceToChessPiecePositionTransfer(BaseChessPiece *chessPiece);
};

#endif // CHESSAPPLICATION_GAMEAPPLICATIONDATAMAPPER_H
