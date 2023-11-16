//
// Created by Julian Sommer on 09.11.23.
//

#ifndef CHESSAPPLICATION_CHESSCLIENTRESPONSEDELEGATOR_H
#define CHESSAPPLICATION_CHESSCLIENTRESPONSEDELEGATOR_H

#include <string>

using namespace std;

class ChessFacade;
class ChessGuiFacade;
class QJsonObject;

class ChessClientResponseDelegator {
private:
    ChessFacade *chessFacade;
    ChessGuiFacade *chessGuiFacade;

public:
    ChessClientResponseDelegator(
      ChessFacade *chessFacade,
      ChessGuiFacade *chessGuiFacade
    );

    void handleEndTurnData(QJsonObject jsonData);
    void startMultiplayerGame(QJsonObject jsonData);

    void delegateChessClientResponse(string responseType, QJsonObject jsonData);
};

#endif // CHESSAPPLICATION_CHESSCLIENTRESPONSEDELEGATOR_H
