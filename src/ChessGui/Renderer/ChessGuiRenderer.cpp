//
// Created by Julian Sommer on 01.09.23.
//

#include "ChessGuiRenderer.h"
#include "../Chess/ChessFacade.h"
#include "../Model/ChessGuiCell.h"
#include "../Model/ChessGuiCellManager.h"
#include "../Model/ChessSelectionPiece.h"
#include "../Model/Generator/ChessGuiPieceIconGenerator.h"
#include "../Shared/Chess/ChessConstants.h"
#include "ChessPieceSelection/ChessPieceSelectionRenderer.h"
#include "ChessTimer.h"
#include "QLabel"
#include "QListWidget"
#include "QPainter"
#include "QTime"
#include "QTimer"
#include "QWidget"
#include "Settings/ChessSpeedButtons.h"
#include "Settings/ChessStartButton.h"
#include "Settings/ChessSettingsButton.h"
#include "Timeline/ChessTimelineRenderer.h"
#include <QGridLayout>
#include <utility>
#include "QColor"
#include "PlayerLabel/PlayerLabelRenderer.h"
#include "PlayerLabel/PlayerLabel.h"
#include "Settings/ChessSettingsRenderer.h"
#include "ChessGrid/ChessGridRenderer.h"
#include "ChessInfo/ChessInfo.h"
#include "../../MultiplayerGui/MultiplayerGuiFacade.h"
#include "../../MultiplayerGui/Model/Button/MultiplayerStartButton.h"
#include "../../Shared/ChessGui/Transfer/Multiplayer/MultiplayerChessGuiTransfer.h"
#include "iostream"
#include "BackToMenu/BackToMenu.h"

QWidget *ChessGuiRenderer::mainChessWindow = nullptr;

ChessGuiRenderer::ChessGuiRenderer(
    ChessFacade *chessFacade,
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiCellManager *chessGuiCellManager,
    ChessPieceSelectionRenderer *chessPieceSelectionRenderer,
    ChessTimelineRenderer *chessTimelineRenderer,
    PlayerLabelRenderer *playerLabelRenderer,
    ChessSettingsRenderer *chessSettingsRenderer,
    ChessGridRenderer *chessGridRenderer,
    MultiplayerGuiFacade *multiplayerGuiFacade
) {
    this->chessFacade = chessFacade;
    this->multiplayerGuiFacade = multiplayerGuiFacade;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessGuiCellManager = chessGuiCellManager;
    this->chessPieceSelectionRenderer = chessPieceSelectionRenderer;
    this->chessTimelineRenderer = chessTimelineRenderer;
    this->playerLabelRenderer = playerLabelRenderer;
    this->chessSettingsRenderer = chessSettingsRenderer;
    this->chessGridRenderer = chessGridRenderer;
}

