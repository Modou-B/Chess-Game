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
#include "iostream"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "../Timeline/rewindDesicion/acceptRewind.h"
#include "../Timeline/rewindDesicion/declineRewind.h"


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
    auto *waitingWindow = new QWidget;
    waitForOpponentResponseScreen(waitingWindow);
    rewindDesicionScreen(waitingWindow);
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

void TurnTakeBackButton::waitForOpponentResponseScreen(QWidget *waitingWindow) {
    waitingWindow->setFixedSize(300, 200);

    auto hBoxContainerLayout = new QHBoxLayout(waitingWindow);
    auto vBoxContainerLayout = new QVBoxLayout(waitingWindow);
    auto waitingLabel = new QLabel("Waiting for player desicion..." );



    vBoxContainerLayout->addWidget(waitingLabel);
    hBoxContainerLayout->addLayout(vBoxContainerLayout);

    waitingWindow->show();
}

void TurnTakeBackButton::rewindDesicionScreen(QWidget *waitingWindow) {
    auto *acceptWindow = new QWidget;
    acceptWindow->setFixedSize(300, 200);

    auto hBoxContainerLayout = new QHBoxLayout(acceptWindow);
    auto vBoxContainerLayout = new QVBoxLayout(acceptWindow);
    auto rewindLabel = new QLabel("Do you want to rewind the last turn" );

    auto accept = new acceptRewind(acceptWindow, waitingWindow, false, chessTimelineRenderer, chessTimelineFacade, chessGuiCellManager, this, chessFacade);
    accept->setText("Accept");

    auto decline = new declineRewind();
    //backToMenu->setText("Menu");


    vBoxContainerLayout->addWidget(rewindLabel);

    vBoxContainerLayout->addWidget(accept);
    hBoxContainerLayout->addLayout(vBoxContainerLayout);

    acceptWindow->show();
}