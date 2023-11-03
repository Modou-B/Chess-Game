//
// Created by Julian Sommer on 26.09.23.
//

#include "GameApplicationDataReader.h"
#include "../GameApplication.h"
#include "../Mapper/GameApplicationDataMapper.h"
#include "../Player/ChessPlayerData.h"
#include "../../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../../Shared/Chess/Transfer/GameState/ChessGameStateTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"

GameApplicationDataReader::GameApplicationDataReader(GameApplicationDataMapper *gameApplicationDataMapper)
{
    this->gameApplicationDataMapper = gameApplicationDataMapper;
}

ChessGameStateTransfer *GameApplicationDataReader::getCurrentGameStateData()
{
    auto chessGameStateTransfer = new ChessGameStateTransfer();

    chessGameStateTransfer->setCurrentGameState(this->getCurrentGameState())
        ->setCurrentPlayer(this->getCurrentPlayer())
        ->setCurrentOpponentPlayer(this->getCurrentOpponentPlayer())
        ->setTurnCounter(this->getTurnCounter())
        ->setLastTurnClickedCellCoordinate(GameApplication::getCoordinatesOfLastTurnClickedCell());

    return chessGameStateTransfer;
}

ChessPiecePositionTransfer GameApplicationDataReader::getKingPiecePositionByPlayer(int player)
{
    return this->gameApplicationDataMapper
            ->mapChessPieceToChessPiecePositionTransfer(
                GameApplication::getChessPlayerDataForPlayer(player)->getKingPiece()
            );
}

ChessMovementResponseTransfer GameApplicationDataReader::getSavedChessMovementResponseTransfer() {
    return GameApplication::getSavedChessMovementResponseTransfer();
}

int GameApplicationDataReader::getCurrentPlayer() {
    return GameApplication::getCurrentPlayer();
}

int GameApplicationDataReader::getCurrentOpponentPlayer() {
    if (GameApplication::getCurrentPlayer() == 1) {
        return 2;
    }

    return 1;
}

int GameApplicationDataReader::getTurnCounter() {
    return GameApplication::getTurnCounter();
}

string GameApplicationDataReader::getCurrentGameState() {
    return GameApplication::getCurrentGameState();
}

bool GameApplicationDataReader::isMultiplayerMatch() {
    return GameApplication::getIsMultiplayerMatch();
}

bool GameApplicationDataReader::isOpponentTurn() {
    return GameApplication::getIsOpponentTurn();
}