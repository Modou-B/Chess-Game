//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_CHESSFACTORY_H
#define CHESSAPPLICATION_CHESSFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Checkmate/CheckmateManager.h"
#include "Checkmate/Status/BareKingDrawStatusChecker.h"
#include "Checkmate/Status/InCheckStatusChecker.h"
#include "Checkmate/Status/InStalemateStatusChecker.h"
#include "Movement/Mapper/ChessPieceMovementMapper.h"
#include "Movement/ChessPieceMovementManager.h"
#include "Movement/Writer/ChessPieceMovementWriter.h"
#include "Movement/Reader/ChessPieceMovementReader.h"
#include "Movement/KingPiece/KingPieceMovementChecker.h"
#include "Creator/ChessCreator.h"
#include "GameApplication/GameApplicationManager.h"
#include "GameApplication/Mapper/GameApplicationDataMapper.h"
#include "GameApplication/Writer/GameApplicationDataWriter.h"
#include "GameApplication/Reader/GameApplicationDataReader.h"
#include "../ChessTimeline/ChessTimelineFacade.h"
#include "../Multiplayer/MultiplayerFacade.h"
#include "ChessPiece/Creator/ChessPieceCreator.h"

class ChessGuiFacade;
class MultiplayerFacade;

class ChessFactory: public AbstractFactory {
public:
    ChessCreator *createChessCreator();

    ChessPieceMovementManager *createChessPieceMovementManager();
    ChessPieceMovementMapper *createChessPieceMovementMapper();
    ChessPieceMovementWriter *createChessPieceMovementWriter();
    ChessPieceMovementReader *createChessPieceMovementReader();

    CheckmateManager *createCheckmateManager();
    InCheckStatusChecker *createInCheckStatusChecker();
    InStalemateStatusChecker *createInStalemateStatusChecker();
    BareKingDrawStatusChecker *createBareKingDrawStatusChecker();
    KingPieceMovementChecker *createKingPieceMovementChecker();

    GameApplicationManager *createGameApplicationManager();
    GameApplicationDataWriter *createGameApplicationDataWriter();
    GameApplicationDataReader *createGameApplicationDataReader();
    GameApplicationDataMapper *createGameApplicationDataMapper();

    ChessPieceCreator *createChessPieceCreator();

    ChessTimelineFacade *getChessTimelineFacade();
    ChessGuiFacade *getChessGuiFacade();
    MultiplayerFacade *getMultiplayerFacade();
};


#endif //CHESSAPPLICATION_CHESSFACTORY_H
