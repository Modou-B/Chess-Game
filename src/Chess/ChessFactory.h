//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_CHESSFACTORY_H
#define CHESSAPPLICATION_CHESSFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Creator/ChessCreator.h"
#include "ChessPiece/Movement/ChessPieceMovementManager.h"
#include "ChessPiece/Generator/ChessPieceMovementGenerator.h"
#include "GameApplication/GameApplicationManager.h"
#include "Checkmate/CheckmateManager.h"
#include "Checkmate/Status/InCheckStatusChecker.h"
#include "Checkmate/Status/InStalemateStatusChecker.h"
#include "Checkmate/Status/BareKingDrawStatusChecker.h"
#include "ChessPiece/Movement/KingPiece/KingPieceMovementChecker.h"

class ChessFactory: public AbstractFactory {
public:
    ChessCreator *createChessCreator();
    ChessPieceMovementManager *createChessPieceMovementManager();
    ChessPieceMovementGenerator *createChessPieceMovementGenerator();

    CheckmateManager *createCheckmateManager();
    InCheckStatusChecker *createInCheckStatusChecker();
    InStalemateStatusChecker *createInStalemateStatusChecker();
    BareKingDrawStatusChecker *createBareKingDrawStatusChecker();
    KingPieceMovementChecker *createKingPieceMovementChecker();

    GameApplicationManager *createGameApplicationManager();
};


#endif //CHESSAPPLICATION_CHESSFACTORY_H
