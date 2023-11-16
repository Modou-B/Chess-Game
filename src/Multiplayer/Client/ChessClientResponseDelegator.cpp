//
// Created by Julian Sommer on 09.11.23.
//

#include "ChessClientResponseDelegator.h"
#include <QJsonObject>
#include "../../Chess/ChessFacade.h"
#include "../../ChessGui/ChessGuiFacade.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"
#include "iostream"

ChessClientResponseDelegator::ChessClientResponseDelegator(
    ChessFacade *chessFacade,
    ChessGuiFacade *chessGuiFacade
) {
    this->chessFacade = chessFacade;
    this->chessGuiFacade = chessGuiFacade;
}

void ChessClientResponseDelegator::delegateChessClientResponse(
    string responseType,
    QJsonObject jsonData
) {
    if (responseType == "startChessMatch") {
        this->startMultiplayerGame(jsonData);
    }

    if (responseType == "endCurrentTurn") {
        this->handleEndTurnData(jsonData);
    }
}

void ChessClientResponseDelegator::handleEndTurnData(QJsonObject jsonData) {
    auto chessMovementResponseTransfer = ChessMovementResponseTransfer();
    chessMovementResponseTransfer.fromQJsonObject(jsonData["chessMovementResponseData"].toObject());

    auto chessPiecePositionTransfer = ChessPiecePositionTransfer();
    chessPiecePositionTransfer.fromQJsonObject(jsonData["chessPiecePositionData"].toObject());

    this->chessFacade->endCurrentTurn(
        chessMovementResponseTransfer,
        chessPiecePositionTransfer
    );
}

void ChessClientResponseDelegator::startMultiplayerGame(QJsonObject jsonData)
{
    this->chessFacade->initiateMultiplayerChessGame(jsonData);
}