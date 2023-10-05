//
// Created by Julian Sommer on 16.09.23.
//

#ifndef CHESSAPPLICATION_CHESSPIECEMOVEMENTMANAGER_H
#define CHESSAPPLICATION_CHESSPIECEMOVEMENTMANAGER_H

#include <utility>
#include <string>
#include <vector>

using namespace std;

class ChessField;
class ChessCreator;
class ChessCell;
class ChessPlayerData;
class ChessMovementResponseTransfer;
class ChessPiecePossibleMoveTransfer;
class ChessPieceMovementMapper;
class ChessPieceMovementReader;
class ChessPieceMovementWriter;
class BaseChessPiece;

class ChessTurnLogTransfer;
class ChessPieceInformationTransfer;

class ChessPieceMovementManager {
private:
    ChessPieceMovementMapper *chessPieceMovementMapper;
    ChessPieceMovementWriter *chessPieceMovementWriter;
    ChessPieceMovementReader *chessPieceMovementReader;

protected:
    ChessMovementResponseTransfer handleMovementWithoutPreviousClickedCell(
      ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, bool isPlayerInCheck);
    ChessMovementResponseTransfer handleMovementWithPreviousClickedCell(
        ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, bool isPlayerInCheck, ChessPlayerData *opponentPlayerData);

    ChessMovementResponseTransfer moveChessPiece(
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPiecePossibleMoveTransfer *usedMove, ChessPlayerData *opponentPlayerData);

    ChessMovementResponseTransfer addEnPassantChessPieceMovement(
        ChessCell *previousChessCell, ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer, ChessPlayerData *opponentPlayerData);

    ChessMovementResponseTransfer addCastlingChessPieceMovement(
        ChessCell *currentChessCell, ChessMovementResponseTransfer chessMovementResponseTransfer);

    void saveClickedCellCoordinates(pair<int, int> currentCellCoordinates);
    void savePossibleMovesForClickedPiece(
        BaseChessPiece *clickedChessPiece,
        bool isPlayerInCheck
    );

    bool doesChessPieceBelongToCurrentPlayer(BaseChessPiece *currentChessPiece);

    vector<ChessPiecePossibleMoveTransfer*> getPossibleMovesForCheckStatus(BaseChessPiece *clickedChessPiece, bool isPlayerInCheck);

    ChessMovementResponseTransfer finalizeChessMovementResponse(ChessMovementResponseTransfer chessMovementResponseTransfer);

    void expandResponseWithPossibleMoves(ChessMovementResponseTransfer &chessMovementResponseTransfer);
public:
    ChessPieceMovementManager(
      ChessPieceMovementMapper *chessPieceMovementMapper,
      ChessPieceMovementWriter *chessPieceMovementWriter,
      ChessPieceMovementReader *chessPieceMovementReader
    );

    ChessMovementResponseTransfer handleChessMovement(
        pair<int, int> currentCellCoordinates,
        ChessMovementResponseTransfer chessMovementResponseTransfer,
        bool isPlayerInCheck,
        ChessPlayerData *opponentPlayerData
    );

    void updateChessGrid(
        ChessTurnLogTransfer *chessTurnLogTransfer,
        string mode
    );

    void handleChessPieceStates(
        ChessPieceInformationTransfer *chessPieceInformationTransfer,
        string mode
    );

    void clearPossibleMoveCollections();
};


#endif //CHESSAPPLICATION_CHESSPIECEMOVEMENTMANAGER_H
