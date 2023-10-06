//
// Created by Julian Sommer on 05.10.23.
//

#include "ChessPieceCreator.h"
#include "../PawnPiece.h"
#include "../KnightPiece.h"
#include "../KingPiece.h"
#include "../RookPiece.h"
#include "../QueenPiece.h"
#include "../BishopPiece.h"
#include "../../../Shared/Chess/ChessConstants.h"
#include "../../Movement/Mapper/ChessPieceMovementMapper.h"
#include "../../Movement/KingPiece/KingPieceMovementChecker.h"
#include "../../../Shared/Chess/Transfer/ChessPiece/ChessPieceStateTransfer.h"

ChessPieceCreator::ChessPieceCreator(
    ChessPieceMovementMapper *chessPieceMovementMapper,
    KingPieceMovementChecker *kingPieceMovementChecker
) {
    this->chessPieceMovementMapper = chessPieceMovementMapper;
    this->kingPieceMovementChecker = kingPieceMovementChecker;
}

BaseChessPiece *ChessPieceCreator::createChessPiece(
    ChessPieceStateTransfer *chessPieceStateTransfer
) {
    auto type = chessPieceStateTransfer->getChessPieceType();
    auto player = chessPieceStateTransfer->getPlayerOfChessPiece();

    BaseChessPiece *chessPiece = nullptr;

    if (type == ChessConstants::PAWN_PIECE_TYPE) {
        auto *pawnPiece = new PawnPiece(
          player,
          this->chessPieceMovementMapper,
          this->kingPieceMovementChecker
        );

        pawnPiece->setUsedDoubleMove(chessPieceStateTransfer->getUsedDoubleMove());
        pawnPiece->setCurrentCoordinates(chessPieceStateTransfer->getStartCoordinate());

        return pawnPiece;
    }
    if (type == ChessConstants::KNIGHT_PIECE_TYPE) {
        chessPiece = new KnightPiece(
          player,
          this->chessPieceMovementMapper,
          this->kingPieceMovementChecker
        );
    }
    if (type == ChessConstants::KING_PIECE_TYPE) {
        chessPiece = new KingPiece(
          player,
          this->chessPieceMovementMapper,
          this->kingPieceMovementChecker
        );
    }
    if (type == ChessConstants::ROOK_PIECE_TYPE) {
        chessPiece = new RookPiece(
          player,
          this->chessPieceMovementMapper,
          this->kingPieceMovementChecker
        );
    }
    if (type == ChessConstants::QUEEN_PIECE_TYPE) {
        chessPiece = new QueenPiece(
          player,
          this->chessPieceMovementMapper,
          this->kingPieceMovementChecker
        );
    }
    if (type == ChessConstants::BISHOP_PIECE_TYPE) {
        chessPiece = new BishopPiece(
          player,
          this->chessPieceMovementMapper,
          this->kingPieceMovementChecker
        );
    }

    chessPiece->setCurrentCoordinates(chessPieceStateTransfer->getStartCoordinate());
    chessPiece->setMoveCounter(chessPieceStateTransfer->getMoveCounter());

    return chessPiece;
}

