//
// Created by Julian Sommer on 02.11.23.
//

#ifndef CHESSAPPLICATION_MULTIPLAYERCHESSGUITRANSFER_H
#define CHESSAPPLICATION_MULTIPLAYERCHESSGUITRANSFER_H

#include <string>

using namespace std;

class QJsonObject;

class MultiplayerChessGuiTransfer {
private:
    string username;
    string opponentUsername;

    int currentPlayer;
    int opponentPlayer;

public:
    MultiplayerChessGuiTransfer *setUsername(string username);
    MultiplayerChessGuiTransfer *setOpponentUsername(string opponentUsername);

    MultiplayerChessGuiTransfer *setCurrentPlayer(int player);
    MultiplayerChessGuiTransfer *setOpponentPlayer(int player);

    MultiplayerChessGuiTransfer *fromJsonObject(QJsonObject jsonData);

    string getUsername();
    string getOpponentUsername();

    int getCurrentPlayer();
    int getOpponentPlayer();
};

#endif // CHESSAPPLICATION_MULTIPLAYERCHESSGUITRANSFER_H
