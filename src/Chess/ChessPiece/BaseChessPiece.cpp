//
// Created by Julian Sommer on 26.08.23.
//

#include "BaseChessPiece.h"
#include "../../Shared/Chess/ChessConstants.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "../../Shared/Chess/Transfer/Checkmate/InCheckResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include "../Movement/Mapper/ChessPieceMovementMapper.h"
#include "Movement/KingPiece/KingPieceMovementChecker.h"
#include "PossibleMoves/PossibleMoveVerifierDataHelper.h"
#include "iostream"

BaseChessPiece::BaseChessPiece(
    std::string type, int player,
    ChessPieceMovementMapper *chessPieceMovementMapper, KingPieceMovementChecker *kingPieceMovementChecker) {
    this->type = type;
    this->player = player;
    this->kingPieceMovementChecker = kingPieceMovementChecker;
    this->chessPieceMovementMapper = chessPieceMovementMapper;
    this->moveCounter = 0;
    this->wasMovedLastTurn = false;
    this->canBlockCheck = false;
}

std::string BaseChessPiece::getType() {
    return this->type;
}

int BaseChessPiece::getPlayer() {
    return this->player;
}

std::vector<ChessPiecePossibleMoveTransfer*> BaseChessPiece::determinePossibleMoves(ChessField *chessField, std::pair<int, int> currentCoordinates, bool verifyInCheck) {
    std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves = std::vector<ChessPiecePossibleMoveTransfer*>();

    int xCoordinate = currentCoordinates.second;
    int yCoordinate = currentCoordinates.first;

    possibleMoves = this->determinePossibleMovesForSpecificPiece(chessField, possibleMoves, xCoordinate, yCoordinate);

    if (this->getType() != ChessConstants::KING_PIECE_TYPE && verifyInCheck) {
        if (this->verifyIfPieceMoveResultsInCheck(chessField, possibleMoves)) {
            return {};
        }
    }

    return possibleMoves;
}

bool BaseChessPiece::verifyIfPieceMoveResultsInCheck(ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves) {
    if (possibleMoves.empty()) {
        return false;
    }

    auto kingPieceCoordinates = this->kingPieceMovementChecker->getKingPieceCoordinatesForPlayer(this->player);
    int yCoordinate = kingPieceCoordinates.first;
    int xCoordinate = kingPieceCoordinates.second;

    ChessField *chessFieldCopy = chessField->getCopy();
    auto firstPossibleMoveTransfer = possibleMoves.front();

    auto *previousChessCell = chessFieldCopy->getChessCell(this->currentCoordinates);
    auto *newChessCell = chessFieldCopy->getChessCell(this->generateCoordinates(firstPossibleMoveTransfer->getXCoordinate(), firstPossibleMoveTransfer->getYCoordinate()));

    newChessCell->setChessPiece(previousChessCell->getChessPiece());
    previousChessCell->setChessPiece(nullptr);

    if (this->kingPieceMovementChecker->getHorizontalCheckAmountForGivenChessCell(chessFieldCopy, xCoordinate, yCoordinate, this->player).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getVerticalCheckAmountForGivenChessCell(chessFieldCopy, xCoordinate, yCoordinate, this->player).getAmountOfPiecesThatCheckCell() > 0
        || this->kingPieceMovementChecker->getDiagonalCheckAmountForGivenChessCell(chessFieldCopy, xCoordinate, yCoordinate, this->player).getAmountOfPiecesThatCheckCell() > 0
    ) {
        return true;
    }

    return false;
}

std::vector<ChessPiecePossibleMoveTransfer*> BaseChessPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> BaseChessPiece::tryToAddCoordinates(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate) {
    if (this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        return possibleMoves;
    }

    std::pair<int, int> coordinates = this->generateCoordinates(yCoordinate, xCoordinate);
    BaseChessPiece *chessPieceOnCell = chessField->getChessCell(coordinates)->getChessPiece();

    if (chessPieceOnCell && chessPieceOnCell->player == this->player) {
        return possibleMoves;
    }

    possibleMoves.push_back(this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(
            ChessMovementConstants::MOVE_TYPE_NORMAL, xCoordinate, yCoordinate));

    return possibleMoves;
}

