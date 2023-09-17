//
// Created by Julian Sommer on 29.08.23.
//

#include "PawnPiece.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "Generator/ChessPieceMovementGenerator.h"
#include "../Model/ChessField.h"

PawnPiece::PawnPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator): BaseChessPiece("Pawn", player, chessPieceMovementGenerator) {
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

    possibleMoves = this->checkForEnPassant(chessField, possibleMoves, xCoordinate, yCoordinate, -1);

    yCoordinate--;
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->checkForDiagonalPieces(chessField, possibleMoves, xCoordinate, yCoordinate);

    yCoordinate--;
    possibleMoves = this->checkForDoubleMove(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> PawnPiece::determinePossibleMovesForPlayer2(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->checkForEnPassant(chessField, possibleMoves, xCoordinate, yCoordinate, 1);

    yCoordinate++;
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);
    possibleMoves = this->checkForDiagonalPieces(chessField, possibleMoves, xCoordinate, yCoordinate);

    yCoordinate++;
    possibleMoves = this->checkForDoubleMove(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer *> PawnPiece::checkForDoubleMove(
    ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer *> possibleMoves, int xCoordinate, int yCoordinate) {

    if (!this->usedDoubleMove) {
        std::pair<int, int> coordinates = this->generateCoordinates(yCoordinate, xCoordinate);

        if (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate) && !this->hasCellOpponentChessPiece(chessField, coordinates)) {
            possibleMoves.push_back(
                    this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                            ChessMovementConstants::MOVE_TYPE_PAWN_DOUBLE_MOVE, xCoordinate, yCoordinate));
        }
    }

    return possibleMoves;
}


std::vector<ChessPiecePossibleMoveTransfer*> PawnPiece::checkForDiagonalPieces(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    std::pair<int, int> leftCoordinates = this->generateCoordinates(yCoordinate, (xCoordinate-1));
    if (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate) && this->hasCellOpponentChessPiece(chessField, leftCoordinates)) {
        possibleMoves.push_back(
                this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_NORMAL, (xCoordinate-1), yCoordinate));
    }

    std::pair<int, int> rightCoordinates = this->generateCoordinates(yCoordinate, (xCoordinate+1));
    if (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate) && this->hasCellOpponentChessPiece(chessField, rightCoordinates)) {
        possibleMoves.push_back(
                this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
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
                this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_EN_PASSANT, (xCoordinate-1), (yCoordinate+yValueToAdd)));
    }

    if (this->isEnPassantPossible(chessField, (xCoordinate+1), yCoordinate)) {
        possibleMoves.push_back(
                this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
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

bool PawnPiece::wasDoubleMoveUsed() {
    return this->usedDoubleMove;
}
