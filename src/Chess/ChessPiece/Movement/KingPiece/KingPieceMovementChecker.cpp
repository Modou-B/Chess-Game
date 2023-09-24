//
// Created by Julian Sommer on 21.09.23.
//

#include "KingPieceMovementChecker.h"
#include "../../../ChessPiece/Movement/ChessPieceMovementTrait.h"
#include "../../../Model/ChessField.h"
#include "../../../Model/ChessCell.h"
#include "../../../ChessPiece/BaseChessPiece.h"
#include "../../../../Shared/Chess/ChessConstants.h"
#include "../../../../Shared/Chess/CheckmateConstants.h"
#include "../../../../Shared/Chess/Transfer/Checkmate/InCheckBlockedCoordinatesTransfer.h"
#include "../../../../Shared/Chess/Transfer/Checkmate/InCheckVerifierTransfer.h"
#include "../../../../Shared/Chess/Transfer/Checkmate/InCheckResponseTransfer.h"

InCheckResponseTransfer KingPieceMovementChecker::getVerticalCheckAmountForGivenChessCell(
      ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer) {
    int baseYCoordinate = yCoordinate;
    int baseXCoordinate = xCoordinate;

    auto inCheckVerifierTransfer = this->createInCheckVerifierTransfer(xCoordinate, yCoordinate, currentPlayer, CheckmateConstants::IN_CHECK_TYPE_VERTICALLY);
    auto inCheckResponseTransfer = InCheckResponseTransfer();

    yCoordinate++;
    inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate);

    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        yCoordinate++;

        inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    this->resetVerifyData(&xCoordinate, &yCoordinate, &inCheckVerifierTransfer, baseXCoordinate, baseYCoordinate);

    yCoordinate--;
    inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        yCoordinate--;

        inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    return inCheckResponseTransfer;
}

InCheckResponseTransfer KingPieceMovementChecker::getHorizontalCheckAmountForGivenChessCell(
      ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer) {
    int baseYCoordinate = yCoordinate;
    int baseXCoordinate = xCoordinate;

    auto inCheckVerifierTransfer = this->createInCheckVerifierTransfer(xCoordinate, yCoordinate, currentPlayer, CheckmateConstants::IN_CHECK_TYPE_HORIZONTAL);
    auto inCheckResponseTransfer = InCheckResponseTransfer();

    xCoordinate++;
    inCheckVerifierTransfer.setXCoordinateToVerify(xCoordinate);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        xCoordinate++;

        inCheckVerifierTransfer.setXCoordinateToVerify(xCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    this->resetVerifyData(&xCoordinate, &yCoordinate, &inCheckVerifierTransfer, baseXCoordinate, baseYCoordinate);

    xCoordinate--;
    inCheckVerifierTransfer.setXCoordinateToVerify(xCoordinate);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        xCoordinate--;

        inCheckVerifierTransfer.setXCoordinateToVerify(xCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    return inCheckResponseTransfer;
}

InCheckResponseTransfer KingPieceMovementChecker::getDiagonalCheckAmountForGivenChessCell(
    ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer) {
    int baseYCoordinate = yCoordinate;
    int baseXCoordinate = xCoordinate;

    auto inCheckVerifierTransfer = this->createInCheckVerifierTransfer(xCoordinate, yCoordinate, currentPlayer, CheckmateConstants::IN_CHECK_TYPE_DIAGONALLY);
    auto inCheckResponseTransfer = InCheckResponseTransfer();

    yCoordinate--;
    xCoordinate++;
    inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate).setDiagonalCheckDirection(CheckmateConstants::DIAGONAL_DIRECTION_TOP_RIGHT);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        yCoordinate--;
        xCoordinate++;

        inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    this->resetVerifyData(&xCoordinate, &yCoordinate, &inCheckVerifierTransfer, baseXCoordinate, baseYCoordinate);

    yCoordinate--;
    xCoordinate--;
    inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate).setDiagonalCheckDirection(CheckmateConstants::DIAGONAL_DIRECTION_TOP_LEFT);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        yCoordinate--;
        xCoordinate--;

        inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    this->resetVerifyData(&xCoordinate, &yCoordinate, &inCheckVerifierTransfer, baseXCoordinate, baseYCoordinate);

    yCoordinate++;
    xCoordinate++;
    inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate).setDiagonalCheckDirection(CheckmateConstants::DIAGONAL_DIRECTION_BOTTOM_RIGHT);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        yCoordinate++;
        xCoordinate++;

        inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    this->resetVerifyData(&xCoordinate, &yCoordinate, &inCheckVerifierTransfer, baseXCoordinate, baseYCoordinate);

    yCoordinate++;
    xCoordinate--;
    inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate).setDiagonalCheckDirection(CheckmateConstants::DIAGONAL_DIRECTION_BOTTOM_LEFT);
    while (this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, &inCheckResponseTransfer)) {
        yCoordinate++;
        xCoordinate--;

        inCheckVerifierTransfer.setYCoordinateToVerify(yCoordinate).setXCoordinateToVerify(xCoordinate);
        inCheckVerifierTransfer.setMoveCounter(inCheckVerifierTransfer.getMoveCounter() + 1);
    }

    return inCheckResponseTransfer;
}

