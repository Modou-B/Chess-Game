//
// Created by Julian Sommer on 02.10.23.
//

#ifndef CHESSAPPLICATION_POSSIBLEMOVEVERIFIERDATAHELPER_H
#define CHESSAPPLICATION_POSSIBLEMOVEVERIFIERDATAHELPER_H

#include <vector>

using namespace std;

class ChessPiecePossibleMoveTransfer;

class PossibleMoveVerifierDataHelper {
private:
  vector<ChessPiecePossibleMoveTransfer*> *possibleMoves;
  bool hasOpponentPieceAsPossibleMove;
  bool isOwnChessPieceIsInFront;

public:
    PossibleMoveVerifierDataHelper();

    vector<ChessPiecePossibleMoveTransfer*> *getPossibleMoveVector();
    bool getHasOpponentPieceAsPossibleMove();
    bool getIsOwnChessPieceIsInFront();

    void setPossibleMoveVector(vector<ChessPiecePossibleMoveTransfer*> *possibleMoves);
    void setHasOpponentPieceAsPossibleMove(bool value);
    void setIsOwnChessPieceIsInFront(bool value);

    void resetVerifierProperties();
};

#endif // CHESSAPPLICATION_POSSIBLEMOVEVERIFIERDATAHELPER_H
