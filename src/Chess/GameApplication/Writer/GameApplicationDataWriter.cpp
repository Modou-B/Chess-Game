//
// Created by Julian Sommer on 03.10.23.
//

#include "GameApplicationDataWriter.h"
#include "../../../Shared/Chess/Transfer/GameState/ChessGameStateTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../GameApplication.h"
#include "../Mapper/GameApplicationDataMapper.h"
#include "../Player/ChessPlayerData.h"

GameApplicationDataWriter::GameApplicationDataWriter(
    GameApplicationDataMapper *gameApplicationDataMapper
) {
    this->gameApplicationDataMapper = gameApplicationDataMapper;
}

void GameApplicationDataWriter::updateGameApplicationData(
    ChessGameStateTransfer *chessGameStateTransfer
) {
    GameApplication::setCurrentGameState(chessGameStateTransfer->getCurrentGameState());
    GameApplication::setCurrentPlayer(chessGameStateTransfer->getCurrentPlayer());
    GameApplication::setCurrentOpponentPlayer(chessGameStateTransfer->getCurrentOpponentPlayer());
    GameApplication::setTurnCounter(chessGameStateTransfer->getTurnCounter());

    if (chessGameStateTransfer->getTurnCounter() > 0) {
        GameApplication::setCoordinatesOfLastTurnClickedCell(
            chessGameStateTransfer->getLastTurnClickedCellCoordinate()
        );
    }
}

void GameApplicationDataWriter::updateGameApplicationCurrentGameState(string gameState) {
    GameApplication::setCurrentGameState(gameState);
}

void GameApplicationDataWriter::saveChessMovementResponseTransfer(
    ChessMovementResponseTransfer chessMovementResponseTransfer
) {
    GameApplication::saveChessMovementResponseTransfer(chessMovementResponseTransfer);
}

void GameApplicationDataWriter::saveChessPieceForChessPlayerData(
    BaseChessPiece *chessPiece,
    string type,
    int player
) {
    auto *chessPlayerData = GameApplication::getChessPlayerDataForPlayer(player);

    chessPlayerData->addPieceByType(chessPiece, type);
}