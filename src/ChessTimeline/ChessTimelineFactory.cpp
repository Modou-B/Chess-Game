//
// Created by Julian Sommer on 26.09.23.
//

#include "ChessTimelineFactory.h"

ChessTurnLogWriter *ChessTimelineFactory::createChessTurnLogWriter()
{
    return new ChessTurnLogWriter(
      this->createChessTimelineMapper()
    );
}

ChessTurnLogReader *ChessTimelineFactory::createChessTurnLogReader()
{
    return new ChessTurnLogReader(
      this->createChessTimelineMapper()
    );
}

ChessTimelineMapper *ChessTimelineFactory::createChessTimelineMapper()
{
    return new ChessTimelineMapper();
}