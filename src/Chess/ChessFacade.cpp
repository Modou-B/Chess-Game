//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"
#include "Model/ChessCell.h"
#include "../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}

void ChessFacade::initiateChessGame() {
    ChessFacade::getFactory()->createGameApplicationManager()->initiateChessApplication();
}

ChessMovementResponseTransfer ChessFacade::handleChessCellClick(std::pair<int, int> currentCellCoordinates) {
    return ChessFacade::getFactory()->createGameApplicationManager()->handleChessCellClick(currentCellCoordinates);
}

void ChessFacade::handlePawnPieceSwitch(ChessPiecePositionTransfer chessPiecePositionTransfer, std::string switchedPieceType) {
    ChessFacade::getFactory()->createGameApplicationManager()->handlePawnPieceSwitch(chessPiecePositionTransfer, switchedPieceType);
}

void ChessFacade::endCurrentTurn(
    ChessMovementResponseTransfer chessMovementResponseTransfer,
    ChessPiecePositionTransfer chessPiecePositionTransfer
) {
    ChessFacade::getFactory()
      ->createGameApplicationManager()
      ->endCurrentTurn(
          chessMovementResponseTransfer,
          chessPiecePositionTransfer
      );
}

void ChessFacade::startNewTurn() {
    ChessFacade::getFactory()->createGameApplicationManager()->startNewTurn();
}

int ChessFacade::getCurrentPlayer() {
    return ChessFacade::getFactory()->createGameApplicationManager()->getCurrentPlayer();
}
