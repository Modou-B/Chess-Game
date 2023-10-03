//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiRenderer.h"
#include <QGridLayout>
#include "../Chess/ChessFacade.h"
#include "../Shared/Chess/ChessConstants.h"
#include "../Shared/ChessGui/ChessGuiConstants.h"
#include "../Model/Generator/ChessGuiPieceIconGenerator.h"
#include "../Model/ChessGuiCell.h"
#include "QWidget"
#include <utility>
#include "QImage"
#include "QLCDNumber"
#include "QLabel"
#include "QPainter"
#include "QLabel"
#include "QPushButton"
#include "QLCDNumber"
#include "QTimer"
#include "QTime"
#include "QListWidget"
#include "ChessTimer.h"
#include "QObject"
#include "Settings/ChessStartButton.h"
#include "Settings/ChessSpeedButtons.h"
#include "../Model/ChessSelectionPiece.h"
#include "../Model/ChessGuiCellManager.h"
#include "ChessPieceSelection/ChessPieceSelectionRenderer.h"

class QGridLayout;

QListWidget *ChessGuiRenderer::timelineList = nullptr;

ChessGuiRenderer::ChessGuiRenderer(
    ChessFacade *chessFacade,
    ChessGuiCellManager *chessGuiCellManager,
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
    ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator
) {
    this->chessFacade = chessFacade;
    this->chessGuiCellManager = chessGuiCellManager;
    this->chessPieceSelectionRenderer = chessPieceSelectionRenderer;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
}

