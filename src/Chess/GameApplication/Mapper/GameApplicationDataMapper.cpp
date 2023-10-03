//
// Created by Julian Sommer on 01.10.23.
//

#include "GameApplicationDataMapper.h"
#include "../../ChessPiece/BaseChessPiece.h"
#include "../../../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"

ChessPiecePositionTransfer GameApplicationDataMapper::mapChessPieceToChessPiecePositionTransfer(BaseChessPiece *chessPiece) {
    ChessPiecePositionTransfer chessPiecePositionTransfer = {};

    chessPiecePositionTransfer.setCurrentChessPieceCoordinates(chessPiece->getCurrentCoordinates());

    return chessPiecePositionTransfer;
}