//
// Created by Julian Sommer on 26.08.23.
//

#ifndef CHESSAPPLICATION_BASECHESSPIECE_H
#define CHESSAPPLICATION_BASECHESSPIECE_H

#include <string>
#include <vector>
#include <utility>

class ChessField;
class ChessPiecePossibleMoveCollectionTransfer;
class ChessPiecePossibleMoveTransfer;
class ChessPieceMovementGenerator;

class BaseChessPiece {
private:
    std::string type;
    int player;
    bool wasMovedLastTurn;
    bool canBlockCheck;

    std::pair<int, int> currentCoordinates;
    std::vector<ChessPiecePossibleMoveTransfer*> coordinatesThatBlockCheck;
protected:
    ChessPieceMovementGenerator *chessPieceMovementGenerator;
    int moveCounter;

    std::pair<int, int> generateCoordinates(int xCoordinate, int yCoordinate);
    std::vector<ChessPiecePossibleMoveTransfer*> tryToAddCoordinates(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);

    bool areCoordinatesOutOfBounds(int xCoordinate, int yCoordinate);

    std::vector<ChessPiecePossibleMoveTransfer*> tryToAddCoordinatesForVerticalMovement(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);
    std::vector<ChessPiecePossibleMoveTransfer*> tryToAddCoordinatesForHorizontalMovement(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);

    std::vector<ChessPiecePossibleMoveTransfer*> tryToAddCoordinatesForDiagonalMovement(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);

    ChessPiecePossibleMoveCollectionTransfer checkOneLineMovement(
            ChessField *chessField, ChessPiecePossibleMoveCollectionTransfer *chessPiecePossibleMoveTransfer, int xCoordinate, int yCoordinate);

    bool hasCellOpponentChessPiece(ChessField *chessField, std::pair<int, int> coordinates);

    bool isOpponentChessPiece(BaseChessPiece *chessPiece);

    BaseChessPiece *getChessPiece(ChessField *chessField, int xCoordinate, int yCoordinate);
public:
    BaseChessPiece(
      std::string type, int player, ChessPieceMovementGenerator *chessPieceMovementGenerator);

    std::string getType();
    int getPlayer();
    int getMoveCounter();
    std::pair<int, int> getCurrentCoordinates();
    std::vector<ChessPiecePossibleMoveTransfer*> getCoordinatesThatBlockCheck();

    bool canPieceBlockCheck();
    bool wasChessPieceMovedLastTurn();
    void setCheckBlockAbility(bool value);
    void setCurrentCoordinates(std::pair<int, int> currentCoordinates);
    void setCoordinatesThatBlockCheck(std::vector<ChessPiecePossibleMoveTransfer*> coordinatesThatBlockCheck);
    void addCoordinateThatBlockCheck(ChessPiecePossibleMoveTransfer *coordinateThatBlocksCheck);

    void clearCoordinatesThatBlockCheck();

    std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMoves(ChessField *chessField, std::pair<int, int> currentCoordinates);
    virtual std::vector<ChessPiecePossibleMoveTransfer*> determinePossibleMovesForSpecificPiece(
            ChessField *chessField, std::vector<ChessPiecePossibleMoveTransfer*> possibleMoves, int xCoordinate, int yCoordinate);

    virtual void handleMovement(ChessPiecePossibleMoveTransfer *usedMove);

    void updateLastTurnMovedStatus();
};


#endif //CHESSAPPLICATION_BASECHESSPIECE_H
