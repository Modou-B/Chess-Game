#ifndef CHESSSERVER_H
#define CHESSSERVER_H

#include <QTcpServer>
#include <QVector>

using namespace std;

class ServerWorker;
class ChessServer : public QTcpServer {
  Q_OBJECT
private:
    void jsonFromLoggedOut(ServerWorker *sender, const QJsonObject &doc);
    void jsonFromLoggedIn(ServerWorker *sender, const QJsonObject &doc);
    void sendJson(ServerWorker *destination, const QJsonObject &message);

    QVector<ServerWorker *> connectedClients;
    map<string, ServerWorker *> clientsInLobby;
    map<string, ServerWorker *> clientsInGame;

protected:
    void incomingConnection(qintptr socketDescriptor) override;

    void routeReceivedJson(ServerWorker *sender, const QJsonObject &json);
    void setClientUsername(ServerWorker *sender, const QJsonObject &json);
    void startChessMatch(ServerWorker *sender, const QJsonObject &json);

    void addClientToLobby(ServerWorker *sender);
    void sendLobbyData(ServerWorker *sender);

    void sendChessMatchStartData(ServerWorker *playerClient1, ServerWorker *playerClient2);
    void sendEndTurnData(ServerWorker *sender, const QJsonObject &json);
public:
    explicit ChessServer(QObject *parent = nullptr);


signals:
    void logMessage(const QString &msg);
public slots:
    void stopServer();
private slots:
    void broadcast(const QJsonObject &message, ServerWorker *exclude);
    void jsonReceived(ServerWorker *sender, const QJsonObject &doc);
    void userDisconnected(ServerWorker *sender);
    void userError(ServerWorker *sender);
};

#endif // CHESSSERVER_H
