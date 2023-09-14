//
// Created by Julian Sommer on 10.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H

#include <utility>
#include <vector>

class ChessPiecePossibleMoveTransfer {
private:
    std::vector<std::pair<int, int>> *possibleMoves;
    bool hasOpponentPieceAsPossibleMove;

public:
    ChessPiecePossibleMoveTransfer();

    std::vector<std::pair<int, int>> *getPossibleMoveVector();
    bool getHasOpponentPieceAsPossibleMove();

    void setPossibleMoveVector(std::vector<std::pair<int, int>> *possibleMoves);
    void setHasOpponentPieceAsPossibleMove(bool value);
};


#endif //CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVETRANSFER_H
