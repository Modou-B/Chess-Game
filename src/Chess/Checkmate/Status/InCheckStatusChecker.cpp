//
// Created by Julian Sommer on 18.09.23.
//

#include "InCheckStatusChecker.h"
#include "../../ChessPiece/Movement/ChessPieceMovementTrait.h"
#include "../../Model/ChessField.h"
#include "../../Model/ChessCell.h"
#include "../../GameApplication/Player/ChessPlayerData.h"
#include "../../ChessPiece/BaseChessPiece.h"
#include "../../ChessPiece/Movement/KingPiece/KingPieceMovementChecker.h"
#include "../../../Shared/Chess/Transfer/Checkmate/InCheckResponseTransfer.h"
#include "../../../Shared/Chess/Transfer/Checkmate/InCheckBlockedCoordinatesTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"

InCheckStatusChecker::InCheckStatusChecker(KingPieceMovementChecker *kingPieceMovementChecker) {
    this->kingPieceMovementChecker = kingPieceMovementChecker;
}

InCheckResponseTransfer InCheckStatusChecker::getAmountOfPiecesThatCheckKing(ChessField *chessField, std::pair<int, int> kingPieceCoordinates, int currentPlayer) {
    int yCoordinate = kingPieceCoordinates.first;
    int xCoordinate = kingPieceCoordinates.second;

    InCheckResponseTransfer fullInCheckResponseTransfer = InCheckResponseTransfer();

    this->updateFullInCheckResponseTransfer(
        this->kingPieceMovementChecker->getVerticalCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, currentPlayer),
        &fullInCheckResponseTransfer
    );

    this->updateFullInCheckResponseTransfer(
        this->kingPieceMovementChecker->getHorizontalCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, currentPlayer),
        &fullInCheckResponseTransfer
    );

    this->updateFullInCheckResponseTransfer(
        this->kingPieceMovementChecker->getDiagonalCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, currentPlayer),
        &fullInCheckResponseTransfer
    );

    this->updateFullInCheckResponseTransfer(
        this->kingPieceMovementChecker->getKnightCheckAmountForGivenChessCell(chessField, xCoordinate, yCoordinate, currentPlayer),
        &fullInCheckResponseTransfer
    );

    return fullInCheckResponseTransfer;
}

void InCheckStatusChecker::updateFullInCheckResponseTransfer(InCheckResponseTransfer inCheckResponseTransfer, InCheckResponseTransfer *fullInCheckResponseTransfer) {
    if (inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() > 0) {
      fullInCheckResponseTransfer->setAmountOfPiecesThatCheckCell(
      fullInCheckResponseTransfer->getAmountOfPiecesThatCheckCell() + inCheckResponseTransfer.getAmountOfPiecesThatCheckCell());

      fullInCheckResponseTransfer->setLatestPieceTypeThatCheckKing(inCheckResponseTransfer.getLatestPieceTypeThatCheckKing());

      fullInCheckResponseTransfer->setLatestCoordinatesFromCellToOpponentPiece(inCheckResponseTransfer.getLatestCoordinatesFromCellToOpponentPiece());
    }
}

int InCheckStatusChecker::getAmountOfPiecesThatBlockCheck(ChessField *chessField, ChessPlayerData *chessPlayerData, InCheckResponseTransfer inCheckResponseTransfer, std::pair<int, int> kingPieceCoordinates, int currentPlayer) {
    int piecesThatBlockCheck = 0;
    this->hashInCheckCords(inCheckResponseTransfer);

    auto pawnPieces = chessPlayerData->getAllPawnPieces();
    piecesThatBlockCheck += this->getCheckBlockAmountForSpecificPieces(chessField, pawnPieces, kingPieceCoordinates, currentPlayer);

    auto rookPieces = chessPlayerData->getAllRookPieces();
    piecesThatBlockCheck += this->getCheckBlockAmountForSpecificPieces(chessField, rookPieces, kingPieceCoordinates, currentPlayer);

    auto knightPieces = chessPlayerData->getAllKnightPieces();
    piecesThatBlockCheck += this->getCheckBlockAmountForSpecificPieces(chessField, knightPieces, kingPieceCoordinates, currentPlayer);

    auto bishopPieces = chessPlayerData->getAllBishopPieces();
    piecesThatBlockCheck += this->getCheckBlockAmountForSpecificPieces(chessField, bishopPieces, kingPieceCoordinates, currentPlayer);

    auto queenPieces = chessPlayerData->getAllQueenPieces();
    piecesThatBlockCheck += this->getCheckBlockAmountForSpecificPieces(chessField, queenPieces, kingPieceCoordinates, currentPlayer);

    return piecesThatBlockCheck;
}

