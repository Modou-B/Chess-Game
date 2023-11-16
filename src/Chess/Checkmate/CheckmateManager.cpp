//
// Created by Julian Sommer on 18.09.23.
//

#include "CheckmateManager.h"
#include "Status/InCheckStatusChecker.h"
#include "Status/InStalemateStatusChecker.h"
#include "Status/BareKingDrawStatusChecker.h"
#include "../Model/ChessField.h"
#include "../Model/ChessCell.h"
#include "../GameApplication/Player/ChessPlayerData.h"
#include "../ChessPiece/BaseChessPiece.h"
#include "../../Shared/Chess/Transfer/Checkmate/InCheckResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiecePossibleMoveTransfer.h"
#include "iostream"
#include "QWidget"
#include "../MainFacade.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "../ChessGui/Renderer/BackToMenu/BackToMenu.h"
#include "../ChessGui/Renderer/ChessGuiRenderer.h"

CheckmateManager::CheckmateManager(
    InCheckStatusChecker *inCheckStatusChecker, InStalemateStatusChecker *inStalemateStatusChecker, BareKingDrawStatusChecker *bareKingDrawStatusChecker) {

    this->inCheckStatusChecker = inCheckStatusChecker;
    this->inStalemateStatusChecker = inStalemateStatusChecker;
    this->bareKingDrawStatusChecker = bareKingDrawStatusChecker;
}


void CheckmateManager::determineCurrentGameState(ChessField *chessField, ChessPlayerData *currentChessPlayerData, ChessPlayerData *opponentChessPlayerData, int player) {
    auto kingPieceCoordinates = currentChessPlayerData->getKingPiece()->getCurrentCoordinates();

    auto inCheckResponseTransfer = this->inCheckStatusChecker->getAmountOfPiecesThatCheckKing(
      chessField, kingPieceCoordinates, player);

    std::cout << "AmountOfPiecesThatCheckKing " <<inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() << std::endl;

    if (inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() > 0) {
        currentChessPlayerData->setInCheckStatus(true);

        this->isPlayerInCheckmate(chessField, kingPieceCoordinates, currentChessPlayerData, inCheckResponseTransfer, player);

        return;
    }

    currentChessPlayerData->setInCheckStatus(false);
    if (this->inStalemateStatusChecker->isKingInStalemate(
          chessField, currentChessPlayerData, kingPieceCoordinates)
    ) {
        std::cout << "Stalemate" << std::endl;
        StalemateScreen();
    }

    if (this->bareKingDrawStatusChecker->isCheckmateNotPossible(currentChessPlayerData, opponentChessPlayerData)) {
        std::cout << "Bare King" << std::endl;
        StalemateScreen();
    }
}

bool CheckmateManager::isPlayerInCheckmate(
    ChessField *chessField, std::pair<int, int> kingPieceCoordinates, ChessPlayerData *chessPlayerData, InCheckResponseTransfer inCheckResponseTransfer, int currentPlayer) {
    auto possibleMovesForKingPiece = chessField->getChessCell(kingPieceCoordinates)->getChessPiece()->determinePossibleMoves(chessField, kingPieceCoordinates);

    int amountOfPiecesThatBlockCheck = this->inCheckStatusChecker->getAmountOfPiecesThatBlockCheck(chessField, chessPlayerData, inCheckResponseTransfer, kingPieceCoordinates, currentPlayer);
    if (possibleMovesForKingPiece.empty()) {
        if (inCheckResponseTransfer.getAmountOfPiecesThatCheckCell() > 1) {
            std::cout << "Checkmate" << std::endl;
            checkmateScreen(currentPlayer);
        }

        if (amountOfPiecesThatBlockCheck == 0) {
            std::cout << "Checkmate2" << std::endl;

            checkmateScreen(currentPlayer);
        }
    }

    return false;
}

void CheckmateManager::checkmateScreen(int player) {
        auto *checkmateWindow = new QWidget;
        checkmateWindow->setFixedSize(300,200);

        auto hBoxContainerLayout = new QHBoxLayout(checkmateWindow);
        auto vBoxContainerLayout = new QVBoxLayout(checkmateWindow);
        auto checkMatePlayer1Label = new QLabel("CHECKMATE - Player 1 wins!!!" );
        auto checkMatePlayer2Label = new QLabel("CHECKMATE - Player 2 wins!!!" );

        auto backToMenu = new BackToMenu(ChessGuiRenderer::getMainWindow(),checkmateWindow, true);
        backToMenu->setText("Menu");

        if (player == 1) {
            vBoxContainerLayout->addWidget(checkMatePlayer2Label);
        } else {
            vBoxContainerLayout->addWidget(checkMatePlayer1Label);
        }

        vBoxContainerLayout->addWidget(backToMenu);
        hBoxContainerLayout->addLayout(vBoxContainerLayout);

        checkmateWindow->show();
}

void CheckmateManager::StalemateScreen() {
    auto *stalemateWindow = new QWidget;
    stalemateWindow->setFixedSize(300, 200);

    auto hBoxContainerLayout = new QHBoxLayout(stalemateWindow);
    auto vBoxContainerLayout = new QVBoxLayout(stalemateWindow);
    auto stalemateLabel = new QLabel("STALEMATE" );

    auto backToMenu = new BackToMenu(ChessGuiRenderer::getMainWindow(), stalemateWindow, true);
    backToMenu->setText("Menu");

    vBoxContainerLayout->addWidget(stalemateLabel);

    vBoxContainerLayout->addWidget(backToMenu);
    hBoxContainerLayout->addLayout(vBoxContainerLayout);

    stalemateWindow->show();
}