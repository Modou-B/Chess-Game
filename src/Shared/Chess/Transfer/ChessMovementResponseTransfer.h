//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
#define CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H

#include <utility>
#include <string>

class ChessMovementResponseTransfer {
private:
    std::string state;
    bool hasPieceMoved;
    std::pair<int, int> previousCellCoordinates;
    std::pair<int, int> currentCellCoordinates;

    bool hasPossibleMoves;
    std::vector<std::pair<int, int>> *previousPossibleMoves;
    std::vector<std::pair<int, int>> *possibleMoves;

public:
    ChessMovementResponseTransfer();

    bool wasPieceMoved();
    bool doesPieceHasPossibleMoves();

    std::pair<int, int> getPreviousCellCoordinates();
    std::pair<int, int> getCurrentCellCoordinates();
    std::vector<std::pair<int, int>> *getPossibleMoves();
    std::vector<std::pair<int, int>> *getPreviousPossibleMoves();
    std::string getState();

    void togglePieceMovementValue();
    void togglePossibleMovesCheckValue();

    ChessMovementResponseTransfer &setPreviousCellCoordinates(std::pair<int, int> coordinates);
    ChessMovementResponseTransfer &setCurrentCellCoordinates(std::pair<int, int> coordinates);
    void setState(std::string state);

    void setPossibleMoves(std::vector<std::pair<int, int>> *possibleMoves);
    void setPreviousPossibleMoves(std::vector<std::pair<int, int>> *previousPossibleMoves);
};


#endif //CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
