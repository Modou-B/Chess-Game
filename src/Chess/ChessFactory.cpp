//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFactory.h"
#include "../ChessGui/ChessGuiFacade.h"

ChessCreator *ChessFactory::createChessCreator() {
    return new ChessCreator();
}

ChessPieceMovementManager *ChessFactory::createChessPieceMovementManager() {
    return new ChessPieceMovementManager(
      this->createChessPieceMovementMapper(),
      this->createChessPieceMovementWriter(),
      this->createChessPieceMovementReader(),
      this->createChessPieceCreator(),
      this->createGameApplicationDataWriter()
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
      this->createGameApplicationDataWriter(),
      this->createGameApplicationDataReader(),
      this->getChessTimelineFacade(),
      this->getChessGuiFacade(),
      this->getMultiplayerFacade()
    );
}

GameApplicationDataWriter *ChessFactory::createGameApplicationDataWriter() {
    return new GameApplicationDataWriter(
        this->createGameApplicationDataMapper()
    );
}

GameApplicationDataReader *ChessFactory::createGameApplicationDataReader() {
    return new GameApplicationDataReader(this->createGameApplicationDataMapper());
}

GameApplicationDataMapper *ChessFactory::createGameApplicationDataMapper() {
    return new GameApplicationDataMapper;
}

ChessPieceCreator *ChessFactory::createChessPieceCreator() {
    return new ChessPieceCreator(
      this->createChessPieceMovementMapper(),
      this->createKingPieceMovementChecker()
    );
}

ChessTimelineFacade *ChessFactory::getChessTimelineFacade() {
    return static_cast<ChessTimelineFacade*>(this->findFacade(typeid(ChessTimelineFacade).name()));
}

ChessGuiFacade *ChessFactory::getChessGuiFacade() {
    return static_cast<ChessGuiFacade*>(this->findFacade(typeid(ChessGuiFacade).name()));
}

MultiplayerFacade *ChessFactory::getMultiplayerFacade() {
    return static_cast<MultiplayerFacade*>(this->findFacade(typeid(MultiplayerFacade).name()));
}