std::vector<ChessPiecePossibleMoveTransfer*> BaseChessPiece::tryToAddCoordinatesForDiagonalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate)
{
    auto possibleMoveVerifierDataHelper = PossibleMoveVerifierDataHelper();
    possibleMoveVerifierDataHelper.setPossibleMoveVector(&possibleMoves);

    int originalYCoordinate = yCoordinate;
    int originalXCoordinate = xCoordinate;

    // Top right diagonal
    yCoordinate--;
    xCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        yCoordinate--;
        xCoordinate++;
    }

    possibleMoveVerifierDataHelper.resetVerifierProperties();

    yCoordinate = originalYCoordinate;
    xCoordinate = originalXCoordinate;

    // Top left diagonal
    yCoordinate--;
    xCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        yCoordinate--;
        xCoordinate--;
    }

    possibleMoveVerifierDataHelper.resetVerifierProperties();

    yCoordinate = originalYCoordinate;
    xCoordinate = originalXCoordinate;

    // Bottom right diagonal
    yCoordinate++;
    xCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        yCoordinate++;
        xCoordinate++;
    }

    possibleMoveVerifierDataHelper.resetVerifierProperties();

    yCoordinate = originalYCoordinate;
    xCoordinate = originalXCoordinate;

    // Bottom left diagonal
    yCoordinate++;
    xCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        yCoordinate++;
        xCoordinate--;
    }

    return *possibleMoveVerifierDataHelper.getPossibleMoveVector();
}

std::vector<ChessPiecePossibleMoveTransfer*> BaseChessPiece::tryToAddCoordinatesForVerticalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate)
{
    auto possibleMoveVerifierDataHelper = PossibleMoveVerifierDataHelper();
    possibleMoveVerifierDataHelper.setPossibleMoveVector(&possibleMoves);

    int originalYCoordinate = yCoordinate;
    yCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        yCoordinate++;
    }

    possibleMoveVerifierDataHelper.resetVerifierProperties();

    yCoordinate = originalYCoordinate;
    yCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        yCoordinate--;
    }

    return *possibleMoveVerifierDataHelper.getPossibleMoveVector();
}

std::vector<ChessPiecePossibleMoveTransfer*> BaseChessPiece::tryToAddCoordinatesForHorizontalMovement(
        ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate)
{
    auto possibleMoveVerifierDataHelper = PossibleMoveVerifierDataHelper();
    possibleMoveVerifierDataHelper.setPossibleMoveVector(&possibleMoves);

    int originalXCoordinate = xCoordinate;
    xCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        xCoordinate++;
    }

    possibleMoveVerifierDataHelper.resetVerifierProperties();

    xCoordinate = originalXCoordinate;
    xCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (possibleMoveVerifierDataHelper.getHasOpponentPieceAsPossibleMove() || possibleMoveVerifierDataHelper.getIsOwnChessPieceIsInFront()) {
            break;
        }

        possibleMoveVerifierDataHelper = this->checkOneLineMovement(chessField, &possibleMoveVerifierDataHelper, xCoordinate, yCoordinate);

        xCoordinate--;
    }

    return *possibleMoveVerifierDataHelper.getPossibleMoveVector();
}