InCheckResponseTransfer KingPieceMovementChecker::getKnightCheckAmountForGivenChessCell(
    ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer) {
    auto inCheckResponseTransfer = InCheckResponseTransfer();

    this->checkForKnightsHorizontally(chessField, xCoordinate, (yCoordinate+1), currentPlayer, &inCheckResponseTransfer);
    this->checkForKnightsHorizontally(chessField, xCoordinate, (yCoordinate-1), currentPlayer, &inCheckResponseTransfer);

    this->checkForKnightsVertically(chessField, (xCoordinate+1), yCoordinate, currentPlayer, &inCheckResponseTransfer);
    this->checkForKnightsVertically(chessField, (xCoordinate-1), yCoordinate, currentPlayer, &inCheckResponseTransfer);

    return inCheckResponseTransfer;
}

void KingPieceMovementChecker::checkForKnightsHorizontally(
    ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer, InCheckResponseTransfer *inCheckResponseTransfer) {

    auto inCheckVerifierTransfer = this->createInCheckVerifierTransfer((xCoordinate+2), yCoordinate, currentPlayer, CheckmateConstants::IN_CHECK_TYPE_KNIGHT);
    this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, inCheckResponseTransfer);

    inCheckVerifierTransfer = this->createInCheckVerifierTransfer((xCoordinate-2), yCoordinate, currentPlayer, CheckmateConstants::IN_CHECK_TYPE_KNIGHT);
    this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, inCheckResponseTransfer);
}

void KingPieceMovementChecker::checkForKnightsVertically(
    ChessField *chessField, int xCoordinate, int yCoordinate, int currentPlayer, InCheckResponseTransfer *inCheckResponseTransfer) {

    auto inCheckVerifierTransfer = this->createInCheckVerifierTransfer(xCoordinate, (yCoordinate+2), currentPlayer, CheckmateConstants::IN_CHECK_TYPE_KNIGHT);
    this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, inCheckResponseTransfer);

    inCheckVerifierTransfer = this->createInCheckVerifierTransfer(xCoordinate, (yCoordinate-2), currentPlayer, CheckmateConstants::IN_CHECK_TYPE_KNIGHT);
    this->continueToVerifyCoordinates(chessField, &inCheckVerifierTransfer, inCheckResponseTransfer);
}

bool KingPieceMovementChecker::continueToVerifyCoordinates(
    ChessField *chessField, InCheckVerifierTransfer *inCheckVerifierTransfer, InCheckResponseTransfer *inCheckResponseTransfer) {
    int xCoordinate = inCheckVerifierTransfer->getXCoordinateToVerify();
    int yCoordinate = inCheckVerifierTransfer->getYCoordinateToVerify();

    if (ChessPieceMovementTrait::areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        return false;
    }

    inCheckVerifierTransfer->addLastInCheckBlockedCoordinatesTransfer(this->createInCheckBlockedCoordinatesTransfer(xCoordinate, yCoordinate));

    auto *potentialChessPieceOnCell = chessField->getChessCell(ChessPieceMovementTrait::generateYXCoordinates(xCoordinate, yCoordinate))->getChessPiece();
    if (!potentialChessPieceOnCell) {
        return true;
    }

    if (potentialChessPieceOnCell->getPlayer() == inCheckVerifierTransfer->getCurrentPlayer()) {
        return false;
    }

    std::string pieceTypeToCheck = inCheckVerifierTransfer->getPieceTypeToCheck();
    if (pieceTypeToCheck == CheckmateConstants::IN_CHECK_TYPE_HORIZONTAL
        || pieceTypeToCheck == CheckmateConstants::IN_CHECK_TYPE_VERTICALLY) {

        if (potentialChessPieceOnCell->getType() == ChessConstants::QUEEN_PIECE_TYPE
            || potentialChessPieceOnCell->getType() == ChessConstants::ROOK_PIECE_TYPE) {
            this->mapToInCheckResponseTransfer(
              potentialChessPieceOnCell->getType(),
              inCheckVerifierTransfer->getLastInCheckBlockedCoordinatesTransfer(),
              inCheckResponseTransfer
            );

            return false;
        }

        if (potentialChessPieceOnCell->getMoveCounter() == 1
            && potentialChessPieceOnCell->getType() == ChessConstants::KING_PIECE_TYPE) {

            return false;
        }

        return false;
    }

    if (pieceTypeToCheck == CheckmateConstants::IN_CHECK_TYPE_KNIGHT) {
        if (potentialChessPieceOnCell->getType() == ChessConstants::KNIGHT_PIECE_TYPE) {
            this->mapToInCheckResponseTransfer(
              potentialChessPieceOnCell->getType(),
              inCheckVerifierTransfer->getLastInCheckBlockedCoordinatesTransfer(),
              inCheckResponseTransfer
            );


            return false;
        }

        return false;
    }

    if (pieceTypeToCheck == CheckmateConstants::IN_CHECK_TYPE_DIAGONALLY) {
        if (potentialChessPieceOnCell->getType() == ChessConstants::QUEEN_PIECE_TYPE
            || potentialChessPieceOnCell->getType() == ChessConstants::BISHOP_PIECE_TYPE) {
            this->mapToInCheckResponseTransfer(
              potentialChessPieceOnCell->getType(),
              inCheckVerifierTransfer->getLastInCheckBlockedCoordinatesTransfer(),
              inCheckResponseTransfer
            );

            return false;
        }

        if (inCheckVerifierTransfer->getMoveCounter() == 1) {
            if (potentialChessPieceOnCell->getType() == ChessConstants::KING_PIECE_TYPE) {
                this->mapToInCheckResponseTransfer(
          potentialChessPieceOnCell->getType(),
          inCheckVerifierTransfer->getLastInCheckBlockedCoordinatesTransfer(),
                    inCheckResponseTransfer
              );

                return false;
            }

            if (potentialChessPieceOnCell->getType() == ChessConstants::PAWN_PIECE_TYPE
                && this->isPawnViable(inCheckVerifierTransfer->getDiagonalCheckDirectionFromCell(), potentialChessPieceOnCell->getPlayer())
            ) {
                this->mapToInCheckResponseTransfer(
          potentialChessPieceOnCell->getType(),
          inCheckVerifierTransfer->getLastInCheckBlockedCoordinatesTransfer(),
                    inCheckResponseTransfer
                );

                return false;
            }
        }
    }

    return false;
}

