//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFactory.h"

GameApplicationManager *ChessFactory::createGameApplicationManager() {
    return new GameApplicationManager(this->createChessCreator(), this->createChessPieceMovementManager());
}

ChessPieceMovementGenerator *ChessFactory::createChessPieceMovementGenerator() {
    return new ChessPieceMovementGenerator();
}

ChessCreator *ChessFactory::createChessCreator() {
    return new ChessCreator();
}

ChessPieceMovementManager *ChessFactory::createChessPieceMovementManager() {
    return new ChessPieceMovementManager(this->createChessPieceMovementGenerator());
}