void ChessGuiRenderer::createSettingsPage(QWidget *mainWindow) {
    auto hBoxStartMenuBracketLayout = new QHBoxLayout(mainWindow);
    auto vBoxStartAndSettingsButtonsLayout = new QVBoxLayout(mainWindow);
    auto vBoxSpeedButtonsLayout = new QVBoxLayout(mainWindow);

    auto startPushbutton = new ChessStartButton(this, mainWindow);
    startPushbutton->setText("Start");
    auto settingsPushbutton = new QPushButton("Settings");

    auto speedPushbuttonClassic = new ChessSpeedButtons(this, 0);
    speedPushbuttonClassic->setText("Classic");
    auto speedPushbuttonFast = new ChessSpeedButtons(this, 1800);
    speedPushbuttonFast->setText("Fast");
    auto speedPushbuttonBlitz = new ChessSpeedButtons(this, 300);
    speedPushbuttonBlitz->setText("Blitz");
    auto speedPushbuttonBullet = new ChessSpeedButtons(this, 180);
    speedPushbuttonBullet->setText("Bullet");


    vBoxStartAndSettingsButtonsLayout->addWidget(startPushbutton);
    vBoxStartAndSettingsButtonsLayout->addWidget(settingsPushbutton);

    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonClassic);
    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonFast);
    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonBlitz);
    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonBullet);

    hBoxStartMenuBracketLayout->addLayout(vBoxStartAndSettingsButtonsLayout);
    hBoxStartMenuBracketLayout->addLayout(vBoxSpeedButtonsLayout);
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    // -- Grid und stuff
    auto hBoxMainBracketLayout = new QHBoxLayout(mainWindow);
    auto vBoxMainContainer = new QVBoxLayout(mainWindow);
    auto vBoxSideInformationPanel = new QVBoxLayout(mainWindow);

    auto hBoxFullGridAndSideInformationPanelLayout = new QHBoxLayout(mainWindow);
    auto vBoxGridAndLetterContainerLayout = new QVBoxLayout(mainWindow);
    auto vBoxNumberLayout = new QVBoxLayout(mainWindow);

    auto vBoxNumberListLayout = new QVBoxLayout(mainWindow);
    auto hBoxLetterListLayout = new QHBoxLayout(mainWindow);

    auto hBoxTimelineButtonsLayout = new QHBoxLayout(mainWindow);
    auto hBoxCountdownLayoutBlack = new QHBoxLayout(mainWindow);
    auto hBoxCountdownLayoutWhite = new QHBoxLayout(mainWindow);
    auto hBoxTimelineLayout = new QHBoxLayout(mainWindow);

    auto hboxTopPanelLayout = new QHBoxLayout(mainWindow);
    auto hboxBottomPanelLayout = new QHBoxLayout(mainWindow);

    auto player1Label = new QLabel("Player 1");
    auto player1ActiveLabel = new QLabel("*Current players turn");
    auto player2Label = new QLabel("Player 2");
    auto player2ActiveLabel = new QLabel("*Current players turn");

    // ChessGrid
    auto *gridLayout = new QGridLayout();

    // ChessPieceSelectionHBoxes
    this->createChessPieceSelectionHBoxes();
    auto hBoxChessPieceSelectionBottom = this->chessPieceSelectionRenderer->getChessPieceSelectionHBoxForPlayer(1);
    auto hBoxChessPieceSelectionTop = this->chessPieceSelectionRenderer->getChessPieceSelectionHBoxForPlayer(2);


    // Untere Labels
    auto chessFieldSideLetterA = new QLabel("A");
    chessFieldSideLetterA->setMinimumSize(80, 50);
    chessFieldSideLetterA->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterB = new QLabel("B");
    chessFieldSideLetterB->setMinimumSize(80, 80);
    chessFieldSideLetterB->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterC = new QLabel("C");
    chessFieldSideLetterC->setMinimumSize(80, 50);
    chessFieldSideLetterC->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterD = new QLabel("D");
    chessFieldSideLetterD->setMinimumSize(80, 80);
    chessFieldSideLetterD->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterE = new QLabel("E");
    chessFieldSideLetterE->setMinimumSize(80, 50);
    chessFieldSideLetterE->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterF = new QLabel("F");
    chessFieldSideLetterF->setMinimumSize(80, 80);
    chessFieldSideLetterF->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterG = new QLabel("G");
    chessFieldSideLetterG->setMinimumSize(80, 50);
    chessFieldSideLetterG->setAlignment(Qt::AlignCenter);

    auto chessFieldSideLetterH = new QLabel("H");
    chessFieldSideLetterH->setMinimumSize(80, 80);
    chessFieldSideLetterH->setAlignment(Qt::AlignCenter);



    // Linke Labels
    auto chessFieldSideNumber1 = new QLabel("1");
    chessFieldSideNumber1->setMinimumSize(80, 50);
    chessFieldSideNumber1->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber2 = new QLabel("2");
    chessFieldSideNumber2->setMinimumSize(80, 80);
    chessFieldSideNumber2->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber3 = new QLabel("3");
    chessFieldSideNumber3->setMinimumSize(80, 50);
    chessFieldSideNumber3->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber4 = new QLabel("4");
    chessFieldSideNumber4->setMinimumSize(80, 80);
    chessFieldSideNumber4->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber5 = new QLabel("5");
    chessFieldSideNumber5->setMinimumSize(80, 50);
    chessFieldSideNumber5->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber6 = new QLabel("6");
    chessFieldSideNumber6->setMinimumSize(80, 80);
    chessFieldSideNumber6->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber7 = new QLabel("7");
    chessFieldSideNumber7->setMinimumSize(80, 50);
    chessFieldSideNumber7->setAlignment(Qt::AlignCenter);

    auto chessFieldSideNumber8 = new QLabel("8");
    chessFieldSideNumber8->setMinimumSize(80, 80);
    chessFieldSideNumber8->setAlignment(Qt::AlignCenter);

    // Empty Labels
    auto spacerNumberList = new QLabel("");

    auto spacer2 = new QLabel("");

    auto chessFieldSideNumberEmpty3 = new QLabel("");

    auto chessFieldSideNumberEmpty4 = new QLabel("");

    auto chessFieldSideNumberEmpty5 = new QLabel("");

    auto *buttonRewind = new QPushButton("<<");
    auto *buttonPause = new QPushButton(">||");
    auto *buttonSkip = new QPushButton(">>");



    auto *rewindListLocal = new QListWidget(mainWindow);
    ChessGuiRenderer::timelineList = rewindListLocal;

    vBoxNumberListLayout->addWidget(chessFieldSideNumber8);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber7);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber6);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber5);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber4);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber3);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber2);
    vBoxNumberListLayout->addWidget(chessFieldSideNumber1);


    hBoxLetterListLayout->addWidget(chessFieldSideLetterA);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterB);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterC);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterD);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterE);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterF);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterG);
    hBoxLetterListLayout->addWidget(chessFieldSideLetterH);

    vBoxNumberLayout->addLayout(vBoxNumberListLayout);
    vBoxNumberLayout->addWidget(spacerNumberList);

    vBoxGridAndLetterContainerLayout->addLayout(gridLayout);
    vBoxGridAndLetterContainerLayout->addLayout(hBoxLetterListLayout);

    hBoxFullGridAndSideInformationPanelLayout->addLayout(vBoxNumberLayout);
    hBoxFullGridAndSideInformationPanelLayout->addLayout(vBoxGridAndLetterContainerLayout);

    // MainWindow Player1 -> Grid -> Player2
    vBoxMainContainer->addLayout(hboxTopPanelLayout);
    vBoxMainContainer->addLayout(hBoxChessPieceSelectionBottom);
    vBoxMainContainer->addLayout(hBoxFullGridAndSideInformationPanelLayout);
    vBoxMainContainer->addLayout(hBoxChessPieceSelectionTop);
    vBoxMainContainer->addLayout(hboxBottomPanelLayout);

    // Befüllen von Labels
    hboxTopPanelLayout->addWidget(chessFieldSideNumberEmpty3);
    hboxTopPanelLayout->addWidget(player2Label);
    hboxTopPanelLayout->addWidget(player2ActiveLabel );

    hboxBottomPanelLayout->addWidget(chessFieldSideNumberEmpty4);
    hboxBottomPanelLayout->addWidget(player1Label);
    hboxBottomPanelLayout->addWidget(player1ActiveLabel);

    // Playbuttons
    hBoxTimelineButtonsLayout->addWidget(buttonRewind);
    hBoxTimelineButtonsLayout->addWidget(buttonPause);
    hBoxTimelineButtonsLayout->addWidget(buttonSkip);

    // Countdown
    if (this->speedModeTimerValue > 0) {
        auto *digitalClockBlack = new ChessTimer(2, this->speedModeTimerValue);
        auto *digitalClockWhite = new ChessTimer(1,this->speedModeTimerValue);

        hBoxCountdownLayoutBlack->addWidget(digitalClockBlack);
        hBoxCountdownLayoutWhite->addWidget(digitalClockWhite);
    }


    // Rewindlist
    hBoxTimelineLayout->addWidget(timelineList);

    vBoxSideInformationPanel->addLayout(hBoxCountdownLayoutBlack);
    vBoxSideInformationPanel->addLayout(hBoxTimelineLayout);
    vBoxSideInformationPanel->addLayout(hBoxCountdownLayoutWhite);
    vBoxSideInformationPanel->addLayout(hBoxTimelineButtonsLayout);




    // In den horizontalen Rahmen das Grid und die Playerlabel einsetzen
    hBoxMainBracketLayout->addLayout(vBoxNumberListLayout); //Test
    hBoxMainBracketLayout->addLayout(vBoxMainContainer);
    hBoxMainBracketLayout->addLayout(vBoxSideInformationPanel);

    // Das rechte Menü samt Countdown und playerbutton einsetzen
    // Obsolete -> hBoxMainBracketLayout->addLayout(hBoxCountdownLayoutBlack);
    // Obsolete -> hBoxMainBracketLayout->addLayout(hBoxCountdownLayoutWhite);

    this->fillFieldWithEmptyCells(gridLayout);
    this->addPawnsToCells(gridLayout);
    this->addQueensToCells(gridLayout);
    this->addKingsToCells(gridLayout);
    this->addBishopsToCells(gridLayout);
    this->addKnightsToCells(gridLayout);
    this->addRooksToCells(gridLayout);

    this->chessGuiCellManager->setChessGuiCellGrid(gridLayout);
}

