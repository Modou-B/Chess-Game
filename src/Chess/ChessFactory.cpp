//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFactory.h"

GameApplicationManager *ChessFactory::createGameApplicationManager() {
    return new GameApplicationManager(
      this->createChessCreator(),
      this->createChessPieceMovementManager(),
      this->createCheckmateManager()
      );
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

CheckmateManager *ChessFactory::createCheckmateManager() {
    return new CheckmateManager(
      this->createInCheckStatusChecker(),
      this->createInStalemateStatusChecker(),
      this->createBareKingDrawStatusChecker()
      );
}

InCheckStatusChecker *ChessFactory::createInCheckStatusChecker() {
    return new InCheckStatusChecker(this->createKingPieceMovementChecker());
}

InStalemateStatusChecker *ChessFactory::createInStalemateStatusChecker() {
    return new InStalemateStatusChecker();
}

BareKingDrawStatusChecker *ChessFactory::createBareKingDrawStatusChecker() {
    return new BareKingDrawStatusChecker();
}

KingPieceMovementChecker *ChessFactory::createKingPieceMovementChecker() {
    return new KingPieceMovementChecker();
}
