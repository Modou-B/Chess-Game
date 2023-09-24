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
#include "QTimer"
#include "QListWidget"
#include "ChessTimer.h"

ChessGuiRenderer::ChessGuiRenderer(ChessFacade *chessFacade, ChessGuiPieceIconGenerator *chessGuiPieceIconGenerator) {
    this->chessFacade = chessFacade;
    this->chessGuiPieceIconGenerator = chessGuiPieceIconGenerator;
}

void ChessGuiRenderer::createChessField(QWidget *mainWindow) {
    auto hBoxMainBracketLayout = new QHBoxLayout(mainWindow);
    auto vBox1Layout = new QVBoxLayout(mainWindow);
    auto vBox2Layout = new QVBoxLayout(mainWindow);

    auto hBoxGridAndSideLettAndNumLayout = new QHBoxLayout(mainWindow);
    auto vBoxGridAndSideLettAndNumLayout1 = new QVBoxLayout(mainWindow);
    auto vBoxGridAndSideLettAndNumLayout2 = new QVBoxLayout(mainWindow);

    auto vBoxSideNumbersLayout = new QVBoxLayout(mainWindow);
    auto hBoxSideLettersLayout = new QHBoxLayout(mainWindow);

    auto hBoxPlaybuttonsLayout = new QHBoxLayout(mainWindow);
    auto hBoxCountdownLayout = new QHBoxLayout(mainWindow);
    auto hBoxRewindLayout = new QHBoxLayout(mainWindow);

    auto hboxTopPanelLayout = new QHBoxLayout(mainWindow);
    auto hboxBottomPanelLayout = new QHBoxLayout(mainWindow);

    auto player1Label = new QLabel("Player 1");
    //player1Label->setAlignment(Qt::AlignRight);
    auto player1ActiveLabel = new QLabel("*Am Zug");
    auto player2Label = new QLabel("Player 2");
    auto player2ActiveLabel = new QLabel("*Am Zug");


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
    auto chessFieldSideNumberEmpty1 = new QLabel("");

    auto chessFieldSideNumberEmpty2 = new QLabel("");

    auto chessFieldSideNumberEmpty3 = new QLabel("");

    auto chessFieldSideNumberEmpty4 = new QLabel("");

    auto chessFieldSideNumberEmpty5 = new QLabel("");

    auto *buttonRewind = new QPushButton("<<");
    auto *buttonPause = new QPushButton(">||");
    auto *buttonSkip = new QPushButton(">>");

    auto *gridLayout = this->createChessGridLayout(mainWindow);

    auto *digitalClock = new ChessTimer();


    //timer->start(1000);

    //auto *time = new QTime(0,1,0);

    //digitalClock->display(time);

    //vBoxSideNumbersLayout->addWidget(chessFieldSideNumberEmpty3);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber8);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber7);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber6);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber5);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber4);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber3);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber2);
    vBoxSideNumbersLayout->addWidget(chessFieldSideNumber1);
    //vBoxSideNumbersLayout->addWidget(chessFieldSideNumberEmpty2);
    //vBoxSideNumbersLayout->addWidget(chessFieldSideNumberEmpty1);


    hBoxSideLettersLayout->addWidget(chessFieldSideLetterA);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterB);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterC);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterD);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterE);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterF);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterG);
    hBoxSideLettersLayout->addWidget(chessFieldSideLetterH);

    vBoxGridAndSideLettAndNumLayout2->addLayout(vBoxSideNumbersLayout);
    vBoxGridAndSideLettAndNumLayout2->addWidget(chessFieldSideNumberEmpty1);

    vBoxGridAndSideLettAndNumLayout1->addLayout(gridLayout);
    vBoxGridAndSideLettAndNumLayout1->addLayout(hBoxSideLettersLayout);

    hBoxGridAndSideLettAndNumLayout->addLayout(vBoxGridAndSideLettAndNumLayout2);
    hBoxGridAndSideLettAndNumLayout->addLayout(vBoxGridAndSideLettAndNumLayout1);

    // MainWindow Player1 -> Grid -> Player2
    vBox1Layout->addLayout(hboxTopPanelLayout);
    // vBox1Layout->addLayout(gridLayout);
    //vBox1Layout->addLayout(hBoxSideLettersLayout);
    vBox1Layout->addLayout(hBoxGridAndSideLettAndNumLayout);
    vBox1Layout->addLayout(hboxBottomPanelLayout);


    // Befüllen von Labels
    hboxTopPanelLayout->addWidget(chessFieldSideNumberEmpty3);
    hboxTopPanelLayout->addWidget(player2Label);
    hboxTopPanelLayout->addWidget(player2ActiveLabel );

    hboxBottomPanelLayout->addWidget(chessFieldSideNumberEmpty4);
    hboxBottomPanelLayout->addWidget(player1Label);
    hboxBottomPanelLayout->addWidget(player1ActiveLabel);

    // Playbuttons
    hBoxPlaybuttonsLayout->addWidget(buttonRewind);
    hBoxPlaybuttonsLayout->addWidget(buttonPause);
    hBoxPlaybuttonsLayout->addWidget(buttonSkip);


    //auto *rewindAction = new QAction();
    // QObject::connect(buttonRewind, SIGNAL(triggered()), rewindAction,SLOT(onRewindButtonPress()));




    // Countdown
    hBoxCountdownLayout->addWidget(digitalClock);

    vBox2Layout->addLayout(hBoxCountdownLayout);
    vBox2Layout->addLayout(hBoxRewindLayout);
    vBox2Layout->addLayout(hBoxPlaybuttonsLayout);

    // In den horizontalen Rahmen das Grid und die Playerlabel einsetzen
    hBoxMainBracketLayout->addLayout(vBoxSideNumbersLayout); //Test
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