void ChessGuiRenderer::fillFieldWithEmptyCells(QGridLayout *layout) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::pair<int, int> coordinates = std::make_pair(i, j);
            ChessGuiCell *chessGuiCell = new ChessGuiCell(
                    layout,
                    this->chessFacade,
                    this->chessPieceSelectionRenderer,
                    coordinates,
                    this->chessGuiPieceIconGenerator
            );

            if (j % 2 - counter == 0) {
                chessGuiCell->setCellColor(ChessGuiConstants::CELL_YELLOW_COLOR);
            } else {
                chessGuiCell->setCellColor(ChessGuiConstants::CELL_GREEN_COLOR);
            }

            chessGuiCell->setBaseCellSize();

            layout->addWidget(chessGuiCell, i, j);
        }

        counter++;
        if (counter > 1) {
            counter = 0;
        }
    }

    layout->setSpacing(0);
}
void ChessGuiRenderer::addChessPieceToCells(QGridLayout *layout, std::string iconFileName, std::string pieceType, int row, int column) {
    ChessGuiCell *chessGuiCell = static_cast<ChessGuiCell*>(layout->itemAtPosition(row, column)->widget());

    auto icon = this->chessGuiPieceIconGenerator->generateIconFromFile(iconFileName);

    chessGuiCell->setChessPieceIcon(ChessGuiConstants::STATE_REAL_CHESS_PIECE_ICON, icon);
    chessGuiCell->setIconSize(QSize(50, 50));
    chessGuiCell->setChessPieceType(pieceType);
}


