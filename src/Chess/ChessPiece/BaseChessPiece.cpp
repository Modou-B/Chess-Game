//
// Created by Julian Sommer on 26.08.23.
//

#include "BaseChessPiece.h"
#include "../Model/ChessField.h"
#include "../Model/ChessCell.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "iostream"

BaseChessPiece::BaseChessPiece(std::string type, int player) {
    this->type = type;
    this->player = player;
}

std::string BaseChessPiece::getType() {
    return this->type;
}

int BaseChessPiece::getPlayer() {
    return this->player;
}

std::vector<std::pair<int, int>> BaseChessPiece::determinePossibleMoves(ChessField *chessField, std::pair<int, int> currentCoordinates) {
    std::vector<std::pair<int, int>> possibleMoves = std::vector<std::pair<int, int>>();

    int xCoordinate = currentCoordinates.second;
    int yCoordinate = currentCoordinates.first;

    return this->determinePossibleMovesForSpecificPiece(chessField, possibleMoves, xCoordinate, yCoordinate);
}

std::vector<std::pair<int, int>> BaseChessPiece::determinePossibleMovesForSpecificPiece(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {

    return possibleMoves;
}

std::vector<std::pair<int, int>> BaseChessPiece::tryToAddCoordinates(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    if (this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        return possibleMoves;
    }

    std::pair<int, int> coordinates = this->generateCoordinates(yCoordinate, xCoordinate);

    BaseChessPiece *chessPieceOnCell = chessField->getChessCell(coordinates)->getChessPiece();

    if (chessPieceOnCell && chessPieceOnCell->player == this->player) {
        return possibleMoves;
    }

    std::pair<int, int> actualCoords = this->generateCoordinates(xCoordinate, yCoordinate);

    possibleMoves.push_back(actualCoords);

    return possibleMoves;
}

std::vector<std::pair<int, int>> BaseChessPiece::tryToAddCoordinatesForDiagonalMovement(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    ChessPiecePossibleMoveTransfer chessPiecePossibleMoveTransfer = ChessPiecePossibleMoveTransfer();
    chessPiecePossibleMoveTransfer.setPossibleMoveVector(&possibleMoves);


    int originalYCoordinate = yCoordinate;
    int originalXCoordinate = xCoordinate;

    // Top right diagonal
    yCoordinate--;
    xCoordinate++;
    while (this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate) == false) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        yCoordinate--;
        xCoordinate++;
    }

    chessPiecePossibleMoveTransfer.setHasOpponentPieceAsPossibleMove(false);
    chessPiecePossibleMoveTransfer.setIsOwnChessPieceIsInFront(false);

    yCoordinate = originalYCoordinate;
    xCoordinate = originalXCoordinate;

    // Top left diagonal
    yCoordinate--;
    xCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        yCoordinate--;
        xCoordinate--;
    }

    chessPiecePossibleMoveTransfer.setHasOpponentPieceAsPossibleMove(false);
    chessPiecePossibleMoveTransfer.setIsOwnChessPieceIsInFront(false);

    yCoordinate = originalYCoordinate;
    xCoordinate = originalXCoordinate;

    // Bottom right diagonal
    yCoordinate++;
    xCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        yCoordinate++;
        xCoordinate++;
    }

    chessPiecePossibleMoveTransfer.setHasOpponentPieceAsPossibleMove(false);
    chessPiecePossibleMoveTransfer.setIsOwnChessPieceIsInFront(false);

    yCoordinate = originalYCoordinate;
    xCoordinate = originalXCoordinate;

    // Bottom left diagonal
    yCoordinate++;
    xCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        yCoordinate++;
        xCoordinate--;
    }

    return *chessPiecePossibleMoveTransfer.getPossibleMoveVector();
}

std::vector<std::pair<int, int>> BaseChessPiece::tryToAddCoordinatesForVerticalMovement(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    ChessPiecePossibleMoveTransfer chessPiecePossibleMoveTransfer = ChessPiecePossibleMoveTransfer();
    chessPiecePossibleMoveTransfer.setPossibleMoveVector(&possibleMoves);

    int originalYCoordinate = yCoordinate;
    yCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        yCoordinate++;
    }

    chessPiecePossibleMoveTransfer.setHasOpponentPieceAsPossibleMove(false);
    chessPiecePossibleMoveTransfer.setIsOwnChessPieceIsInFront(false);

    yCoordinate = originalYCoordinate;
    yCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        yCoordinate--;
    }

    return *chessPiecePossibleMoveTransfer.getPossibleMoveVector();
}

std::vector<std::pair<int, int>> BaseChessPiece::tryToAddCoordinatesForHorizontalMovement(
        ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate) {
    ChessPiecePossibleMoveTransfer chessPiecePossibleMoveTransfer = ChessPiecePossibleMoveTransfer();
    chessPiecePossibleMoveTransfer.setPossibleMoveVector(&possibleMoves);

    int originalXCoordinate = xCoordinate;
    xCoordinate++;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        xCoordinate++;
    }

    chessPiecePossibleMoveTransfer.setHasOpponentPieceAsPossibleMove(false);
    chessPiecePossibleMoveTransfer.setIsOwnChessPieceIsInFront(false);

    xCoordinate = originalXCoordinate;
    xCoordinate--;
    while (!this->areCoordinatesOutOfBounds(xCoordinate, yCoordinate)) {
        if (chessPiecePossibleMoveTransfer.getHasOpponentPieceAsPossibleMove() || chessPiecePossibleMoveTransfer.getIsOwnChessPieceIsInFront()) {
            break;
        }

        chessPiecePossibleMoveTransfer = this->checkOneLineMovement(chessField, &chessPiecePossibleMoveTransfer, xCoordinate, yCoordinate);

        xCoordinate--;
    }

    return *chessPiecePossibleMoveTransfer.getPossibleMoveVector();
}

ChessPiecePossibleMoveTransfer BaseChessPiece::checkOneLineMovement(
        ChessField *chessField, ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer, int xCoordinate, int yCoordinate) {
    std::pair<int, int> coordinates = this->generateCoordinates(yCoordinate, xCoordinate);
    BaseChessPiece *chessPieceOnCell = chessField->getChessCell(coordinates)->getChessPiece();

    if (chessPieceOnCell) {
        if (chessPieceOnCell->player == this->player) {
            chessPiecePossibleMoveTransfer->setIsOwnChessPieceIsInFront(true);

            return *chessPiecePossibleMoveTransfer;
        }

        chessPiecePossibleMoveTransfer->setHasOpponentPieceAsPossibleMove(true);
    }
    std::pair<int, int> coordinates2 = this->generateCoordinates(xCoordinate, yCoordinate);

    chessPiecePossibleMoveTransfer->getPossibleMoveVector()->push_back(coordinates2);

    return *chessPiecePossibleMoveTransfer;
}

void BaseChessPiece::handleMovement() {
    return;
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