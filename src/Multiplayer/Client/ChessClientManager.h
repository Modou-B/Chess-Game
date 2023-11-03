//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_CHESSCLIENTMANAGER_H
#define CHESSAPPLICATION_CHESSCLIENTMANAGER_H

class ChessClient;
class QJsonObject;
class ChessFacade;

class ChessClientManager {
private:
    static ChessClient *chessClient;

    ChessFacade *chessFacade;

    void jsonReceived(const QJsonObject &doc);

public:
    ChessClientManager(
        ChessFacade *chessFacade
    );

    void initializeChessClient();
    void sendJsonData(QJsonObject jsonData);

    QJsonObject requestJsonData(QJsonObject jsonData);
    void handleMultiplayerLobbyJoin();
};

#endif // CHESSAPPLICATION_CHESSCLIENTMANAGER_H
