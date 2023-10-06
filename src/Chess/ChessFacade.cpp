//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"
#include "Model/ChessCell.h"
#include "../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"

void ChessFacade::initiateChessGame() {
    ChessFacade::getFactory()->createGameApplicationManager()->initiateChessApplication();
}

ChessMovementResponseTransfer ChessFacade::handleChessCellClick(pair<int, int> currentCellCoordinates) {
    return ChessFacade::getFactory()->createGameApplicationManager()->handleChessCellClick(currentCellCoordinates);
}

void ChessFacade::handlePawnPieceSwitch(string switchedPieceType) {
    ChessFacade::getFactory()->createGameApplicationManager()->handlePawnPieceSwitch(switchedPieceType);
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

void ChessFacade::updateCurrentGameState(string gameState) {
    ChessFacade::getFactory()->createGameApplicationDataWriter()->updateGameApplicationCurrentGameState(gameState);
}

void ChessFacade::rewindCurrentTurn(
    ChessTurnLogTransfer *chessTurnLogTransfer
) {
    ChessFacade::getFactory()->createGameApplicationManager()
        ->rewindCurrentTurn(chessTurnLogTransfer);
}

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}
