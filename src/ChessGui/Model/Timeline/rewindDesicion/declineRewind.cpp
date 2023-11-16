//
// Created by mberlemann on 16.11.2023.
//

#include "declineRewind.h"
#include "../../../Renderer/Timeline/ChessTimelineRenderer.h"
#include "../../../../ChessTimeline/ChessTimelineFacade.h"
#include "../../ChessGuiCellManager.h"
#include "../../../../Shared/ChessTimeline/ChessTimelineConstants.h"
#include "../TurnTakeBackButton.h"
#include "../../../../Chess/ChessFacade.h"
#include "../../../../Shared/ChessTimeline/ChessTurnLogTransfer.h"

declineRewind::declineRewind(QWidget *checkmateWindow,QWidget *waitingWindow,bool isCheckmate, ChessTimelineRenderer *chessTimelineRenderer, ChessTimelineFacade *chessTimelineFacade, ChessGuiCellManager *chessGuiCellManager, TurnTakeBackButton *turnTakeBackButton, ChessFacade *chessFacade) {
    this->checkmateWindow = checkmateWindow;
    this->waitingWindow = waitingWindow;
    this->isCheckmate = isCheckmate;
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->chessGuiCellManager = chessGuiCellManager;
    this->turnTakeBackButton = turnTakeBackButton;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessFacade = chessFacade;

    connect(this, &QPushButton::released, this, &declineRewind::decline);
}

void declineRewind::decline() {

    auto currentTurn = this->chessTimelineRenderer->getCurrentTurn();

    auto *lastChessTurnLogTransfer = this->chessTimelineFacade->findChessTurnLogForTurn(currentTurn);
    if (lastChessTurnLogTransfer->getChessPieceInformationTransfers().empty()) {
        return;
    }

    this->turnTakeBackButton->updateChessGridGui(lastChessTurnLogTransfer, currentTurn);

    this->chessTimelineRenderer->removeLastTurn();

    this->chessFacade->rewindCurrentTurn(lastChessTurnLogTransfer);

    this->checkmateWindow->close();
    this->waitingWindow->close();
}