//
// Created by Modou on 05.10.23.
//

#include "ChessSettingsRenderer.h"
#include "QWidget"
#include "QLabel"
#include "QPushButton"
#include "QLayout"
#include <QColor>
#include "string"
#include "../ChessGrid/ChessGridRenderer.h"
#include "../../Model/Settings/ChessSettingsDataHolder.h"
#include "ChessChoosePlayerColor.h"
#include "ChessChooseCellColor.h"
#include "ChessSaveButton.h"
#include "ChessExitButton.h"

QWidget *ChessSettingsRenderer::settingsWindow = nullptr;

ChessSettingsRenderer::ChessSettingsRenderer(
    ChessGridRenderer *chessGridRenderer,
    ChessSettingsDataHolder *chessSettingsDataHolder
) {
    this->chessGridRenderer = chessGridRenderer;
    this->chessSettingsDataHolder = chessSettingsDataHolder;
}

void ChessSettingsRenderer::createSettingsView()
{
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

    auto saveButton = new ChessSaveButton(this, settingsWindow);
    saveButton->setText("Save");
    auto exitButton = new ChessExitButton(this, settingsWindow);
    exitButton->setText("Exit");

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

    auto colorRedButton = new ChessChooseCellColor(this, QColor(102, 18, 28));
    colorRedButton->setText("Red");
    auto colorBlueButton = new ChessChooseCellColor(this, QColor(104,134,170));
    colorBlueButton->setText("Blue");
    auto colorGreenButton = new ChessChooseCellColor(this, QColor(23, 87, 23));
    colorGreenButton->setText("Green");

    auto colorWhiteButton = new ChessChooseCellColor(this, QColor(255, 250, 225));
    colorWhiteButton->setText("White");
    auto colorPurpleButton = new ChessChooseCellColor(this, QColor(128,0,128));
    colorPurpleButton->setText("Purple");
    auto colorOrangeButton = new ChessChooseCellColor(this, QColor(197,120,55));
    colorOrangeButton->setText("Orange");

    // Playerbuttons in hBox
    hBoxPlayerButtonsLayout->addWidget(player1Button);
    hBoxPlayerButtonsLayout->addWidget(player2Button);

    // Colorbuttons in hBox
    hBoxColorButtonRow1Layout->addWidget(colorRedButton);
    hBoxColorButtonRow1Layout->addWidget(colorBlueButton);
    hBoxColorButtonRow1Layout->addWidget(colorGreenButton);

    hBoxColorButtonRow2Layout->addWidget(colorWhiteButton);
    hBoxColorButtonRow2Layout->addWidget(colorPurpleButton);
    hBoxColorButtonRow2Layout->addWidget(colorOrangeButton);

    this->chessGridRenderer->setCellSize(40, 40);
    this->chessGridRenderer->setIconSize(25, 25);
    auto *chessGridPreviewLayout = this->chessGridRenderer->createChessFieldWithPieces();
    this->chessSettingsDataHolder->setChessGridPreviewLayout(chessGridPreviewLayout);

    hBoxPreviewLayout->addLayout(chessGridPreviewLayout);
    hBoxSpacerLayout->addWidget(spacer1);
    hBoxSpacerLayout->addWidget(spacer2);

    hBoxSaveAndExitLayout->addWidget(exitButton);
    hBoxSaveAndExitLayout->addWidget(saveButton);

    vBoxChooseColorAndPreviewGridLayout->addWidget(choosePlayer);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxPlayerButtonsLayout);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxPreviewLayout);
    vBoxChooseColorAndPreviewGridLayout->addWidget(chooseColor);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxColorButtonRow1Layout);
    vBoxChooseColorAndPreviewGridLayout->addLayout(hBoxColorButtonRow2Layout);

    vBoxOtherSettingsLayout->addLayout(hBoxSpacerLayout);
    vBoxOtherSettingsLayout->addLayout(hBoxSaveAndExitLayout);


    hBoxMainContainerLayout->addLayout(vBoxChooseColorAndPreviewGridLayout);
    hBoxMainContainerLayout->addLayout(vBoxOtherSettingsLayout);

    settingsWindow->show();

    this->setSettingsWindow(settingsWindow);
}

void ChessSettingsRenderer::updateCellColors() {
    this->chessGridRenderer->updateChessGridCellColor(
        this->chessSettingsDataHolder->getChessGridPreviewLayout()
    );
}
void ChessSettingsRenderer::setPlayerToChooseColor(int player)
{
    this->chessSettingsDataHolder->setChoosePlayer(player);
}

void ChessSettingsRenderer::setColorForSetPlayer(QColor color)
{
    this->chessSettingsDataHolder->setPlayerColor(color);
}

void ChessSettingsRenderer::saveCustomColor() {
    this->chessSettingsDataHolder->savePlayerColors();
}

void ChessSettingsRenderer::setSettingsWindow(QWidget *settingsWindow) {
    ChessSettingsRenderer::settingsWindow = settingsWindow;
}

void ChessSettingsRenderer::closeSettingsWindow() {

}


