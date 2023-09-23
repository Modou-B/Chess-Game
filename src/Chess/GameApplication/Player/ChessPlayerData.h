//
// Created by Julian Sommer on 22.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPLAYERDATA_H
#define CHESSAPPLICATION_CHESSPLAYERDATA_H

#include <vector>
#include <string>

class BaseChessPiece;

class ChessPlayerData {
private:
    std::vector<BaseChessPiece*> *activePawnPieces;
    std::vector<BaseChessPiece*> *activeRookPieces;
    std::vector<BaseChessPiece*> *activeKnightPieces;
    std::vector<BaseChessPiece*> *activeBishopPieces;
    std::vector<BaseChessPiece*> *activeQueenPieces;
    BaseChessPiece *activeKingPiece;

    int chessPieceAmount;
    bool isInCheck;
protected:
    std::vector<BaseChessPiece*> *getChessPiecesForType(std::string pieceType);

public:
    ChessPlayerData();

    void addPieceByType(BaseChessPiece *chessPiece, std::string pieceType);

    void addPawnPiece(BaseChessPiece *pawnPiece);
    void addRookPiece(BaseChessPiece *rookPiece);
    void addKnightPiece(BaseChessPiece *knightPiece);
    void addBishopPiece(BaseChessPiece *bishopPiece);
    void addQueenPiece(BaseChessPiece *queenPiece);
    void setKingPiece(BaseChessPiece *kingPiece);
    void setInCheckStatus(bool value);

    std::vector<BaseChessPiece*> getAllPawnPieces();
    std::vector<BaseChessPiece*> getAllRookPieces();
    std::vector<BaseChessPiece*> getAllKnightPieces();
    std::vector<BaseChessPiece*> getAllBishopPieces();
    std::vector<BaseChessPiece*> getAllQueenPieces();
    BaseChessPiece *getKingPiece();
    int getChessPieceAmount();

    bool isPlayerInCheck();

    void removePiece(BaseChessPiece *chessPiece);
};

#endif // CHESSAPPLICATION_CHESSPLAYERDATA_H
