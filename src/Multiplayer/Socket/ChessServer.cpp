#include "ChessServer.h"
#include "serverworker.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QThread>
#include <QTimer>
#include <functional>
#include <QRandomGenerator>
#include "iostream"
#include <QJsonArray>
ChessServer::ChessServer(QObject *parent)
    : QTcpServer(parent)
{}

void ChessServer::incomingConnection(qintptr socketDescriptor)
{
    ServerWorker *worker = new ServerWorker(this);
    if (!worker->setSocketDescriptor(socketDescriptor)) {
        worker->deleteLater();
        return;
    }

    connect(worker, &ServerWorker::disconnectedFromClient, this, std::bind(&ChessServer::userDisconnected, this, worker));
    connect(worker, &ServerWorker::error, this, std::bind(&ChessServer::userError, this, worker));
    connect(worker, &ServerWorker::jsonReceived, this, std::bind(&ChessServer::jsonReceived, this, worker, std::placeholders::_1));
    connect(worker, &ServerWorker::logMessage, this, &ChessServer::logMessage);
    connectedClients.append(worker);

    emit logMessage(QStringLiteral("New client Connected"));
}
void ChessServer::sendJson(ServerWorker *destination, const QJsonObject &message)
{
    Q_ASSERT(destination);
    destination->sendJson(message);
}
void ChessServer::broadcast(const QJsonObject &message, ServerWorker *exclude)
{
    for (ServerWorker *worker : connectedClients) {
        Q_ASSERT(worker);
        if (worker == exclude)
            continue;
        sendJson(worker, message);
    }
}

void ChessServer::jsonReceived(ServerWorker *sender, const QJsonObject &doc)
{
    Q_ASSERT(sender);

    std::cout << "JSON received " <<  QString::fromUtf8(QJsonDocument(doc).toJson()).toStdString() <<std::endl;

    emit logMessage(QLatin1String("JSON received ") + QString::fromUtf8(QJsonDocument(doc).toJson()));

    this->routeReceivedJson(sender, doc);
}

void ChessServer::routeReceivedJson(ServerWorker *sender, const QJsonObject &json) {
    const auto messageType = json.value(QLatin1String("requestType"));

    if (messageType.isNull() || !messageType.isString()) {
        return;
    }

    if (messageType.toString().compare(QLatin1String("setUsername"), Qt::CaseInsensitive) == 0) {
        this->setClientUsername(sender, json);
    }

    if (messageType.toString().compare(QLatin1String("openLobby"), Qt::CaseInsensitive) == 0) {
        this->addClientToLobby(sender);
    }

    if (messageType.toString().compare(QLatin1String("joinOpenLobby"), Qt::CaseInsensitive) == 0) {
        this->startChessMatch(sender, json);
    }

    if (messageType.toString().compare(QLatin1String("getLobbyData"), Qt::CaseInsensitive) == 0) {
        this->sendLobbyData(sender);
    }
}

void ChessServer::setClientUsername(ServerWorker *sender, const QJsonObject &json)
{
    if (!sender->getUsername().isEmpty()) {
        return;
    }

    auto username = json.value(QLatin1String("username"));
    std::cout << username.toString().toStdString() << std::endl;

    sender->setUserName(username.toString());

    std::cout << sender->getUsername().toStdString() << std::endl;

    sender->setUserIdentifier(to_string(QRandomGenerator::global()->generate()));
}

void ChessServer::addClientToLobby(ServerWorker *sender) {
    this->clientsInLobby[sender->getUserIdentifier()] = sender;
}

void ChessServer::sendLobbyData(ServerWorker *sender) {
    QJsonObject lobbyData;
    lobbyData[QStringLiteral("responseType")] = QStringLiteral("getLobbyData");

    QJsonArray lobbyDataArray;
    for (auto lobbyClients : this->clientsInLobby) {
        QJsonObject data;
        data[QStringLiteral("userIdentifier")] = QString::fromStdString(lobbyClients.first);
        data[QStringLiteral("username")] = lobbyClients.second->getUsername();

        lobbyDataArray.append(data);
    }

    lobbyData[QStringLiteral("lobbyData")] = lobbyDataArray;

    sender->sendJson(lobbyData);
}

