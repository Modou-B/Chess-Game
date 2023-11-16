//
// Created by Julian Sommer on 27.10.23.
//

#ifndef CHESSAPPLICATION_CHESSCLIENT_H
#define CHESSAPPLICATION_CHESSCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>

using namespace std;

class QHostAddress;
class QJsonDocument;
class QJsonObject;
class ChessClientResponseDelegator;

class ChessClient : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(ChessClient)

private:
    QTcpSocket *clientSocket;
    ChessClientResponseDelegator *chessClientResponseDelegator;

    bool loggedIn;
    map<string, QJsonObject> mappedResponseData;

protected:
    void onReadyRead();

public:
    ChessClient(
      ChessClientResponseDelegator *chessClientResponseDelegator,
      QObject *parent = nullptr
    );

    QTcpSocket *getClientSocket();
    void connectToServer();
    void error(QAbstractSocket::SocketError socketError);

    void sendRequest(QJsonObject jsonData);
    QJsonObject getResponse(string requestType);

public slots:
    void login(const QString &userName);
    void disconnectFromHost();

signals:
    void connected();
    void loginError(const QString &reason);
    void disconnected();
    void messageReceived(const QString &sender, const QString &text);
    void userJoined(const QString &username);
    void userLeft(const QString &username);

};

#endif // CHESSAPPLICATION_CHESSCLIENT_H
