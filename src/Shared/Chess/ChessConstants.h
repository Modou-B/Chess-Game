//
// Created by Julian Sommer on 01.09.23.
//

#ifndef CHESSAPPLICATION_CHESSCONSTANTS_H
#define CHESSAPPLICATION_CHESSCONSTANTS_H

#include <string>

namespace ChessConstants
{
    const std::string KING_PIECE_TYPE = "king";
    const std::string QUEEN_PIECE_TYPE = "queen";
    const std::string BISHOP_PIECE_TYPE = "bishop";
    const std::string KNIGHT_PIECE_TYPE = "knight";
    const std::string ROOK_PIECE_TYPE = "rook";
    const std::string PAWN_PIECE_TYPE = "pawn";
    const std::string EMPTY_PIECE_TYPE = "empty";

    const std::string WHITE_KING_PIECE_FILENAME = "king-white";
    const std::string BLACK_KING_PIECE_FILENAME = "king-black";

    const std::string WHITE_QUEEN_PIECE_FILENAME = "queen-white";
    const std::string BLACK_QUEEN_PIECE_FILENAME = "queen-black";

    const std::string WHITE_BISHOP_PIECE_FILENAME = "bishop-white";
    const std::string BLACK_BISHOP_PIECE_FILENAME = "bishop-black";

    const std::string WHITE_KNIGHT_PIECE_FILENAME = "knight-white";
    const std::string BLACK_KNIGHT_PIECE_FILENAME = "knight-black";

    const std::string WHITE_ROOK_PIECE_FILENAME = "rook-white";
    const std::string BLACK_ROOK_PIECE_FILENAME = "rook-black";

    const std::string WHITE_PAWN_PIECE_FILENAME = "pawn-white";
    const std::string BLACK_PAWN_PIECE_FILENAME = "pawn-black";

    const std::string STATE_SWITCHED_PIECE = "STATE_SWITCHED_PIECE";
    const std::string STATE_MOVED_PIECE = "STATE_MOVED_PIECE";
    const std::string STATE_MOVED_PIECE_PAWN_SWITCH = "STATE_MOVED_PIECE_PAWN_SWITCH";

}


#endif //CHESSAPPLICATION_CHESSCONSTANTS_H
