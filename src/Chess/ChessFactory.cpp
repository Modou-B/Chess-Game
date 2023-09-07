//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFactory.h"

ChessCreator *ChessFactory::createChessCreator() {
    return new ChessCreator();
}

GameApplicationManager *ChessFactory::createGameApplicationManager() {
    return new GameApplicationManager(this->createChessCreator());
}
