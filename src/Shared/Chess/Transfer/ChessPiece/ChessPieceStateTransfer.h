//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECESTATETRANSFER_H
#define CHESSAPPLICATION_CHESSPIECESTATETRANSFER_H

#include <utility>
#include <string>

using namespace std;

class ChessPieceStateTransfer {
private:
    int playerOfChessPiece;
    string chessPieceType;
    string state;
    pair<int, int> startCoordinate;
    pair<int, int> endCoordinate;

public:   
    ChessPieceStateTransfer *setPlayerOfChessPiece(int player);
    ChessPieceStateTransfer *setChessPieceType(string chessPieceType);
    ChessPieceStateTransfer *setState(string chessPieceState);
    ChessPieceStateTransfer *setStartCoordinate(pair<int, int> startCoordinate);
    ChessPieceStateTransfer *setEndCoordinate(pair<int, int> endCoordinate);

    int getPlayerOfChessPiece();
    string getChessPieceType();
    string getState();
    pair<int, int> getStartCoordinate();
    pair<int, int> getEndCoordinate();
};

#endif // CHESSAPPLICATION_CHESSPIECESTATETRANSFER_H
