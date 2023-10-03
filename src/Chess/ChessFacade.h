//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_CHESSFACADE_H
#define CHESSAPPLICATION_CHESSFACADE_H

#include <string>
#include <utility>
#include "../Application/Facade/AbstractFacade.h"
#include "ChessFactory.h"

class ChessCell;
class ChessField;
class BaseChessPiece;
class ChessMovementResponseTransfer;
class ChessPiecePositionTransfer;

class ChessFacade: public AbstractFacade {
public:
    void initiateChessGame();
    void endCurrentTurn(
        ChessMovementResponseTransfer chessMovementResponseTransfer,
        ChessPiecePositionTransfer chessPiecePositionTransfer
    );

    void startNewTurn();

    int getCurrentPlayer();

    ChessMovementResponseTransfer handleChessCellClick(std::pair<int, int> currentCellCoordinates);
    void handlePawnPieceSwitch(ChessPiecePositionTransfer chessPiecePositionTransfer, std::string switchedPieceType);

    ChessFactory *getFactory() override;
};


#endif //CHESSAPPLICATION_CHESSFACADE_H
