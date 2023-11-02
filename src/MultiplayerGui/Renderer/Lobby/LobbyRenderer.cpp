#include "LobbyRenderer.h"
#include "iostream"
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>
#include <QListWidget>
#include "../../Model/Button/LobbyCreateButton.h"
#include "../../Model/Button/LobbyJoinButton.h"
#include "../../Model/Button/RefreshLobbyButton.h"
#include "../../Model/MultiplayerGuiModelCreator.h"
#include "../DataHolder/MultiplayerGuiDataHolder.h"
#include <QJsonObject>
#include <QJsonArray>
#include "../../../Multiplayer/MultiplayerFacade.h"

LobbyRenderer::LobbyRenderer(
    MultiplayerGuiDataHolder *multiplayerGuiDataHolder,
    MultiplayerFacade *multiplayerFacade,
    MultiplayerGuiModelCreator *multiplayerGuiModelCreator
) {
    this->multiplayerGuiDataHolder = multiplayerGuiDataHolder;
    this->multiplayerFacade = multiplayerFacade;
    this->multiplayerGuiModelCreator = multiplayerGuiModelCreator;
}

LobbyRenderer::~LobbyRenderer()
{
}

QString LobbyRenderer::showUsernameDialog(QWidget *widget)
{
    // once we connected to the server we ask the user for what username they would like to use
    return QInputDialog::getText(widget, QString::fromStdString("Chose Username"), QString::fromStdString("Username"));
}

QVBoxLayout *LobbyRenderer::createMultiplayerLobbyLayout() {
    auto *lobbyLayout = new QVBoxLayout();
    auto *lobbyRooms = new QListWidget();
    auto *lobbyButton = this->multiplayerGuiModelCreator->createLobbyCreateButton();
    auto *refreshButton = this->multiplayerGuiModelCreator->createRefreshLobbyButton();

    lobbyLayout->addWidget(lobbyRooms);
    lobbyLayout->addWidget(lobbyButton);
    lobbyLayout->addWidget(refreshButton);

    lobbyRooms->hide();
    lobbyButton->hide();
    refreshButton->hide();

    this->multiplayerGuiDataHolder->saveLobbyLayout(lobbyLayout);

    return lobbyLayout;
}

void LobbyRenderer::showMultiplayerLobby() {
    auto *lobbyLayout = this->multiplayerGuiDataHolder->getLobbyLayout();

    lobbyLayout->itemAt(0)->widget()->show();
    lobbyLayout->itemAt(1)->widget()->show();
    lobbyLayout->itemAt(2)->widget()->show();
}

void LobbyRenderer::fillLobbyListWithData(QJsonObject lobbyData) {
    auto *lobbyLayout = this->multiplayerGuiDataHolder->getLobbyLayout();

    QListWidget *lobbyRoomsWidget = static_cast<QListWidget *>(lobbyLayout->itemAt(0)->widget());

    for (auto userLobbies : lobbyData["lobbyData"].toArray()) {
        auto userIdentifier = userLobbies[QLatin1String("userIdentifier")].toString().toStdString();
        auto username = userLobbies[QLatin1String("username")].toString();

        auto *joinButton = this->createLobbyJoinButtonWidget(userIdentifier);

        auto *listItem = new QListWidgetItem();
        listItem->setText(username);
        listItem->setSizeHint(joinButton->sizeHint());

        lobbyRoomsWidget->addItem(listItem);
        lobbyRoomsWidget->setItemWidget(listItem, joinButton);
    }
}

void LobbyRenderer::refreshLobbyList() {
    auto lobbyData = this->getLobbyData();

    if (!lobbyData.empty()) {
        this->fillLobbyListWithData(lobbyData);
    }
}

QJsonObject LobbyRenderer::getLobbyData() {
    QJsonObject json;
    json[QStringLiteral("requestType")] = QStringLiteral("getLobbyData");

    return this->multiplayerFacade->requestJsonDataFromServer(json);
}

