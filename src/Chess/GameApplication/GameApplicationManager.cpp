//
// Created by Julian Sommer on 07.09.23.
//

#include "GameApplicationManager.h"
#include "../Creator/ChessCreator.h"
#include "../../Shared/Chess/Transfer/ChessMovementResponseTransfer.h"
#include "../../Shared/Chess/Transfer/ChessPiece/ChessPiecePositionTransfer.h"
#include "../../Shared/ChessTimeline/EndTurnInformationTransfer.h"
#include "../../Shared/ChessTimeline/ChessTurnLogTransfer.h"
#include "../../Shared/Chess/Transfer/GameState/ChessGameStateTransfer.h"
#include "../../Shared/Chess/ChessMovementConstants.h"
#include "../../Shared/ChessGui/Transfer/Multiplayer/MultiplayerChessGuiTransfer.h"
#include "GameApplication.h"
#include "../Movement/ChessPieceMovementManager.h"
#include "../Checkmate/CheckmateManager.h"
#include "../Model/ChessCell.h"
#include "../Model/ChessField.h"
#include "Player/ChessPlayerData.h"
#include "../ChessPiece/BaseChessPiece.h"
#include "Writer/GameApplicationDataWriter.h"
#include "Reader/GameApplicationDataReader.h"
#include "../../ChessTimeline/ChessTimelineFacade.h"
#include "../../Multiplayer/MultiplayerFacade.h"
#include "../../ChessGui/ChessGuiFacade.h"
#include "iostream"
#include <QJsonObject>

GameApplicationManager::GameApplicationManager(
    ChessCreator *chessCreator,
    ChessPieceMovementManager* chessPieceMovementManager,
    CheckmateManager *checkmateManager,
    GameApplicationDataWriter *gameApplicationDataWriter,
    GameApplicationDataReader *gameApplicationDataReader,
    ChessTimelineFacade *chessTimelineFacade,
    ChessGuiFacade *chessGuiFacade,
    MultiplayerFacade *multiplayerFacade
) {
    this->chessCreator = chessCreator;
    this->chessPieceMovementManager = chessPieceMovementManager;
    this->checkmateManager = checkmateManager;
    this->gameApplicationDataWriter = gameApplicationDataWriter;
    this->gameApplicationDataReader = gameApplicationDataReader;
    this->chessTimelineFacade = chessTimelineFacade;
    this->chessGuiFacade = chessGuiFacade;
    this->multiplayerFacade = multiplayerFacade;
}


void GameApplicationManager::initiateChessApplication() {
    auto *chessField = new ChessField;
    auto *chessPlayer1Data = new ChessPlayerData;
    auto *chessPlayer2Data = new ChessPlayerData;

    this->chessCreator->initiateChessData(chessField, chessPlayer1Data, chessPlayer2Data);

    GameApplication::setChessField(chessField);
    GameApplication::setChessPlayer1Data(chessPlayer1Data);
    GameApplication::setChessPlayer2Data(chessPlayer2Data);
}

void GameApplicationManager::startMultiplayerMatch(QJsonObject startMatchResponseData)
{
    this->gameApplicationDataWriter->writeMultiplayerStartData(
        startMatchResponseData[QLatin1String("player")].toInt(),
        startMatchResponseData[QLatin1String("opponentPlayer")].toInt()
    );

    this->chessGuiFacade->initGuiForMultiplayerChessGame(
      (new MultiplayerChessGuiTransfer())->fromJsonObject(startMatchResponseData)
    );
}

