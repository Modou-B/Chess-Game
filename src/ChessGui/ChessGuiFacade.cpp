//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiFacade.h"

void ChessGuiFacade::initializeSettingsPage(QWidget *mainWindow) {
    ChessGuiFacade::getFactory()->createChessGuiRenderer()->createSettingsPage(mainWindow);
}
void ChessGuiFacade::initializeChessField(QWidget *mainWindow) {
    ChessGuiFacade::getFactory()->createChessGuiRenderer()->createChessField(mainWindow);
}

void ChessGuiFacade::handlePawnPieceSwitch(
    pair<int, int> chessGuiCellCoordinate,
    string pieceTypeToSwitch
) {
    ChessGuiFacade::getFactory()->createChessGuiCellManager()->handlePawnPieceSwitch(
        chessGuiCellCoordinate,
        pieceTypeToSwitch
    );
}

void ChessGuiFacade::updateTimelineTurnProperties(int currentTurn) {
    ChessGuiFacade::getFactory()->createChessTimelineRenderer()->updateTurnProperties(currentTurn);
}

ChessGuiFactory *ChessGuiFacade::getFactory() {
    return static_cast<ChessGuiFactory*>(this->findFactory(typeid(ChessGuiFactory).name()));
}