void ChessGuiRenderer::createSettingsPage(QWidget *mainWindow) {
    auto hBoxStartMenuBracketLayout = new QHBoxLayout(mainWindow);
    auto vBoxStartAndSettingsButtonsLayout = new QVBoxLayout();
    auto vBoxSpeedButtonsLayout = new QVBoxLayout();

    auto startPushbutton = new ChessStartButton(this, mainWindow);
    startPushbutton->setText("Start");
    auto settingsPushbutton = new ChessSettingsButton(this->chessSettingsRenderer);
    settingsPushbutton->setText("Settings");
    auto chessInfoButton = new ChessInfo();
    chessInfoButton->setText("Info");
    

    auto speedPushbuttonClassic = new ChessSpeedButtons(this, 0);
    speedPushbuttonClassic->setText("Classic");
    auto speedPushbuttonFast = new ChessSpeedButtons(this, 1800);
    speedPushbuttonFast->setText("Fast");
    auto speedPushbuttonBlitz = new ChessSpeedButtons(this, 300);
    speedPushbuttonBlitz->setText("Blitz");
    auto speedPushbuttonBullet = new ChessSpeedButtons(this, 180);
    speedPushbuttonBullet->setText("Bullet");



    vBoxStartAndSettingsButtonsLayout->addWidget(startPushbutton);
    vBoxStartAndSettingsButtonsLayout->addWidget(
        this->multiplayerGuiFacade->createMultiplayerStartButton()
    );
    vBoxStartAndSettingsButtonsLayout->addWidget(settingsPushbutton);
    vBoxStartAndSettingsButtonsLayout->addWidget(chessInfoButton);

    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonClassic);
    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonFast);
    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonBlitz);
    vBoxSpeedButtonsLayout->addWidget(speedPushbuttonBullet);

    hBoxStartMenuBracketLayout->addLayout(vBoxStartAndSettingsButtonsLayout);
    hBoxStartMenuBracketLayout->addLayout(vBoxSpeedButtonsLayout);
    hBoxStartMenuBracketLayout->addLayout(
        this->multiplayerGuiFacade->createLobbyLayout()
    );
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    // -- Grid und stuff
    auto hBoxMainBracketLayout = new QHBoxLayout(mainWindow);
    auto vBoxMainContainer = new QVBoxLayout(mainWindow);

    auto hBoxMenuButtonslayout = new QHBoxLayout(mainWindow);

    ChessGuiRenderer::mainChessWindow = mainWindow;

    QWidget *checkmateWindow;
    auto backToMainMenu = new BackToMenu(mainWindow, checkmateWindow,false);
    backToMainMenu->setText("Menu");
    hBoxMenuButtonslayout->addWidget(backToMainMenu);
    auto spacer1 = new QLabel("");
    hBoxMenuButtonslayout->addWidget(spacer1);
    auto spacer3 = new QLabel("");
    hBoxMenuButtonslayout->addWidget(spacer3);
    auto spacer4 = new QLabel("");
    hBoxMenuButtonslayout->addWidget(spacer4);


    auto vBoxSideInformationPanel = new QVBoxLayout(mainWindow);

    auto hBoxFullGridAndSideInformationPanelLayout = new QHBoxLayout(mainWindow);
    auto vBoxGridAndLetterContainerLayout = new QVBoxLayout(mainWindow);
    auto vBoxNumberLayout = new QVBoxLayout(mainWindow);

    auto vBoxNumberListLayout = new QVBoxLayout(mainWindow);
    auto hBoxLetterListLayout = new QHBoxLayout(mainWindow);

    auto hBoxCountdownLayoutBlack = new QHBoxLayout(mainWindow);
    auto hBoxCountdownLayoutWhite = new QHBoxLayout(mainWindow);

    auto hboxTopPanelLayout = new QHBoxLayout(mainWindow);
    auto hboxBottomPanelLayout = new QHBoxLayout(mainWindow);

    this->playerLabelRenderer->createPlayerLabels();
    PlayerLabel *p1 = this->playerLabelRenderer->getPlayerLabel(1);
    p1->setCurrentPlayerColor();
    PlayerLabel *p2 = this->playerLabelRenderer->getPlayerLabel(2);

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

    // ChessGrid
    auto *chessGridLayout = this->chessGridRenderer->createChessFieldWithPieces();

    vBoxGridAndLetterContainerLayout->addLayout(chessGridLayout);
    vBoxGridAndLetterContainerLayout->addLayout(hBoxLetterListLayout);

    hBoxFullGridAndSideInformationPanelLayout->addLayout(vBoxNumberLayout);
    hBoxFullGridAndSideInformationPanelLayout->addLayout(vBoxGridAndLetterContainerLayout);

    // MainWindow Player1 -> Grid -> Player2
    vBoxMainContainer->addLayout(hBoxMenuButtonslayout);
    vBoxMainContainer->addLayout(hboxTopPanelLayout);
    vBoxMainContainer->addLayout(hBoxChessPieceSelectionBottom);
    vBoxMainContainer->addLayout(hBoxFullGridAndSideInformationPanelLayout);
    vBoxMainContainer->addLayout(hBoxChessPieceSelectionTop);
    vBoxMainContainer->addLayout(hboxBottomPanelLayout);

    // Befüllen von Labels
    hboxTopPanelLayout->addWidget(chessFieldSideNumberEmpty3);
    hboxTopPanelLayout->addWidget(p2);
    //hboxTopPanelLayout->addWidget(player2ActiveLabel );

    hboxBottomPanelLayout->addWidget(chessFieldSideNumberEmpty4);
    hboxBottomPanelLayout->addWidget(p1);
    //hboxBottomPanelLayout->addWidget(player1ActiveLabel);

    // Countdown
    if (this->speedModeTimerValue > 0) {
        auto *digitalClockBlack = new ChessTimer(2, this->speedModeTimerValue);
        auto *digitalClockWhite = new ChessTimer(1,this->speedModeTimerValue);

        hBoxCountdownLayoutBlack->addWidget(digitalClockBlack);
        hBoxCountdownLayoutWhite->addWidget(digitalClockWhite);
    }

    // Timeline layouts
    auto hBoxTimelineLayout = this->chessTimelineRenderer->createHBoxChessTimelineLayout();
    auto hBoxTimelineButtonsLayout = this->chessTimelineRenderer->createHBoxTimelineButtonsLayout(
        this->chessTimelineFacade,
        this->chessGuiCellManager,
        this->chessFacade
    );

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

    this->chessGuiCellManager->setChessGuiCellGrid(chessGridLayout);
}


void ChessGuiRenderer::onPressStartButton(QWidget *mainWindow) {
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

void ChessGuiRenderer::startMultiplayerChessGame(
    MultiplayerChessGuiTransfer *multiplayerChessGuiTransfer
) {
    this->playerLabelRenderer->updateLabelTextsWithUsername(multiplayerChessGuiTransfer);

    auto *mainGridWindow = new QWidget;

    this->createChessField(mainGridWindow);

    mainGridWindow->show();
}

QWidget *ChessGuiRenderer::getMainWindow(){
    return ChessGuiRenderer::mainChessWindow;
}