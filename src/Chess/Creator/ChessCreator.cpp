//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCreator.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include "../Shared/Chess/Transfer/ChessCellTransfer.h"
#include "../Shared/Chess/Transfer/ChessPieceTransfer.h"
#include <utility>
#include "../Shared/Chess/ChessConstants.h"
#include "../ChessPiece/PawnPiece.h"

BaseChessPiece *ChessCreator::createChessPiece(ChessPieceTransfer* chessPieceTransfer) {
    std::string type = chessPieceTransfer->getType();


    if (type == ChessConstants::PAWN_PIECE_TYPE) {

        return new PawnPiece(chessPieceTransfer->getPlayer());
    }

    return nullptr;
}

ChessCell *ChessCreator::createChessCell(ChessCellTransfer* chessCellTransfer) {
    std::pair<int, int> coordinates = std::make_pair(
            chessCellTransfer->getXPosition(),
            chessCellTransfer->getYPosition()
            );

    return new ChessCell(
            chessCellTransfer->getChessField(),
            chessCellTransfer->getChessPiece(),
            coordinates);
}

ChessField *ChessCreator::createChessField() {
    return new ChessField();
}

