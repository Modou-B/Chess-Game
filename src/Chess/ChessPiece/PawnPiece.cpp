//
// Created by Julian Sommer on 29.08.23.
//

#include "PawnPiece.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../Model/ChessField.h"
#include "../Movement/Mapper/ChessPieceMovementMapper.h"
#include "iostream"

PawnPiece::PawnPiece(
    int player,
    ChessPieceMovementMapper *chessPieceMovementMapper,
    KingPieceMovementChecker *kingPieceMovementChecker
    ): BaseChessPiece(ChessConstants::PAWN_PIECE_TYPE, player, chessPieceMovementMapper, kingPieceMovementChecker) {

    this->usedDoubleMove = false;
}

std::vector<ChessPiecePossibleMoveTransfer*> PawnPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    if (this->getPlayer() == 1) {
        return this->determinePossibleMovesForPlayer1(chessField, possibleMoves, xCoordinate, yCoordinate);
    }

    return this->determinePossibleMovesForPlayer2(chessField, possibleMoves, xCoordinate, yCoordinate);
}

std::vector<ChessPiecePossibleMoveTransfer*> PawnPiece::determinePossibleMovesForPlayer1(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    bool isDoubleMovePossible = false;

    possibleMoves = this->checkForEnPassant(chessField, possibleMoves, xCoordinate, yCoordinate, -1);

    yCoordinate--;

    if (!this->hasCellChessPiece(chessField, this->generateCoordinates(yCoordinate, xCoordinate))) {
          possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);
          isDoubleMovePossible = true;
    }

    possibleMoves = this->checkForDiagonalPieces(chessField, possibleMoves, xCoordinate, yCoordinate);

    yCoordinate--;
    possibleMoves = this->checkForDoubleMove(chessField, possibleMoves, xCoordinate, yCoordinate, isDoubleMovePossible);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> PawnPiece::determinePossibleMovesForPlayer2(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    bool isDoubleMovePossible = false;

    possibleMoves = this->checkForEnPassant(chessField, possibleMoves, xCoordinate, yCoordinate, 1);

    yCoordinate++;

    if (!this->hasCellChessPiece(chessField, this->generateCoordinates(yCoordinate, xCoordinate))) {
          possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);
          isDoubleMovePossible = true;
    }

    possibleMoves = this->checkForDiagonalPieces(chessField, possibleMoves, xCoordinate, yCoordinate);

    yCoordinate++;
    possibleMoves = this->checkForDoubleMove(chessField, possibleMoves, xCoordinate, yCoordinate, isDoubleMovePossible);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer *> PawnPiece::checkForDoubleMove(
    ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer *> possibleMoves, int xCoordinate, int yCoordinate, bool isDoubleMovePossible) {

    if (!isDoubleMovePossible) {
        return possibleMoves;
    }

    if (this->moveCounter == 0) {
        std::pair<int, int> coordinates = this->generateCoordinates(yCoordinate, xCoordinate);

        if (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate) && !this->hasCellOpponentChessPiece(chessField, coordinates)) {
            possibleMoves.push_back(
                    this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(
                            ChessMovementConstants::MOVE_TYPE_PAWN_DOUBLE_MOVE, xCoordinate, yCoordinate));
        }
    }

    return possibleMoves;
}


std::vector<ChessPiecePossibleMoveTransfer*> PawnPiece::checkForDiagonalPieces(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    std::pair<int, int> leftCoordinates = this->generateCoordinates(yCoordinate, (xCoordinate-1));

    cout << "checkForDiagonalPieces: "<< xCoordinate << " " << yCoordinate <<endl;

    if (!this->areCoordinatesOutOfBounds((xCoordinate-1), yCoordinate) && this->hasCellOpponentChessPiece(chessField, leftCoordinates)) {
        possibleMoves.push_back(
                this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_NORMAL, (xCoordinate-1), yCoordinate));
    }

    std::pair<int, int> rightCoordinates = this->generateCoordinates(yCoordinate, (xCoordinate+1));
    if (!this->areCoordinatesOutOfBounds((xCoordinate+1), yCoordinate) && this->hasCellOpponentChessPiece(chessField, rightCoordinates)) {
        possibleMoves.push_back(
                this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_NORMAL, (xCoordinate+1), yCoordinate));
    }

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer *> PawnPiece::checkForEnPassant(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer *> possibleMoves, int xCoordinate, int yCoordinate, int yValueToAdd) {

    if (this->moveCounter == 0) {
        return possibleMoves;
    }

    if (this->isEnPassantPossible(chessField, (xCoordinate-1), yCoordinate)) {
        possibleMoves.push_back(
                this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_EN_PASSANT, (xCoordinate-1), (yCoordinate+yValueToAdd)));
    }

    if (this->isEnPassantPossible(chessField, (xCoordinate+1), yCoordinate)) {
        possibleMoves.push_back(
                this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_EN_PASSANT, (xCoordinate+1), (yCoordinate+yValueToAdd)));
    }

    return possibleMoves;
}

bool PawnPiece::isEnPassantPossible(ChessField *chessField, int xCoordinate, int yCoordinate) {
    if (this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        return false;
    }

    auto *chessPiece = this->getChessPiece(chessField, xCoordinate, yCoordinate);
    if (!this->isOpponentChessPiece(chessPiece)) {
        return false;
    }

    if (chessPiece->getType() != this->getType()) {
        return false;
    }

    auto *pawnPiece = static_cast<PawnPiece*>(chessPiece);
    if (pawnPiece->getMoveCounter() == 1 && pawnPiece->wasDoubleMoveUsed() && pawnPiece->wasChessPieceMovedLastTurn()) {
        return true;
    }

    return false;
}

void PawnPiece::handleMovement(ChessPiecePossibleMoveTransfer *usedMove) {
    BaseChessPiece::handleMovement(usedMove);

    if (usedMove->getMoveType() == ChessMovementConstants::MOVE_TYPE_PAWN_DOUBLE_MOVE) {
        this->usedDoubleMove = true;
    }
}

void PawnPiece::setUsedDoubleMove(bool usedDoubleMove) {
    this->usedDoubleMove = usedDoubleMove;
}

bool PawnPiece::getUsedDoubleMove() {
  return this-usedDoubleMove;
}

bool PawnPiece::wasDoubleMoveUsed() {
    return this->usedDoubleMove;
}