QWidget *LobbyRenderer::createLobbyJoinButtonWidget(string userIdentifier)
{
    auto *joinLobbyButton = this->multiplayerGuiModelCreator->createLobbyJoinButton(userIdentifier);

    joinLobbyButton->setText("join Lobby");
    joinLobbyButton->setMaximumWidth(80);
    joinLobbyButton->setMinimumHeight(24);

    auto *hBoxButtonLayout = new QHBoxLayout();
    hBoxButtonLayout->addWidget(joinLobbyButton, Qt::AlignRight);
    hBoxButtonLayout->setContentsMargins(0,0,0,0);

    auto *joinLobbyButtonWidget = new QWidget();
    joinLobbyButtonWidget->setLayout(hBoxButtonLayout);

    return joinLobbyButtonWidget;
}
/*
void LobbyRenderer::loginFailed(const QString &reason)
{
    // the server rejected the login attempt
    // display the reason for the rejection in a message box
    QMessageBox::critical(this, tr("Error"), reason);
    // allow the user to retry, execute the same slot as when just connected
    connectedToServer();
}
*/
/*
void LobbyRenderer::messageReceived(const QString &sender, const QString &text)
{
    // store the index of the new row to append to the model containing the messages
    int newRow = m_chatModel->rowCount();
    // we display a line containing the username only if it's different from the last username we displayed
    if (m_lastUserName != sender) {
        // store the last displayed username
        m_lastUserName = sender;
        // create a bold default font
        QFont boldFont;
        boldFont.setBold(true);
        // insert 2 row, one for the message and one for the username
        m_chatModel->insertRows(newRow, 2);
        // store the username in the model
        m_chatModel->setData(m_chatModel->index(newRow, 0), sender + QLatin1Char(':'));
        // set the alignment for the username
        m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
        // set the for the username
        m_chatModel->setData(m_chatModel->index(newRow, 0), boldFont, Qt::FontRole);
        ++newRow;
    } else {
        // insert a row for the message
        m_chatModel->insertRow(newRow);
    }
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
}
*/
/*
void LobbyRenderer::sendMessage()
{
    // we use the client to send the message that the user typed
    m_chatClient->sendMessage(ui->messageEdit->text());
    // now we add the message to the list
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row for the message
    m_chatModel->insertRow(newRow);
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->messageEdit->text());
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // clear the content of the message editor
    ui->messageEdit->clear();
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();
}
*/
/*
void LobbyRenderer::disconnectedFromServer()
{
    // if the client loses connection to the server
    // comunicate the event to the user via a message box
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // reset the last printed username
    m_lastUserName.clear();
}
*/
/*
void LobbyRenderer::userJoined(const QString &username)
{
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row
    m_chatModel->insertRow(newRow);
    // store in the model the message to comunicate a user joined
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Joined the Chat").arg(username));
    // set the alignment for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    // set the color for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();
}
*/
/*
void LobbyRenderer::userLeft(const QString &username)
{
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row
    m_chatModel->insertRow(newRow);
    // store in the model the message to comunicate a user left
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Left the Chat").arg(username));
    // set the alignment for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    // set the color for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::red), Qt::ForegroundRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();
}
*/

/*
void LobbyRenderer::error(QAbstractSocket::SocketError socketError)
{
    // show a message to the user that informs of what kind of error occurred
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::ProxyConnectionClosedError:
        return; // handled by disconnectedFromServer
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
        break;
    case QAbstractSocket::ProxyNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
        break;
    case QAbstractSocket::SocketAccessError:
        QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
        break;
    case QAbstractSocket::SocketResourceError:
        QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
        break;
    case QAbstractSocket::SocketTimeoutError:
        QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
        return;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
        break;
    case QAbstractSocket::NetworkError:
        QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
        break;
    case QAbstractSocket::UnknownSocketError:
        QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
        break;
    case QAbstractSocket::ProxyProtocolError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
        break;
    case QAbstractSocket::TemporaryError:
    case QAbstractSocket::OperationError:
        QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
        return;
    default:
        Q_UNREACHABLE();
    }
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    // reset the last printed username
    m_lastUserName.clear();
}
*/