//
// Created by Modou on 21.09.23.
//

#include "ChessCoordinateConverter.h"
#include "QString"


std::string ChessCoordinateConverter::GetConvertedChessMatrixValue(std::pair<int, int> coordinates) {
    std::string letter, number;
    std::string chessMatrixAlphabet[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    std::string chessMatrixNumber[8] = {"8", "7", "6", "5", "4", "3", "2", "1"};

    letter = chessMatrixAlphabet[coordinates.second];
    number = chessMatrixNumber[coordinates.first];

    return letter + number;
}