//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFactory.h"

ChessCreator *ChessFactory::createChessCreator() {
    return new ChessCreator();
}

ChessPieceMovementManager *ChessFactory::createChessPieceMovementManager() {
    return new ChessPieceMovementManager(
      this->createChessPieceMovementMapper(),
      this->createChessPieceMovementWriter(),
      this->createChessPieceMovementReader()
    );
}

ChessPieceMovementMapper *ChessFactory::createChessPieceMovementMapper() {
    return new ChessPieceMovementMapper();
}

ChessPieceMovementWriter *ChessFactory::createChessPieceMovementWriter() {
    return new ChessPieceMovementWriter();
}

ChessPieceMovementReader *ChessFactory::createChessPieceMovementReader() {
    return new ChessPieceMovementReader();
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
    return new KingPieceMovementChecker(this->createGameApplicationDataReader());
}

GameApplicationManager *ChessFactory::createGameApplicationManager() {
    return new GameApplicationManager(
      this->createChessCreator(),
      this->createChessPieceMovementManager(),
      this->createCheckmateManager(),
      this->createGameApplicationDataReader(),
      this->getChessTimelineFacade()
    );
}

GameApplicationDataReader *ChessFactory::createGameApplicationDataReader() {
    return new GameApplicationDataReader(this->createGameApplicationDataMapper());
}

GameApplicationDataMapper *ChessFactory::createGameApplicationDataMapper() {
    return new GameApplicationDataMapper;
}

ChessTimelineFacade *ChessFactory::getChessTimelineFacade() {
    return static_cast<ChessTimelineFacade*>(this->findFacade(typeid(ChessTimelineFacade).name()));
}