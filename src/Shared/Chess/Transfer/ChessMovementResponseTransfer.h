//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
#define CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H

#include <utility>

class ChessMovementResponseTransfer {
private:
    bool hasPieceMoved;
    std::pair<int, int> previousCellCoordinates;
    std::pair<int, int> currentCellCoordinates;
public:
    ChessMovementResponseTransfer();

    bool wasPieceMoved();

    std::pair<int, int> getPreviousCellCoordinates();
    std::pair<int, int> getCurrentCellCoordinates();

    void togglePieceMovementValue();

    ChessMovementResponseTransfer &setPreviousCellCoordinates(std::pair<int, int> coordinates);
    ChessMovementResponseTransfer &setCurrentCellCoordinates(std::pair<int, int> coordinates);
};


#endif //CHESSAPPLICATION_CHESSMOVEMENTRESPONSETRANSFER_H
