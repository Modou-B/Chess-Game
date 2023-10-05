//
// Created by Julian Sommer on 17.09.23.
//

#include "ChessPieceMovementMapper.h"
#include "../../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPieceMovementTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPiece/ChessPieceStateTransfer.h"

ChessPiecePossibleMoveTransfer *ChessPieceMovementMapper::generateChessPiecePossibleMoveTransfer(
        string moveType, int xCoordinate, int yCoordinate) {

    auto chessPiecePossibleMoveTransfer = new ChessPiecePossibleMoveTransfer;
    chessPiecePossibleMoveTransfer->setMoveType(moveType).setXCoordinate(xCoordinate).setYCoordinate(yCoordinate);

    return chessPiecePossibleMoveTransfer;
}

ChessPieceMovementTransfer *ChessPieceMovementMapper::generateChessPieceMovementTransfer(
        string action, pair<int, int> oldCoordinates, pair<int, int> newCoordinates) {

    auto chessPieceMovementTransfer = new ChessPieceMovementTransfer;
    chessPieceMovementTransfer->setAction(action).setOldCoordinates(oldCoordinates).setNewCoordinates(newCoordinates);

    return chessPieceMovementTransfer;
}

ChessPieceMovementTransfer *ChessPieceMovementMapper::generateChessPieceMovementTransfer(
    string action, pair<int, int> oldCoordinates) {

    auto chessPieceMovementTransfer = new ChessPieceMovementTransfer;
    chessPieceMovementTransfer->setAction(action).setOldCoordinates(oldCoordinates);

    return chessPieceMovementTransfer;
}

ChessPieceStateTransfer *ChessPieceMovementMapper::mapDataToChessPieceStateTransfer(
    int player,
    string pieceType,
    string state,
    pair<int, int> startCoordinates,
    pair<int, int> endCoordinates
) {
    auto *chessPieceStateTransfer = this->mapDataToChessPieceStateTransfer(
      player,
      pieceType,
      state,
      startCoordinates
    )->setEndCoordinate(endCoordinates);

    return chessPieceStateTransfer;
}

ChessPieceStateTransfer *ChessPieceMovementMapper::mapDataToChessPieceStateTransfer(
    int player,
    string pieceType,
    string state,
    pair<int, int> startCoordinates
) {
    auto *chessPieceStateTransfer = new ChessPieceStateTransfer;

    chessPieceStateTransfer->setPlayerOfChessPiece(player)
        ->setChessPieceType(pieceType)
        ->setState(state)
        ->setStartCoordinate(startCoordinates);

    return chessPieceStateTransfer;
}
