//
// Created by Julian Sommer on 04.10.23.
//

#include "ChessTimelineRenderer.h"
#include "../../Model/Timeline/FastForwardTimelineButton.h"
#include "../../Model/Timeline/RewindTimelineButton.h"
#include "../../Model/Timeline/TurnTakeBackButton.h"
#include "../ChessCoordinateConverter.h"
#include "QHBoxLayout"
#include "QListWidget"

QListWidget *ChessTimelineRenderer::timelineList = nullptr;
int ChessTimelineRenderer::selectedTurn = 0;
int ChessTimelineRenderer::currentTurn = 0;

QHBoxLayout *ChessTimelineRenderer::createHBoxChessTimelineLayout()
{
    ChessTimelineRenderer::timelineList = new QListWidget();

    auto hBoxTimelineLayout = new QHBoxLayout();
    hBoxTimelineLayout->addWidget(ChessTimelineRenderer::timelineList);

    return hBoxTimelineLayout;
}

QHBoxLayout *ChessTimelineRenderer::createHBoxTimelineButtonsLayout(
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiCellManager *chessGuiCellManager,
    ChessFacade *chessFacade
) {
    auto hBoxTimelineButtonsLayout = new QHBoxLayout();

    auto *buttonRewind = new RewindTimelineButton(
        this,
        chessTimelineFacade,
        chessGuiCellManager
    );
    buttonRewind->setText("<<");

    auto *buttonPause = new TurnTakeBackButton(
        this,
        chessTimelineFacade,
        chessGuiCellManager,
        chessFacade
    );
    buttonPause->setText(">||");

    auto *buttonSkip = new FastForwardTimelineButton(
        this,
        chessTimelineFacade,
        chessGuiCellManager
    );
    buttonSkip->setText(">>");

    hBoxTimelineButtonsLayout->addWidget(buttonRewind);
    hBoxTimelineButtonsLayout->addWidget(buttonPause);
    hBoxTimelineButtonsLayout->addWidget(buttonSkip);

    return hBoxTimelineButtonsLayout;
}

void ChessTimelineRenderer::addListWidgetItem(
    pair<int, int> currentCellCoordinates,
    string chessPieceType
) {
    auto entryStr = QString::fromStdString(
      ChessCoordinateConverter::GetConvertedChessMatrixValue(currentCellCoordinates) + " -> " +
      chessPieceType);

    auto *rewindListEntry = new QListWidgetItem(entryStr);

    ChessTimelineRenderer::timelineList->insertItem(ChessTimelineRenderer::timelineList->count() + 1, rewindListEntry);
    ChessTimelineRenderer::timelineList->setCurrentRow(ChessTimelineRenderer::timelineList->count() - 1);
}

int ChessTimelineRenderer::fastForwardTurn()
{
    int turn = ChessTimelineRenderer::selectedTurn;

    ChessTimelineRenderer::timelineList->setCurrentRow(turn);

    ChessTimelineRenderer::selectedTurn++;
    if (ChessTimelineRenderer::selectedTurn > ChessTimelineRenderer::currentTurn) {
        ChessTimelineRenderer::selectedTurn = ChessTimelineRenderer::currentTurn;

        return ChessTimelineRenderer::selectedTurn;
    }

    return turn;
}

int ChessTimelineRenderer::rewindTurn()
{
    int turn = ChessTimelineRenderer::selectedTurn;

    ChessTimelineRenderer::timelineList->setCurrentRow(turn-1);

    ChessTimelineRenderer::selectedTurn--;
    if (ChessTimelineRenderer::selectedTurn < 0) {
        ChessTimelineRenderer::selectedTurn = 0;

        return 0;
    }

    return turn;
}

void ChessTimelineRenderer::updateTurnProperties(int turn) {
    ChessTimelineRenderer::selectedTurn = turn;
    ChessTimelineRenderer::currentTurn = turn;
}

int ChessTimelineRenderer::getCurrentTurn() {
    return ChessTimelineRenderer::currentTurn;
}

int ChessTimelineRenderer::getSelectedTurn() {
    return ChessTimelineRenderer::selectedTurn;
}

void ChessTimelineRenderer::removeLastTurn() {
    ChessTimelineRenderer::timelineList->setCurrentRow(ChessTimelineRenderer::timelineList->count() - 1);
    delete ChessTimelineRenderer::timelineList->currentItem();
}