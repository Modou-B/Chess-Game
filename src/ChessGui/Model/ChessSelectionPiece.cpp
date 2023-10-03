//
// Created by Modou on 28.09.23.
//

#include "ChessSelectionPiece.h"
#include "../../Chess/ChessFacade.h"
#include "../../Shared/Chess/ChessMovementConstants.h"

ChessSelectionPiece::ChessSelectionPiece(ChessFacade *chessFacade, std::string pieceType) {
    this->chessFacade = chessFacade;
    this->pieceType = pieceType;

    connect(this, &QPushButton::released, this, &ChessSelectionPiece::setSelectionPiece);
}

void ChessSelectionPiece::setSelectionPiece() {
    this->chessFacade->handlePawnPieceSwitch(this->pieceType);

    this->chessFacade->updateCurrentGameState(ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH);
}