InCheckVerifierTransfer KingPieceMovementChecker::createInCheckVerifierTransfer(
    int xCoordinate, int yCoordinate, int currentPlayer, std::string pieceTypeToCheck) {

    auto inCheckVerifierTransfer = InCheckVerifierTransfer();

    inCheckVerifierTransfer.setXCoordinateToVerify(xCoordinate)
        .setYCoordinateToVerify(yCoordinate)
        .setCurrentPlayer(currentPlayer)
        .setPieceTypeToCheck(pieceTypeToCheck)
        .setMoveCounter(1);

    return inCheckVerifierTransfer;
}

InCheckBlockedCoordinatesTransfer *KingPieceMovementChecker::createInCheckBlockedCoordinatesTransfer(int xCoordinate, int yCoordinate) {
    auto *inCheckBlockedCoordinatesTransfer = new InCheckBlockedCoordinatesTransfer;

    auto coordinates = ChessPieceMovementTrait::generateYXCoordinates(xCoordinate, yCoordinate);
    inCheckBlockedCoordinatesTransfer->setBlockedCoordinateFromCellToOpponentPiece(coordinates)
        .setIsRealTransfer(true)
        .setHasCoordinateOpponentPiece(false);

    return inCheckBlockedCoordinatesTransfer;
}

void KingPieceMovementChecker::resetVerifyData(
    int *xCoordinateToReset, int *yCoordinateToReset, InCheckVerifierTransfer *inCheckVerifierTransfer, int xValue, int yValue) {

    (*xCoordinateToReset) = xValue;
    (*yCoordinateToReset) = yValue;

    inCheckVerifierTransfer->setYCoordinateToVerify(yValue).setXCoordinateToVerify(xValue);
    inCheckVerifierTransfer->setMoveCounter(1);
    inCheckVerifierTransfer->clearLastCheckedCoordinates();
}

void KingPieceMovementChecker::mapToInCheckResponseTransfer(
    std::string pieceType, std::vector<InCheckBlockedCoordinatesTransfer*> checkedCoordinates, InCheckResponseTransfer *inCheckResponseTransfer) {
    checkedCoordinates.back()->setHasCoordinateOpponentPiece(true);

    inCheckResponseTransfer->setLatestCoordinatesFromCellToOpponentPiece(checkedCoordinates);
    inCheckResponseTransfer->setLatestPieceTypeThatCheckKing(pieceType);
    inCheckResponseTransfer->setAmountOfPiecesThatCheckCell(inCheckResponseTransfer->getAmountOfPiecesThatCheckCell() + 1);
}

bool KingPieceMovementChecker::isPawnViable(std::string diagonalDirection, int pawnPiecePlayer) {
    if (pawnPiecePlayer == 2
        && (diagonalDirection == CheckmateConstants::DIAGONAL_DIRECTION_TOP_LEFT
            || diagonalDirection == CheckmateConstants::DIAGONAL_DIRECTION_TOP_RIGHT)
    ) {
        return true;
    }

    if (pawnPiecePlayer == 1
        && (diagonalDirection == CheckmateConstants::DIAGONAL_DIRECTION_BOTTOM_LEFT
            || diagonalDirection == CheckmateConstants::DIAGONAL_DIRECTION_BOTTOM_RIGHT)
    ) {
        return true;
    }

    return false;
}
