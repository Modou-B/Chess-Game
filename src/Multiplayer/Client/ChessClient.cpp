//
// Created by Julian Sommer on 27.10.23.
//

#include "ChessClient.h"
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QTcpSocket>
#include <iostream>
#include "ChessClientResponseDelegator.h"

ChessClient::ChessClient(
    ChessClientResponseDelegator *chessClientResponseDelegator,
    QObject *parent
): QObject(parent) {
    this->clientSocket = new QTcpSocket(this);
    this->chessClientResponseDelegator = chessClientResponseDelegator;
    this->loggedIn = false;
    // Forward the connected and disconnected signals
    connect(this->clientSocket, &QTcpSocket::connected, this, &ChessClient::connected);
    connect(this->clientSocket, &QTcpSocket::disconnected, this, &ChessClient::disconnected);
    connect(this->clientSocket, &QTcpSocket::readyRead, this, &ChessClient::onReadyRead);
    // Forward the error signal, QOverload is necessary as error() is overloaded, see the Qt docs
    this->clientSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);

    connect(this->clientSocket, &QAbstractSocket::errorOccurred, this, &ChessClient::error);
    // Reset the m_loggedIn variable when we disconnec. Since the operation is trivial we use a lambda instead of creating another slot
    connect(this->clientSocket, &QTcpSocket::disconnected, this, [this]()->void{ this->loggedIn = false;});
}

QTcpSocket *ChessClient::getClientSocket() {
    return this->clientSocket;
}

void ChessClient::login(const QString &userName)
{
    if (this->clientSocket->state() == QAbstractSocket::ConnectedState) { // if the client is connected
        // create a QDataStream operating on the socket
        QDataStream clientStream(this->clientSocket);
        // set the version so that programs compiled with different versions of Qt can agree on how to serialise
        clientStream.setVersion(QDataStream::Qt_6_5);
        // Create the JSON we want to send
        QJsonObject message;
        std::cout << userName.toStdString() << std::endl;
        message[QStringLiteral("type")] = QStringLiteral("setUsername");
        message[QStringLiteral("username")] = userName;
        // send the JSON using QDataStream
        clientStream << QJsonDocument(message).toJson(QJsonDocument::Compact);
    }
}

void ChessClient::disconnectFromHost()
{
    this->clientSocket->disconnectFromHost();
}


void ChessClient::connectToServer()
{
    this->clientSocket->connectToHost(QHostAddress("127.0.0.1"), 1999);
}

void ChessClient::onReadyRead()
{
    // prepare a container to hold the UTF-8 encoded JSON we receive from the socket
    QByteArray jsonData;
    // create a QDataStream operating on the socket
    QDataStream socketStream(this->clientSocket);
    // set the version so that programs compiled with different versions of Qt can agree on how to serialise
    socketStream.setVersion(QDataStream::Qt_6_5);
    // start an infinite loop
    for (;;) {
        // we start a transaction so we can revert to the previous state in case we try to read more data than is available on the socket
        socketStream.startTransaction();
        // we try to read the JSON data
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            // we successfully read some data
            // we now need to make sure it's in fact a valid JSON
            QJsonParseError parseError;
            // we try to create a json document with the data we received
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

            std::cout << jsonDoc.toJson(QJsonDocument::Indented).toStdString() << std::endl;
            if (parseError.error == QJsonParseError::NoError) {
                // if the data was indeed valid JSON
                if (jsonDoc.isObject()) {
                    auto responseType = jsonDoc.object().value(QLatin1String("responseType")).toString().toStdString();

                    this->mappedResponseData[responseType] = jsonDoc.object();

                    this->chessClientResponseDelegator->delegateChessClientResponse(responseType, jsonDoc.object());
                } // and is a JSON object
                    //jsonReceived(jsonDoc.object()); // parse the JSON
            }
            // loop and try to read more JSONs if they are available
        } else {
            QJsonParseError parseError;
            // we try to create a json document with the data we received
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            std::cout << jsonDoc.toJson(QJsonDocument::Indented).toStdString() << std::endl;

            // the read failed, the socket goes automatically back to the state it was in before the transaction started
            // we just exit the loop and wait for more data to become available
            break;
        }
    }
}

void ChessClient::error(QAbstractSocket::SocketError socketError)
{
    // show a message to the user that informs of what kind of error occurred
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::ProxyConnectionClosedError:
        return; // handled by disconnectedFromServer
    case QAbstractSocket::ConnectionRefusedError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::ProxyNotFoundError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::HostNotFoundError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::SocketAccessError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::SocketResourceError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::SocketTimeoutError:
        std::cout << "The host refused the connection" << std::endl;
        return;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::NetworkError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::UnknownSocketError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::ProxyProtocolError:
        std::cout << "The host refused the connection" << std::endl;
        break;
    case QAbstractSocket::TemporaryError:
    case QAbstractSocket::OperationError:
        std::cout << "The host refused the connection" << std::endl;
        return;
    default:
        Q_UNREACHABLE();
    }
}

void ChessClient::sendRequest(QJsonObject jsonData) {
     if (this->clientSocket->state() == QAbstractSocket::ConnectedState) {
        QDataStream clientStream(this->clientSocket);
        clientStream.setVersion(QDataStream::Qt_6_5);

        clientStream << QJsonDocument(jsonData).toJson(QJsonDocument::Compact);
    }
}

QJsonObject ChessClient::getResponse(string requestType)
{
    this->clientSocket->waitForReadyRead(250);

    return this->mappedResponseData[requestType];
}
