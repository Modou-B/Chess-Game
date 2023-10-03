//
// Created by Julian Sommer on 26.09.23.
//

#include "GameApplicationDataReader.h"
#include "../GameApplication.h"
#include "../Mapper/GameApplicationDataMapper.h"
#include "../Player/ChessPlayerData.h"
#include "../../../Shared/Chess/Transfer/GameState/ChessGameStateTransfer.h"
#include "../../../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"

GameApplicationDataReader::GameApplicationDataReader(GameApplicationDataMapper *gameApplicationDataMapper)
{
    this->gameApplicationDataMapper = gameApplicationDataMapper;
}

ChessGameStateTransfer GameApplicationDataReader::getCurrentGameStateData()
{
    auto chessGameStateTransfer = ChessGameStateTransfer();

    chessGameStateTransfer.setCurrentPlayer(this->getCurrentPlayer())
        ->setCurrentOpponentPlayer(this->getCurrentOpponentPlayer())
        ->setTurnCounter(this->getTurnCounter());

    return chessGameStateTransfer;
}

ChessPiecePositionTransfer GameApplicationDataReader::getKingPiecePositionByPlayer(int player)
{
    return this->gameApplicationDataMapper
            ->mapChessPieceToChessPiecePositionTransfer(
                GameApplication::getChessPlayerDataForPlayer(player)->getKingPiece()
            );
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