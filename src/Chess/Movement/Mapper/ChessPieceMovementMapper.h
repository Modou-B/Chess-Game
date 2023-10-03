//
// Created by Julian Sommer on 17.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTMAPPER_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTMAPPER_H

#include <string>
#include <utility>

using namespace std;

class ChessPiecePossibleMoveTransfer;
class ChessPieceMovementTransfer;
class ChessPieceStateTransfer;

class ChessPieceMovementMapper {
public:
    ChessPiecePossibleMoveTransfer *generateChessPiecePossibleMoveTransfer(
            string moveType, int xCoordinate, int yCoordinate);

    ChessPieceMovementTransfer *generateChessPieceMovementTransfer(
            string action, pair<int, int> oldCoordinates, pair<int, int> newCoordinates);

    ChessPieceMovementTransfer *generateChessPieceMovementTransfer(
            string action, pair<int, int> oldCoordinates);

    ChessPieceStateTransfer *mapDataToChessPieceStateTransfer(
        int player,
        string pieceType,
        string state,
        pair<int, int> startCoordinates,
        pair<int, int> endCoordinates
    );

    ChessPieceStateTransfer *mapDataToChessPieceStateTransfer(
        int player,
        string pieceType,
        string state,
        pair<int, int> startCoordinates
    );
};


#endif // CHESSAPPLICATION_CHESSPIECEMOVEMENTMAPPER_H
