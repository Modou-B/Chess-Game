//
// Created by Julian Sommer on 10.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVECOLLECTIONTRANSFER_H
#define CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVECOLLECTIONTRANSFER_H

#include <utility>
#include <vector>

class ChessPiecePossibleMoveTransfer;

class ChessPiecePossibleMoveCollectionTransfer {
private:
    std::vector<ChessPiecePossibleMoveTransfer*> *possibleMoves;
    bool hasOpponentPieceAsPossibleMove;
    bool isOwnChessPieceIsInFront;

public:
    ChessPiecePossibleMoveCollectionTransfer();

    std::vector<ChessPiecePossibleMoveTransfer*> *getPossibleMoveVector();
    bool getHasOpponentPieceAsPossibleMove();
    bool getIsOwnChessPieceIsInFront();

    void setPossibleMoveVector(std::vector<ChessPiecePossibleMoveTransfer*> *possibleMoves);
    void setHasOpponentPieceAsPossibleMove(bool value);
    void setIsOwnChessPieceIsInFront(bool value);
};


#endif //CHESSAPPLICATION_CHESSPIECEPOSSIBLEMOVECOLLECTIONTRANSFER_H