PossibleMoveVerifierDataHelper BaseChessPiece::checkOneLineMovement(
        ChessField *chessField, PossibleMoveVerifierDataHelper *possibleMoveVerifierDataHelper, int xCoordinate, int yCoordinate) {
    std::pair<int, int> coordinates = this->generateCoordinates(yCoordinate, xCoordinate);
    BaseChessPiece *chessPieceOnCell = chessField->getChessCell(coordinates)->getChessPiece();

    if (chessPieceOnCell) {
        if (chessPieceOnCell->player == this->player) {
            possibleMoveVerifierDataHelper->setIsOwnChessPieceIsInFront(true);

            return *possibleMoveVerifierDataHelper;
        }

        possibleMoveVerifierDataHelper->setHasOpponentPieceAsPossibleMove(true);
    }

    possibleMoveVerifierDataHelper->getPossibleMoveVector()->push_back(
            this->chessPieceMovementMapper->generateChessPiecePossibleMoveTransfer(ChessMovementConstants::MOVE_TYPE_NORMAL, xCoordinate, yCoordinate));

    return *possibleMoveVerifierDataHelper;
}

void BaseChessPiece::handleMovement(ChessPiecePossibleMoveTransfer *usedMove) {
    this->moveCounter++;
    this->wasMovedLastTurn = true;
}

std::pair<int, int> BaseChessPiece::generateCoordinates(int xCoordinate, int yCoordinate) {
    return std::make_pair(xCoordinate, yCoordinate);
}

bool BaseChessPiece::areCoordinatesOutOfBounds(int xCoordinate, int yCoordinate) {
    if ((xCoordinate > 7 || xCoordinate < 0) || (yCoordinate > 7 || yCoordinate < 0)) {
        return true;
    }

    return false;
}

bool BaseChessPiece::hasCellOpponentChessPiece(ChessField *chessField, std::pair<int, int> coordinates) {
    BaseChessPiece *chessPieceOnCell = chessField->getChessCell(coordinates)->getChessPiece();

    return this->isOpponentChessPiece(chessPieceOnCell);
}

bool BaseChessPiece::hasCellChessPiece(ChessField *chessField, std::pair<int, int> coordinates) {
    BaseChessPiece *chessPieceOnCell = chessField->getChessCell(coordinates)->getChessPiece();

    if (chessPieceOnCell) {
        return true;
    }

    return false;
}

BaseChessPiece *BaseChessPiece::getChessPiece(ChessField *chessField, int xCoordinate, int yCoordinate) {
    auto coordinates = this->generateCoordinates(yCoordinate, xCoordinate);

    return chessField->getChessCell(coordinates)->getChessPiece();
}

bool BaseChessPiece::isOpponentChessPiece(BaseChessPiece *chessPiece) {
    if (chessPiece && chessPiece->player != this->player) {
        return true;
    }

    return false;
}

int BaseChessPiece::getMoveCounter() {
    return this->moveCounter;
}

std::pair<int, int> BaseChessPiece::getCurrentCoordinates() {
    return this->currentCoordinates;
}

std::vector<ChessPiecePossibleMoveTransfer *> BaseChessPiece::getCoordinatesThatBlockCheck() {
    return this->coordinatesThatBlockCheck;
}

bool BaseChessPiece::canPieceBlockCheck() {
    return this->canBlockCheck;
}

bool BaseChessPiece::wasChessPieceMovedLastTurn() {
    return this->wasMovedLastTurn;
}

void BaseChessPiece::setCheckBlockAbility(bool value) {
    this->canBlockCheck = value;
}

void BaseChessPiece::setCurrentCoordinates(std::pair<int, int> currentCoordinates) {
    this->currentCoordinates = currentCoordinates;
}

void BaseChessPiece::setCoordinatesThatBlockCheck(std::vector<ChessPiecePossibleMoveTransfer*> coordinatesThatBlockCheck) {
    this->coordinatesThatBlockCheck = coordinatesThatBlockCheck;
}

void BaseChessPiece::addCoordinateThatBlockCheck(ChessPiecePossibleMoveTransfer *coordinateThatBlocksCheck) {
    this->coordinatesThatBlockCheck.push_back(coordinateThatBlocksCheck);
}

void BaseChessPiece::clearCoordinatesThatBlockCheck() {
    this->coordinatesThatBlockCheck.clear();
}

void BaseChessPiece::updateLastTurnMovedStatus() {
    this->wasMovedLastTurn = false;
}
