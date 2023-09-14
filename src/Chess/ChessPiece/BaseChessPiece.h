//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_BASECHESSPIECE_H
#define CHESSAPPLICATION_BASECHESSPIECE_H

#include <string>
#include <vector>
#include <utility>

class ChessField;
class ChessPiecePossibleMoveTransfer;

class BaseChessPiece {
private:
    std::string type;
    int player;

protected:
    std::pair<int, int> generateCoordinates(int xCoordinate, int yCoordinate);
    std::vector<std::pair<int, int>> tryToAddCoordinates(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);

    bool areCoordinatesOutOfBounds(int xCoordinate, int yCoordinate);

    std::vector<std::pair<int, int>> tryToAddCoordinatesForVerticalMovement(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<std::pair<int, int>> tryToAddCoordinatesForHorizontalMovement(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);

    std::vector<std::pair<int, int>> tryToAddCoordinatesForDiagonalMovement(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);

    ChessPiecePossibleMoveTransfer checkOneLineMovement(
            ChessField *chessField, ChessPiecePossibleMoveTransfer *chessPiecePossibleMoveTransfer, int xCoordinate, int yCoordinate);

public:
    BaseChessPiece(std::string type, int player);

    std::string getType();
    int getPlayer();

    std::vector<std::pair<int, int>> determinePossibleMoves(ChessField *chessField, std::pair<int, int> currentCoordinates);
    virtual std::vector<std::pair<int, int>> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<std::pair<int, int>> possibleMoves, int xCoordinate, int yCoordinate);

    virtual void handleMovement();
};


#endif //CHESSAPPLICATION_BASECHESSPIECE_H
