#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QAbstractSocket>
#include "QVBoxLayout"

using namespace std;
using namespace std::chrono_literals;

class QListWidget;
class QVBoxLayout;
class QJsonObject;
class MultiplayerGuiDataHolder;
class MultiplayerFacade;
class MultiplayerGuiModelCreator;

class LobbyRenderer {
private:
    MultiplayerGuiDataHolder *multiplayerGuiDataHolder;
    MultiplayerFacade *multiplayerFacade;
    MultiplayerGuiModelCreator *multiplayerGuiModelCreator;

protected:
    QJsonObject getLobbyData();

    QWidget *createLobbyJoinButtonWidget(string userIdentifier);

public:
    LobbyRenderer(
        MultiplayerGuiDataHolder *multiplayerGuiDataHolder,
        MultiplayerFacade *multiplayerFacade,
        MultiplayerGuiModelCreator *multiplayerGuiModelCreator
    );

    ~LobbyRenderer();

    QVBoxLayout *createMultiplayerLobbyLayout();

    QString showUsernameDialog(QWidget *widget);

    void showMultiplayerLobby();
    void fillLobbyListWithData(QJsonObject lobbyData);
    void refreshLobbyList();

private slots:
    void attemptConnection();
    void connectedToServer();
    void loggedIn();
    void loginFailed(const QString &reason);
    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void userJoined(const QString &username);
    void userLeft(const QString &username);
    void error(QAbstractSocket::SocketError socketError);
};

#endif // CHATWINDOW_H
