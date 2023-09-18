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
#include "QPainter"
#include "QLabel"
#include "QPushButton"
#include "QLCDNumber"
#include "QTimer"
#include "QTime"
#include "QListWidget"
#include "QListWidgetItem"



ChessGuiRenderer::ChessGuiRenderer(ChessFacade *chessFacade, ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator) {
    this->chessFacade = chessFacade;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    auto hBoxMainBracketLayout = new QHBoxLayout(mainWindow);
    auto vBox1Layout = new QVBoxLayout(mainWindow);
    auto vBox2Layout = new QVBoxLayout(mainWindow);


    auto hBoxPlaybuttonsLayout = new QHBoxLayout(mainWindow);
    auto hBoxCountdownLayout = new QHBoxLayout(mainWindow);
    auto hBoxRewindLayout = new QHBoxLayout(mainWindow);

    auto hboxTopPanelLayout = new QHBoxLayout(mainWindow);
    auto hboxBottomPanelLayout = new QHBoxLayout(mainWindow);

    auto player1Label = new QLabel("Player 1");
    auto player1ActiveLabel = new QLabel("*Am Zug");
    auto player2Label = new QLabel("Player 2");
    auto player2ActiveLabel = new QLabel("*Am Zug");

    auto *buttonRewind = new QPushButton("<<");
    auto *buttonPause = new QPushButton(">||");
    auto *buttonSkip = new QPushButton(">>");

    auto *gridLayout = this->createChessGridLayout(mainWindow);

    auto *digitalClock = new QLCDNumber();

    auto *timer = new QTimer(mainWindow);


    auto *rewindList = new QListWidget(mainWindow);

    auto *rewindListEntry = new QListWidgetItem();




    QObject::connect(timer,SIGNAL(timeout()), digitalClock, SLOT(TestTimer()));
    //timer->start(1000);

    //auto *time = new QTime(0,1,0);

    digitalClock->display(QString::fromStdString(std::string("1000")));
    //digitalClock->display(time);


    // MainWindow Player1 -> Grid -> Player2
    vBox1Layout->addLayout(hboxTopPanelLayout);
    vBox1Layout->addLayout(gridLayout);
    vBox1Layout->addLayout(hboxBottomPanelLayout);


    // Befüllen von Labels
    hboxTopPanelLayout->addWidget(player1Label);
    hboxTopPanelLayout->addWidget(player1ActiveLabel);
    hboxBottomPanelLayout->addWidget(player2Label);
    hboxBottomPanelLayout->addWidget(player2ActiveLabel);

    // Playbuttons
    hBoxPlaybuttonsLayout->addWidget(buttonRewind);
    hBoxPlaybuttonsLayout->addWidget(buttonPause);
    hBoxPlaybuttonsLayout->addWidget(buttonSkip);


    //auto *rewindAction = new QAction();
    // QObject::connect(buttonRewind, SIGNAL(triggered()), rewindAction,SLOT(onRewindButtonPress()));




    // Countdown
    hBoxCountdownLayout->addWidget(digitalClock);

    // Rewindlist
    hBoxRewindLayout->addWidget(rewindList);

    vBox2Layout->addLayout(hBoxCountdownLayout);
    vBox2Layout->addLayout(hBoxRewindLayout);
    vBox2Layout->addLayout(hBoxPlaybuttonsLayout);

    // In den horizontalen Rahmen das Grid und die Playerlabel einsetzen
    hBoxMainBracketLayout->addLayout(vBox1Layout);
    hBoxMainBracketLayout->addLayout(vBox2Layout);

    // Das rechte Menü samt Countdown und playerbutton einsetzen
    hBoxMainBracketLayout->addLayout(hBoxCountdownLayout);

    this->fillFieldWithEmptyCells(gridLayout);
    this->addPawnsToCells(gridLayout);
    this->addQueensToCells(gridLayout);
    this->addKingsToCells(gridLayout);
    this->addBishopsToCells(gridLayout);
    this->addKnightsToCells(gridLayout);
    this->addRooksToCells(gridLayout);
}

void ChessGuiRenderer::TimeSlot() {
    //counter ++;
    qDebug() << QString("Test");
}


QGridLayout *ChessGuiRenderer::createChessGridLayout(QWidget *mainWindow) {
    return new QGridLayout();
}


void ChessGuiRenderer::fillFieldWithEmptyCells(QGridLayout *layout) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::pair<int, int> coordinates = std::make_pair(i, j);
            ChessGuiCell *chessGuiCell = new ChessGuiCell(layout, this->chessFacade, coordinates, this->chessGuiPieceIconGenerator);

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

void ChessGuiRenderer::addListWidgetItem(std::pair<int, int> currentCellCoordinates) {
    qDebug() << "First: "+QString::number(currentCellCoordinates.first);
    qDebug() << "Second: "+QString::number(currentCellCoordinates.second);
    //rewindListEntry->setText("test");

    //rewindList->insertItem(0, rewindListEntry);
}