ChessMovementResponseTransfer GameApplicationManager::handleChessCellClick(
    pair<int, int> currentCellCoordinates
) {
    auto chessMovementResponseTransfer = ChessMovementResponseTransfer();
    this->expandChessMovementResponseTransfer(chessMovementResponseTransfer);

    if (this->gameApplicationDataReader->isMultiplayerMatch()
        && this->gameApplicationDataReader->isOpponentTurn()
    ) {
        return *chessMovementResponseTransfer.setState(ChessMovementConstants::MOVEMENT_STATE_NOT_MOVED);
    }

    if (chessMovementResponseTransfer.getState() == ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH_SELECTION
        || chessMovementResponseTransfer.getState() == ChessMovementConstants::MOVEMENT_STATE_PAWN_SWITCH_SELECTION_START) {

        return chessMovementResponseTransfer;
    }

    auto playerInCheckStatus = GameApplication::getCurrentChessPlayerData()->isPlayerInCheck();

    chessMovementResponseTransfer = this->chessPieceMovementManager->handleChessMovement(
        currentCellCoordinates,
        chessMovementResponseTransfer,
        playerInCheckStatus,
        GameApplication::getOpponentChessPlayerData()
    );

    this->gameApplicationDataWriter->updateGameApplicationCurrentGameState(chessMovementResponseTransfer.getState());
    this->gameApplicationDataWriter->saveChessMovementResponseTransfer(chessMovementResponseTransfer);

    return chessMovementResponseTransfer;
}

void GameApplicationManager::handlePawnPieceSwitch(string switchedPieceType)
{
    auto currentCoordinates = GameApplication::getPreviouslyClickedCellCoordinates();
    auto currentChessCell = GameApplication::getChessField()->getChessCell(currentCoordinates);

    auto chessPlayerData = GameApplication::getCurrentChessPlayerData();
    chessPlayerData->removePiece(currentChessCell->getChessPiece());

    auto switchedChessPiece = this->chessCreator->createChessPiece(switchedPieceType, GameApplication::getCurrentPlayer());
    switchedChessPiece->setCurrentCoordinates(currentCoordinates);

    currentChessCell->setChessPiece(switchedChessPiece);
    chessPlayerData->addPieceByType(switchedChessPiece, switchedPieceType);

    this->chessGuiFacade->handlePawnPieceSwitch(
        currentCoordinates,
        switchedPieceType
    );

    ChessPiecePositionTransfer chessPiecePositionTransfer = {};
    chessPiecePositionTransfer.setCurrentChessPieceCoordinates(currentCoordinates);

    this->endCurrentTurn(
        this->gameApplicationDataReader->getSavedChessMovementResponseTransfer(),
        chessPiecePositionTransfer
    );
}

void GameApplicationManager::endCurrentTurn(
    ChessMovementResponseTransfer chessMovementResponseTransfer,
    ChessPiecePositionTransfer chessPiecePositionTransfer
) {
    bool isMultiplayerMatch = this->gameApplicationDataReader->isMultiplayerMatch();
    bool isOpponentTurn = this->gameApplicationDataReader->isOpponentTurn();

    cout << "endCurrentTurn isMultiplayerMatch:"<< isMultiplayerMatch << endl;
    cout << "endCurrentTurn isOpponentTurn: "<< isOpponentTurn <<endl;

    if (isMultiplayerMatch) {
        if (!isOpponentTurn) {
            this->multiplayerFacade
              ->sendJsonDataToServer(
                this->buildEndTurnJsonData(
                      chessMovementResponseTransfer,
                      chessPiecePositionTransfer
              )
            );

            this->gameApplicationDataWriter->setOpponentTurn(true);
        }

        if (isOpponentTurn) {
            GameApplication::switchPlayers();
            this->gameApplicationDataWriter->setOpponentTurn(false);

            this->chessGuiFacade->updateChessGuiGrid(
                chessMovementResponseTransfer,
                chessPiecePositionTransfer
            );
        }
    }

    this->logCurrentTurn(chessMovementResponseTransfer);

    if (isMultiplayerMatch && isOpponentTurn) {
          cout << "endCurrentTurn Update: "<< isOpponentTurn <<endl;

        this->chessPieceMovementManager
            ->updateMultiplayerChessGrid(
              this->chessTimelineFacade
                  ->findChessTurnLogForTurn(
                      this->gameApplicationDataReader->getTurnCounter()
                  )
            );
    }

    this->chessGuiFacade->updateTimelineTurnProperties(
        this->gameApplicationDataReader->getTurnCounter()
    );


    if (isMultiplayerMatch && isOpponentTurn) {
        GameApplication::switchPlayers();
    }
    GameApplication::togglePreviousClickedCellValue();

    this->updateStateLastTurnChessPieces();

    GameApplication::increaseTurnCounter();
    GameApplication::setCoordinatesOfLastTurnClickedCell(chessPiecePositionTransfer.getCurrentChessPieceCoordinates());

    this->chessPieceMovementManager->clearPossibleMoveCollections();

    this->startNewTurn();
}

