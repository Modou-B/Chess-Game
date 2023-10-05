//
// Created by Modou on 05.10.23.
//

#include "ChessSettingsRenderer.h"
#include "QWidget"
#include "QLabel"
#include "QPushButton"
#include "QLayout"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QColor>
#include "string"

#include "ChessChoosePlayerColor.h"
#include "ChessChooseCellColor.h"
#include "../../../Shared/ChessGui/ChessGuiConstants.h"

int ChessSettingsRenderer::selectedPlayer = 1;
QColor ChessSettingsRenderer::player1Color = ChessGuiConstants::CELL_YELLOW_COLOR;
QColor ChessSettingsRenderer::player2Color = ChessGuiConstants::CELL_GREEN_COLOR;

void ChessSettingsRenderer::onPressSettingsButton() {
    this->createSettingsView();
    //QWidget *settingsWindow;

    //while ( auto* w = settingsWindow->findChild<QWidget*>() ) {
     //   delete w;
    //}

    //this->createChessField(mainGridWindow);

    //settingsWindow->close();
}

void ChessSettingsRenderer::createSettingsView() {
    auto *settingsWindow = new QWidget;

    auto hBoxMainContainerLayout = new QHBoxLayout(settingsWindow);
    auto vBoxChooseColorAndPreviewGridLayout = new QVBoxLayout(settingsWindow);
    auto vBoxOtherSettingsLayout = new QVBoxLayout(settingsWindow);


    auto hBoxPlayerButtonsLayout = new QHBoxLayout();
    auto hBoxPreviewLayout = new QHBoxLayout();
    auto hBoxColorButtonRow1Layout = new QHBoxLayout();
    auto hBoxColorButtonRow2Layout = new QHBoxLayout();

    auto hBoxSaveAndExitLayout = new QHBoxLayout();
    auto hBoxSpacerLayout = new QHBoxLayout();

    auto saveButton = new QPushButton("Save");
    auto exitButton = new QPushButton("Exit");

    auto spacer1 = new QLabel(" ");
    auto spacer2 = new QLabel(" ");

    auto choosePlayer = new QLabel("Choose a player");
    choosePlayer->setAlignment(Qt::AlignCenter);
    auto chooseColor = new QLabel("Choose a color");
    chooseColor->setAlignment(Qt::AlignCenter);

    auto player1Button = new ChessChoosePlayerColor(this,1);
    player1Button->setText("Player 1");
    auto player2Button = new ChessChoosePlayerColor(this, 2);
    player2Button->setText("Player 2");




    auto colorRedButton = new ChessChooseCellColor(this, QColor(255, 0, 0));
    colorRedButton->setText("Red");
    auto colorBlueButton = new ChessChooseCellColor(this, QColor(0,191,255));
    colorBlueButton->setText("Blue");
    auto colorGreenButton = new ChessChooseCellColor(this, QColor(124,252,0));
    colorGreenButton->setText("Green");


    auto colorYellowButton = new ChessChooseCellColor(this, QColor(255,255,0));
    colorYellowButton->setText("Yellow");
    auto colorPurpleButton = new ChessChooseCellColor(this, QColor(128,0,128));
    colorPurpleButton->setText("Purple");
    auto colorOrangeButton = new ChessChooseCellColor(this, QColor(255,140,0));
    colorOrangeButton->setText("Orange");



    // Playerbuttons in hBox
    hBoxPlayerButtonsLayout->addWidget(player1Button);
    hBoxPlayerButtonsLayout->addWidget(player2Button);

    // Colorbuttons in hBox
    hBoxColorButtonRow1Layout->addWidget(colorRedButton);
    hBoxColorButtonRow1Layout->addWidget(colorBlueButton);
    hBoxColorButtonRow1Layout->addWidget(colorGreenButton);

    hBoxColorButtonRow2Layout->addWidget(colorYellowButton);
    hBoxColorButtonRow2Layout->addWidget(colorPurpleButton);
    hBoxColorButtonRow2Layout->addWidget(colorOrangeButton);



    hBoxSpacerLayout->addWidget(spacer1);
    hBoxSpacerLayout->addWidget(spacer2);

    hBoxSaveAndExitLayout->addWidget(exitButton);
    hBoxSaveAndExitLayout->addWidget(saveButton);

    vBoxChooseColorAndPreviewGridLayout->addWidget(choosePlayer);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxPreviewLayout);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxPlayerButtonsLayout);
    vBoxChooseColorAndPreviewGridLayout->addWidget(chooseColor);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxColorButtonRow1Layout);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxColorButtonRow2Layout);

    vBoxOtherSettingsLayout->addLayout(hBoxSpacerLayout);
    vBoxOtherSettingsLayout->addLayout(hBoxSaveAndExitLayout);


    hBoxMainContainerLayout->addLayout(vBoxChooseColorAndPreviewGridLayout);
    hBoxMainContainerLayout->addLayout(vBoxOtherSettingsLayout);

    settingsWindow->show();
}

void ChessSettingsRenderer::setChoosePlayer(int player) {
    qDebug() << std::to_string(player);
    ChessSettingsRenderer::selectedPlayer = player;
}

void ChessSettingsRenderer::setPlayerColor(QColor playerColor) {
    if (ChessSettingsRenderer::selectedPlayer == 1) {
        ChessSettingsRenderer::player1Color = playerColor;
        return;
    }

    ChessSettingsRenderer::player2Color = playerColor;
}

QColor ChessSettingsRenderer::getColorForPlayer(int player) {
    if (player == 1) {
        return ChessSettingsRenderer::player1Color;
    }

    return ChessSettingsRenderer::player2Color;
}
