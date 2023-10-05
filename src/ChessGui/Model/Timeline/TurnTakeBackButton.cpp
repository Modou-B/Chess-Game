//
// Created by Modou on 03.10.23.
//

#include "TurnTakeBackButton.h"
#include "../../../ChessTimeline/ChessTimelineFacade.h"
#include "../../../Chess/ChessFacade.h"
#include "Renderer/Timeline/ChessTimelineRenderer.h"
#include "../ChessGuiCellManager.h"
#include "../../../Shared/ChessTimeline/ChessTimelineConstants.h"
#include "../../../Shared/ChessTimeline/ChessTurnLogTransfer.h"

TurnTakeBackButton::TurnTakeBackButton(
    ChessTimelineRenderer *chessTimelineRenderer,
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiCellManager *chessGuiCellManager,
    ChessFacade *chessFacade
) {
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessGuiCellManager = chessGuiCellManager;
    this->chessFacade = chessFacade;

    connect(this, &QPushButton::released, this, &TurnTakeBackButton::takeBackTurn);
}

void TurnTakeBackButton::takeBackTurn()
{
    auto currentTurn = this->chessTimelineRenderer->getCurrentTurn();

    auto *lastChessTurnLogTransfer = this->chessTimelineFacade->findChessTurnLogForTurn(currentTurn);

    if (lastChessTurnLogTransfer->getChessPieceInformationTransfers().empty()) {
        return;
    }

    this->updateChessGridGui(lastChessTurnLogTransfer, currentTurn);

    this->chessTimelineRenderer->removeLastTurn();

    this->chessFacade->rewindCurrentTurn(lastChessTurnLogTransfer);
}

void TurnTakeBackButton::updateChessGridGui(
    ChessTurnLogTransfer *lastChessTurnLogTransfer,
    int currentTurn
) {
    int selectedTurn = this->chessTimelineRenderer->getSelectedTurn();

    if (selectedTurn < currentTurn) {
        auto chessTurnLogTransfers = this->chessTimelineFacade->findChessTurnLogsForTurnRange(selectedTurn, currentTurn);

        this->chessGuiCellManager->forwardChessGridToLatestTurn(chessTurnLogTransfers);

        return;
    }

    this->chessGuiCellManager->updateChessGrid(
        lastChessTurnLogTransfer,
        ChessTimelineConstants::MODE_REWIND
    );
}