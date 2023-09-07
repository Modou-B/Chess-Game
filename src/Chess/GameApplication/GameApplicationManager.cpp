//
// Created by Julian Sommer on 07.09.23.
//

#include "GameApplicationManager.h"
#include "../Creator/ChessCreator.h"
#include "GameApplication.h"

GameApplicationManager::GameApplicationManager(ChessCreator *chessCreator) {
    this->chessCreator = chessCreator;
}

void GameApplicationManager::initiateChessApplication() {
    ChessField *chessField = this->chessCreator->initiateChessField();

    GameApplication::setChessField(chessField);
}
