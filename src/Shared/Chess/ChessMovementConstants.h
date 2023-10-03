//
// Created by Julian Sommer on 16.09.23.
//

#ifndef CHESSAPPLICATION_CHESSMOVEMENTCONSTANTS_H
#define CHESSAPPLICATION_CHESSMOVEMENTCONSTANTS_H

#include <string>

namespace ChessMovementConstants
{
    /**
     * Defines the move type for the possible move (normal, en passant or castling)
     */
    const std::string MOVE_TYPE_EN_PASSANT = "MOVE_TYPE_EN_PASSANT";
    const std::string MOVE_TYPE_CASTLING = "MOVE_TYPE_CASTLING";
    const std::string MOVE_TYPE_NORMAL = "MOVE_TYPE_NORMAL";
    const std::string MOVE_TYPE_PAWN_DOUBLE_MOVE = "MOVE_TYPE_PAWN_DOUBLE_MOVE";

    /**
     * Defines the action to use for the data inside the ChessPieceMovementTransfer
     * -> delete: Deletes the chessPiece on the oldCoordinates chess cell
     * -> move: Deletes the chessPiece on the oldCoordinates chess cell and moves it to the newCoordinates chess cell
     */
    const std::string ACTION_DELETE = "ACTION_DELETE";
    const std::string ACTION_MOVE = "ACTION_MOVE";

    const std::string MOVEMENT_STATE_MOVED = "MOVEMENT_STATE_MOVED";
    const std::string MOVEMENT_STATE_NOT_MOVED = "MOVEMENT_STATE_NOT_MOVED";
    const std::string MOVEMENT_STATE_SWITCHED_TO_OWN_PIECE = "MOVEMENT_STATE_SWITCHED_TO_OWN_PIECE";
    const std::string MOVEMENT_STATE_PAWN_SWITCH_SELECTION_START = "MOVEMENT_STATE_PAWN_SWITCH_SELECTION_START";
    const std::string MOVEMENT_STATE_PAWN_SWITCH_SELECTION = "MOVEMENT_STATE_PAWN_SWITCH_SELECTION";
    const std::string MOVEMENT_STATE_PAWN_SWITCH = "MOVEMENT_STATE_PAWN_SWITCH";

    const std::string CHESS_PIECE_STATE_MOVED = "CHESS_PIECE_STATE_MOVED";
    const std::string CHESS_PIECE_STATE_DELETED_EN_PASSANT = "CHESS_PIECE_STATE_DELETED_EN_PASSANT";
    const std::string CHESS_PIECE_STATE_DELETED = "CHESS_PIECE_STATE_DELETED";
}

#endif //CHESSAPPLICATION_CHESSMOVEMENTCONSTANTS_H

