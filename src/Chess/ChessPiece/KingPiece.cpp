//
// Created by Julian Sommer on 29.08.23.
//

#include "KingPiece.h"
#include "Generator/ChessPieceMovementGenerator.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "iostream"

KingPiece::KingPiece(int player, ChessPieceMovementGenerator *chessPieceMovementGenerator): BaseChessPiece("King", player, chessPieceMovementGenerator) {
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->checkForCastling(chessField, possibleMoves, xCoordinate, yCoordinate);

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::checkHorizontalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer *> KingPiece::checkForCastling(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer *> possibleMoves, int xCoordinate, int yCoordinate) {

    if (this->moveCounter > 0) {
        return possibleMoves;
    }

    // Check right side from the king
    bool isRightSidePossibleForCastling = false;
    if (this->isRookEligibleForCastling(chessField, 7, yCoordinate)) {
        for (int i = 1; i <= 2; i++) {
            auto *potentialChessPieceOnCell = this->getChessPiece(chessField, (xCoordinate+i), yCoordinate);

            if (potentialChessPieceOnCell) {
                break;
            }
        }

        isRightSidePossibleForCastling = true;
    }

    if (isRightSidePossibleForCastling) {
        possibleMoves.push_back(
                this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_CASTLING, (xCoordinate+2), yCoordinate));
    }

    bool isLeftSidePossibleForCastling = false;
    if (this->isRookEligibleForCastling(chessField, 0, yCoordinate)) {
        for (int i = 1; i <= 3; i++) {
            auto *potentialChessPieceOnCell = this->getChessPiece(chessField, (xCoordinate-i), yCoordinate);

            if (potentialChessPieceOnCell) {
                break;
            }
        }

        isLeftSidePossibleForCastling = true;
    }

    if (isLeftSidePossibleForCastling) {
        possibleMoves.push_back(
                this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                        ChessMovementConstants::MOVE_TYPE_CASTLING, (xCoordinate-2), yCoordinate));
    }

    return possibleMoves;
}

bool KingPiece::isRookEligibleForCastling(ChessField *chessField, int xCoordinate, int yCoordinate) {
    auto *possibleChessPieceOnCell = this->getChessPiece(chessField, xCoordinate, yCoordinate);

    if (!possibleChessPieceOnCell || possibleChessPieceOnCell->getType() != ChessConstants::ROOK_PIECE_TYPE) {
        return false;
    }

    if (possibleChessPieceOnCell->getMoveCounter() > 0) {
        return false;
    }

    return true;
}
