//
// Created by Julian Sommer on 29.08.23.
//

#include "KingPiece.h"
#include "Generator/ChessPieceMovementGenerator.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../../Shared/Chess/Transfer/Checkmate/InCheckResponseTransfer.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "Movement/KingPiece/KingPieceMovementChecker.h"

KingPiece::KingPiece(
    int player,
    ChessPieceMovementGenerator *chessPieceMovementGenerator,
    KingPieceMovementChecker *kingPieceMovementChecker
    ): BaseChessPiece(ChessConstants::KING_PIECE_TYPE, player, chessPieceMovementGenerator, kingPieceMovementChecker) {
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    possibleMoves = this->checkForCastling(chessField, possibleMoves, xCoordinate, yCoordinate);

    possibleMoves = this->tryToAddPossibleKingCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->tryToAddPossibleKingCoordinates(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate + 1));
    possibleMoves = this->checkHorizontalMovement(chessField, possibleMoves, xCoordinate, (yCoordinate - 1));

    possibleMoves = this->tryToAddPossibleKingCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddPossibleKingCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::checkHorizontalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    possibleMoves = this->tryToAddPossibleKingCoordinates(chessField, possibleMoves, (xCoordinate + 1), yCoordinate);
    possibleMoves = this->tryToAddPossibleKingCoordinates(chessField, possibleMoves, (xCoordinate - 1), yCoordinate);

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
        isRightSidePossibleForCastling = true;

        for (int i = 1; i <= 2; i++) {
            auto *potentialChessPieceOnCell = this->getChessPiece(chessField, (xCoordinate+i), yCoordinate);

            if (potentialChessPieceOnCell) {
                isRightSidePossibleForCastling = false;

                break;
            }
        }

    }

    if (isRightSidePossibleForCastling) {
        if (!this->doesOpponentChessPieceBlockCoordinates(chessField, (xCoordinate+1), yCoordinate)
            && !this->doesOpponentChessPieceBlockCoordinates(chessField, (xCoordinate+2), yCoordinate)
          ) {
            possibleMoves.push_back(
                  this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                          ChessMovementConstants::MOVE_TYPE_CASTLING, (xCoordinate+2), yCoordinate));
        }
    }

    bool isLeftSidePossibleForCastling = false;
    if (this->isRookEligibleForCastling(chessField, 0, yCoordinate)) {
        isLeftSidePossibleForCastling = true;

        for (int i = 1; i <= 3; i++) {
            auto *potentialChessPieceOnCell = this->getChessPiece(chessField, (xCoordinate-i), yCoordinate);

            if (potentialChessPieceOnCell) {
                isLeftSidePossibleForCastling = false;
                break;
            }
        }
    }

    if (isLeftSidePossibleForCastling) {
      if (!this->doesOpponentChessPieceBlockCoordinates(chessField, (xCoordinate-1), yCoordinate)
            && !this->doesOpponentChessPieceBlockCoordinates(chessField, (xCoordinate-2), yCoordinate)
          ) {
            possibleMoves.push_back(
                  this->chessPieceMovementGenerator->generateChessPiecePossibleMoveTransfer(
                          ChessMovementConstants::MOVE_TYPE_CASTLING, (xCoordinate-2), yCoordinate));
        }

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

bool KingPiece::doesOpponentChessPieceBlockCoordinates(
    ChessField *chessField, int xCoordinate, int yCoordinate) {
    if (this->kingPieceMovementChecker->getVerticalCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, this->getPlayer()).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getHorizontalCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, this->getPlayer()).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getDiagonalCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, this->getPlayer()).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getKnightCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, this->getPlayer()).getAmountOfPiecesThatCheckCell() > 0) {

        return true;
    }

    return false;
}

std::vector<ChessPiecePossibleMoveTransfer*> KingPiece::tryToAddPossibleKingCoordinates(
    ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    if (this->doesOpponentChessPieceBlockCoordinates(chessField, xCoordinate, yCoordinate)) {
        return possibleMoves;
    }

    possibleMoves = this->tryToAddCoordinates(chessField, possibleMoves, xCoordinate, yCoordinate);

    return possibleMoves;
}