void GameApplicationManager::rewindCurrentTurn(
    ChessTurnLogTransfer *chessTurnLogTransferToRewind
) {
    this->chessPieceMovementManager->updateChessGrid(chessTurnLogTransferToRewind);

    auto *gameStateTransfer = chessTurnLogTransferToRewind->getChessGameStateTransfer();

    this->chessGuiFacade->updateTimelineTurnProperties(
        this->gameApplicationDataReader->getTurnCounter()-2
    );

    this->gameApplicationDataWriter->updateGameApplicationData(
        gameStateTransfer
    );
    this->updateStateLastTurnChessPieces();
    GameApplication::setHasPreviousClickedCell(false);

    this->chessPieceMovementManager->clearPossibleMoveCollections();

    this->chessTimelineFacade->deleteLastTurnLog();

    this->startNewTurn();
}

void GameApplicationManager::updateStateLastTurnChessPieces() {
    if (GameApplication::getTurnCounter() == 0) {
        return;
    }

    auto *lastTurnClickedChessCellChessPiece = GameApplication::getChessCell(GameApplication::getCoordinatesOfLastTurnClickedCell())->getChessPiece();
    if (lastTurnClickedChessCellChessPiece) {
        lastTurnClickedChessCellChessPiece->updateLastTurnMovedStatus();
    }
}

void GameApplicationManager::startNewTurn()
{
    this->checkmateManager->determineCurrentGameState(
      GameApplication::getChessField(),
      GameApplication::getCurrentChessPlayerData(),
      GameApplication::getOpponentChessPlayerData(),
      GameApplication::getCurrentPlayer()
    );

    this->chessGuiFacade->updatePlayerColor(this->gameApplicationDataReader->getCurrentPlayer());
}

int GameApplicationManager::getCurrentPlayer() {
    return GameApplication::getCurrentPlayer();
}

void GameApplicationManager::expandChessMovementResponseTransfer(
    ChessMovementResponseTransfer &chessMovementResponseTransfer
) {
    this->expandChessMovementResponseTransferWithPlayers(chessMovementResponseTransfer);
    this->expandChessMovementResponseTransferWithCurrentGameState(chessMovementResponseTransfer);
}

void GameApplicationManager::expandChessMovementResponseTransferWithCurrentGameState(
    ChessMovementResponseTransfer &chessMovementResponseTransfer
) {
    chessMovementResponseTransfer.setState(
      this->gameApplicationDataReader->getCurrentGameState()
    );
}

void GameApplicationManager::expandChessMovementResponseTransferWithPlayers(
    ChessMovementResponseTransfer &chessMovementResponseTransfer
) {
    chessMovementResponseTransfer.setCurrentPlayer(
      this->gameApplicationDataReader->getCurrentPlayer()
      )->setCurrentOpponentPlayer(
          this->gameApplicationDataReader->getCurrentOpponentPlayer()
        );
}

void GameApplicationManager::logCurrentTurn(
    ChessMovementResponseTransfer chessMovementResponseTransfer
) {
    EndTurnInformationTransfer endTurnInformationTransfer = {};
    auto *chessGameStateTransfer = this->gameApplicationDataReader->getCurrentGameStateData();

    endTurnInformationTransfer.setChessGameStateTransfer(chessGameStateTransfer)
        ->setChessPieceStateTransfers(
            chessMovementResponseTransfer.getChessPieceStateTransfers()
    );

    this->chessTimelineFacade->logCurrentTurnData(endTurnInformationTransfer);
}

QJsonObject GameApplicationManager::buildEndTurnJsonData(
    ChessMovementResponseTransfer chessMovementResponseTransfer,
    ChessPiecePositionTransfer chessPiecePositionTransfer
) {
    QJsonObject jsonData;

    jsonData["chessMovementResponseData"] = chessMovementResponseTransfer.toQJsonObject();
    jsonData["chessPiecePositionData"] = chessPiecePositionTransfer.toQJsonObject();
    jsonData["requestType"] = QString::fromStdString("endCurrentTurn");

    return jsonData;
}