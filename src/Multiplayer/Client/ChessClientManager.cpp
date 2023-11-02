//
// Created by Julian Sommer on 27.10.23.
//

#include "ChessClientManager.h"
#include "ChessClient.h"
#include <QJsonObject>
#include <QJsonParseError>
#include "iostream"
#include "../../Chess/ChessFacade.h"

ChessClient *ChessClientManager::chessClient = nullptr;

ChessClientManager::ChessClientManager(
    ChessFacade *chessFacade
) {
    this->chessFacade = chessFacade;
}

void ChessClientManager::initializeChessClient() {
    ChessClientManager::chessClient = new ChessClient();

    ChessClientManager::chessClient->connectToServer();
}

void ChessClientManager::sendJsonData(QJsonObject jsonData) {
    ChessClientManager::chessClient->sendRequest(jsonData);
}

QJsonObject ChessClientManager::requestJsonData(QJsonObject jsonData) {
    ChessClientManager::chessClient->sendRequest(jsonData);

    return ChessClientManager::chessClient
        ->getResponse(
            jsonData.value(QLatin1String("requestType"))
                .toString()
                .toStdString()
            );
}

void ChessClientManager::handleMultiplayerLobbyJoin()
{
    std::cout << "We are gere" << std::endl;

    this->chessFacade->initiateMultiplayerChessGame(
        ChessClientManager::chessClient->getResponse("startChessMatch")
    );
}

/*
void ChessClientManager::jsonReceived(const QJsonObject &docObj)
{
    // actions depend on the type of message
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return; // a message with no type was received so we just ignore it
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) == 0) { //It's a login message
        if (this->loggedIn)
            return; // if we are already logged in we ignore
        // the success field will contain the result of our attempt to login
        const QJsonValue resultVal = docObj.value(QLatin1String("success"));
        if (resultVal.isNull() || !resultVal.isBool())
            return; // the message had no success field so we ignore
        const bool loginSuccess = resultVal.toBool();
        if (loginSuccess) {
            // we logged in succesfully and we notify it via the loggedIn signal
            //emit loggedIn();
            return;
        }
        // the login attempt failed, we extract the reason of the failure from the JSON
        // and notify it via the loginError signal
        const QJsonValue reasonVal = docObj.value(QLatin1String("reason"));
        emit loginError(reasonVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) == 0) { //It's a chat message
        // we extract the text field containing the chat text
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        // we extract the sender field containing the username of the sender
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (textVal.isNull() || !textVal.isString())
            return; // the text field was invalid so we ignore
        if (senderVal.isNull() || !senderVal.isString())
            return; // the sender field was invalid so we ignore
        // we notify a new message was received via the messageReceived signal
        emit messageReceived(senderVal.toString(), textVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("newuser"), Qt::CaseInsensitive) == 0) { // A user joined the chat
        // we extract the username of the new user
        const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
        if (usernameVal.isNull() || !usernameVal.isString())
            return; // the username was invalid so we ignore
        // we notify of the new user via the userJoined signal
        emit userJoined(usernameVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("userdisconnected"), Qt::CaseInsensitive) == 0) { // A user left the chat
         // we extract the username of the new user
        const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
        if (usernameVal.isNull() || !usernameVal.isString())
            return; // the username was invalid so we ignore
        // we notify of the user disconnection the userLeft signal
        emit userLeft(usernameVal.toString());
    }
}
 */