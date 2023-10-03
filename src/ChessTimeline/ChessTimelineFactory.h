//
// Created by Julian Sommer on 26.09.23.
//

#ifndef CHESSAPPLICATION_CHESSTIMELINEFACTORY_H
#define CHESSAPPLICATION_CHESSTIMELINEFACTORY_H

#include "../Application/Factory/AbstractFactory.h"
#include "Writer/ChessTurnLogWriter.h"
#include "Reader/ChessTurnLogReader.h"
#include "Mapper/ChessTimelineMapper.h"

class ChessTimelineFactory: public AbstractFactory {
public:
    ChessTurnLogWriter *createChessTurnLogWriter();
    ChessTurnLogReader *createChessTurnLogReader();
    ChessTimelineMapper *createChessTimelineMapper();
};

#endif // CHESSAPPLICATION_CHESSTIMELINEFACTORY_H