int InCheckStatusChecker::getCheckBlockAmountForSpecificPieces(
    ChessField *chessField, std::vector<BaseChessPiece*> specificPieces, std::pair<int, int> kingPieceCoordinates, int currentPlayer) {
    int blockAmount = 0;

    for (auto &specificPiece : specificPieces) {
        bool canPieceBlockCheck = false;
        specificPiece->setCheckBlockAbility(false);
        specificPiece->clearCoordinatesThatBlockCheck();

        auto possibleMoveTransfers = specificPiece->determinePossibleMoves(chessField, specificPiece->getCurrentCoordinates(), false);
        for (auto &possibleMoveTransfer : possibleMoveTransfers) {

            auto coordinates = std::make_pair(possibleMoveTransfer->getYCoordinate(), possibleMoveTransfer->getXCoordinate());
            auto *inCheckBlockedCoordinatesTransfer = this->hashedCoords[this->getHash(coordinates)];
            if (inCheckBlockedCoordinatesTransfer && inCheckBlockedCoordinatesTransfer->getIsRealTransfer()) {
                if (inCheckBlockedCoordinatesTransfer->getHasCoordinateOpponentPiece()
                    && this->verifyIfPieceTakeResultsInCheck(chessField, inCheckBlockedCoordinatesTransfer, specificPiece->getCurrentCoordinates(), kingPieceCoordinates, currentPlayer)) {
                    continue;
                }

                canPieceBlockCheck = true;
                specificPiece->addCoordinateThatBlockCheck(possibleMoveTransfer);
            }
        }

        if (canPieceBlockCheck) {
            blockAmount++;
            specificPiece->setCheckBlockAbility(true);
        }
    }

    return blockAmount;
}

bool InCheckStatusChecker::verifyIfPieceTakeResultsInCheck(
    ChessField *chessField, InCheckBlockedCoordinatesTransfer *inCheckBlockedCoordinatesTransfer, std::pair<int, int> kingPieceCoordinates, std::pair<int, int> coordinatesOfCheckedPiece, int currentPlayer) {
    int yCoordinate = kingPieceCoordinates.first;
    int xCoordinate = kingPieceCoordinates.second;

    ChessField *chessFieldCopy = chessField->getCopy();

    auto *previousChessCell = chessFieldCopy->getChessCell(coordinatesOfCheckedPiece);
    auto *newChessCell = chessFieldCopy->getChessCell(inCheckBlockedCoordinatesTransfer->getBlockedCoordinateFromCellToOpponentPiece());

    newChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    if (this->kingPieceMovementChecker->getHorizontalCheckAmountForGivenChessCell(chessFieldCopy, xCoordinate, yCoordinate, currentPlayer).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getVerticalCheckAmountForGivenChessCell(chessFieldCopy, xCoordinate, yCoordinate, currentPlayer).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getDiagonalCheckAmountForGivenChessCell(chessFieldCopy, xCoordinate, yCoordinate, currentPlayer).getAmountOfPiecesThatCheckCell() > 0
    ) {
        return true;
    }

    return false;
}

void InCheckStatusChecker::hashInCheckCords(InCheckResponseTransfer inCheckResponseTransfer) {
    for (auto &inCheckBlockedCoordinatesTransfer : inCheckResponseTransfer.getLatestCoordinatesFromCellToOpponentPiece()) {
        this->hashedCoords[this->getHash(inCheckBlockedCoordinatesTransfer->getBlockedCoordinateFromCellToOpponentPiece())] = inCheckBlockedCoordinatesTransfer;
    }
}

std::string InCheckStatusChecker::getHash(std::pair<int, int> coords) {
    return std::to_string(coords.second)+std::to_string(coords.first);
}