void ChessServer::startChessMatch(ServerWorker *sender, const QJsonObject &json) {
    auto opponentClientUserIdentifier = json.value(QLatin1String("opponentIdentifier")).toString().toStdString();

    sender->setOpponentIdentifier(opponentClientUserIdentifier);
    sender->setInMatchStatus(true);

    auto opponentClient = this->clientsInLobby[opponentClientUserIdentifier];
    opponentClient->setOpponentIdentifier(sender->getUserIdentifier());
    opponentClient->setInMatchStatus(true);

    this->sendChessMatchStartData(sender, opponentClient);

    this->clientsInLobby.erase(opponentClientUserIdentifier);
}

void ChessServer::sendChessMatchStartData(
    ServerWorker *playerClient1,
    ServerWorker *playerClient2
) {
    std::cout << "send Chess Start Data" << std::endl;
    QJsonObject chessMatchStartData;
    chessMatchStartData[QStringLiteral("responseType")] = QStringLiteral("startChessMatch");
    chessMatchStartData[QStringLiteral("player")] = 1;
    chessMatchStartData[QStringLiteral("playerName")] = playerClient1->getUsername();
    chessMatchStartData[QStringLiteral("opponentPlayer")] = 2;
    chessMatchStartData[QStringLiteral("opponentPlayerName")] = playerClient2->getUsername();

    playerClient1->sendJson(chessMatchStartData);
    std::cout << playerClient1->getUsername().toStdString() << std::endl;

    chessMatchStartData[QStringLiteral("player")] = 2;
    chessMatchStartData[QStringLiteral("playerName")] = playerClient2->getUsername();
    chessMatchStartData[QStringLiteral("opponentPlayer")] = 1;
    chessMatchStartData[QStringLiteral("opponentPlayerName")] = playerClient1->getUsername();

    playerClient2->sendJson(chessMatchStartData);
    std::cout << playerClient2->getUsername().toStdString() << std::endl;

    std::cout << "End" << std::endl;

}

void ChessServer::userDisconnected(ServerWorker *sender)
{
    Q_ASSERT(sender);

    connectedClients.removeAll(sender);
    const QString userName = sender->userName();
    if (!userName.isEmpty()) {
        QJsonObject disconnectedMessage;
        disconnectedMessage[QStringLiteral("type")] = QStringLiteral("userdisconnected");
        disconnectedMessage[QStringLiteral("username")] = userName;
        broadcast(disconnectedMessage, nullptr);
        emit logMessage(userName + QLatin1String(" disconnected"));
    }

    sender->deleteLater();
}

void ChessServer::userError(ServerWorker *sender)
{
    Q_UNUSED(sender)
    emit logMessage(QLatin1String("Error from ") + sender->userName());
}

void ChessServer::stopServer()
{
    for (ServerWorker *worker : connectedClients) {
        worker->disconnectFromClient();
    }
    close();
}

void ChessServer::jsonFromLoggedOut(ServerWorker *sender, const QJsonObject &docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
    if (usernameVal.isNull() || !usernameVal.isString())
        return;
    const QString newUserName = usernameVal.toString().simplified();
    if (newUserName.isEmpty())
        return;
    for (ServerWorker *worker : qAsConst(connectedClients)) {
        if (worker == sender)
            continue;
        if (worker->userName().compare(newUserName, Qt::CaseInsensitive) == 0) {
            QJsonObject message;
            message[QStringLiteral("type")] = QStringLiteral("login");
            message[QStringLiteral("success")] = false;
            message[QStringLiteral("reason")] = QStringLiteral("duplicate username");
            sendJson(sender, message);
            return;
        }
    }

    sender->setUserName(newUserName);
    QJsonObject successMessage;
    successMessage[QStringLiteral("type")] = QStringLiteral("login");
    successMessage[QStringLiteral("success")] = true;
    sendJson(sender, successMessage);
    QJsonObject connectedMessage;
    connectedMessage[QStringLiteral("type")] = QStringLiteral("newuser");
    connectedMessage[QStringLiteral("username")] = newUserName;

    broadcast(connectedMessage, sender);
}

void ChessServer::jsonFromLoggedIn(ServerWorker *sender, const QJsonObject &docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue textVal = docObj.value(QLatin1String("text"));
    if (textVal.isNull() || !textVal.isString())
        return;
    const QString text = textVal.toString().trimmed();
    if (text.isEmpty())
        return;
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("message");
    message[QStringLiteral("text")] = text;
    message[QStringLiteral("sender")] = sender->userName();
    broadcast(message, sender);
}


