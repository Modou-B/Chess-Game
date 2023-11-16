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

void GameApplicationDataWriter::writeMultiplayerStartData(
    int currentPlayer,
    int opponentPlayer
) {
    GameApplication::setIsMultiplayerMatch(true);

    if (currentPlayer == 2) {
        GameApplication::setIsOpponentTurn(true);
    }

    if (currentPlayer == 1) {
        GameApplication::setIsOpponentTurn(false);
    }

    GameApplication::setCurrentPlayer(currentPlayer);
    GameApplication::setCurrentOpponentPlayer(opponentPlayer);
}

void GameApplicationDataWriter::setOpponentTurn(bool isOpponentTurn) {
    GameApplication::setIsOpponentTurn(isOpponentTurn);
}