void ChessGuiRenderer::addPawnsToCells(QGridLayout *layout) {
    for (int i = 0; i < 8; i++) {
        this->addChessPieceToCells(layout, ChessConstants::BLACK_PAWN_PIECE_FILENAME, ChessConstants::PAWN_PIECE_TYPE, 1, i);
        this->addChessPieceToCells(layout, ChessConstants::WHITE_PAWN_PIECE_FILENAME, ChessConstants::PAWN_PIECE_TYPE, 6, i);
    }
}

void ChessGuiRenderer::addQueensToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_QUEEN_PIECE_FILENAME, ChessConstants::QUEEN_PIECE_TYPE, 0, 3);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_QUEEN_PIECE_FILENAME, ChessConstants::QUEEN_PIECE_TYPE, 7, 3);
}

void ChessGuiRenderer::addKingsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_KING_PIECE_FILENAME, ChessConstants::KING_PIECE_TYPE, 0, 4);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_KING_PIECE_FILENAME, ChessConstants::KING_PIECE_TYPE, 7, 4);
}

void ChessGuiRenderer::addBishopsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 0, 2);
    this->addChessPieceToCells(layout, ChessConstants::BLACK_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 0, 5);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 7, 2);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_BISHOP_PIECE_FILENAME, ChessConstants::BISHOP_PIECE_TYPE, 7, 5);
}

void ChessGuiRenderer::addKnightsToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 0, 1);
    this->addChessPieceToCells(layout, ChessConstants::BLACK_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 0, 6);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 7, 1);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_KNIGHT_PIECE_FILENAME, ChessConstants::KNIGHT_PIECE_TYPE, 7, 6);
}

void ChessGuiRenderer::addRooksToCells(QGridLayout *layout) {
    this->addChessPieceToCells(layout, ChessConstants::BLACK_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 0, 0);
    this->addChessPieceToCells(layout, ChessConstants::BLACK_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 0, 7);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 7, 0);
    this->addChessPieceToCells(layout, ChessConstants::WHITE_ROOK_PIECE_FILENAME, ChessConstants::ROOK_PIECE_TYPE, 7, 7);
}

void ChessGuiRenderer::onSkipButtonPress() {

}

void ChessGuiRenderer::onPauseButtonPress() {

}

void ChessGuiRenderer::onRewindButtonPress() {
    qDebug() << "Test";
}

void ChessGuiRenderer::onPressStartButton(QWidget *mainWindow) {
    while ( auto* w = mainWindow->findChild<QWidget*>() ) {
        delete w;
    }

    auto *mainGridWindow = new QWidget;
    this->createChessField(mainGridWindow);

    mainGridWindow->show();
    mainWindow->close();
}

void ChessGuiRenderer::onPressSpeedButton(int speedModeTimerValue) {
    this->speedModeTimerValue = speedModeTimerValue;
}

void ChessGuiRenderer::createChessPieceSelectionHBoxes() {
    string chessPieceTypes[4] = {
      ChessConstants::ROOK_PIECE_TYPE,
      ChessConstants::KNIGHT_PIECE_TYPE,
      ChessConstants::BISHOP_PIECE_TYPE,
      ChessConstants::QUEEN_PIECE_TYPE
    };

    this->chessPieceSelectionRenderer->createChessPieceSelectionHBoxes(
        this->chessFacade,
        chessPieceTypes
    );
}