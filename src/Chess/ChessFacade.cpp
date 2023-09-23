//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"
#include "Model/ChessCell.h"
#include "../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}

void ChessFacade::initiateChessGame() {
    ChessFacade::getFactory()->createGameApplicationManager()->initiateChessApplication();
}

ChessMovementResponseTransfer ChessFacade::handleChessCellClick(std::pair<int, int> currentCellCoordinates) {
    return ChessFacade::getFactory()->createGameApplicationManager()->handleChessCellClick(currentCellCoordinates);
}

void ChessFacade::endCurrentTurn(ChessMovementResponseTransfer chessMovementResponseTransfer) {
    ChessFacade::getFactory()->createGameApplicationManager()->endCurrentTurn(chessMovementResponseTransfer);
}

void ChessFacade::startNewTurn() {
    ChessFacade::getFactory()->createGameApplicationManager()->startNewTurn();
}
