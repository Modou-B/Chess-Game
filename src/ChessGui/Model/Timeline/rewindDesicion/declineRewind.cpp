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

declineRewind::declineRewind(QWidget *acceptWindow, QWidget *waitingWindow)
 {
    this->acceptWindow = acceptWindow;
    this->waitingWindow = waitingWindow;

    connect(this, &QPushButton::released, this, &declineRewind::decline);
}

void declineRewind::decline() {
    this->acceptWindow->close();
    this->waitingWindow->close();
}