#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include <QTcpSocket>

using namespace std;

class QJsonObject;
class ServerWorker : public QObject {
  Q_OBJECT
public:
    explicit ServerWorker(QObject *parent = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    QString userName() const;
    void sendJson(const QJsonObject &jsonData);

    void setUserName(const QString &userName);
    void setUserIdentifier(string userIdentifier);
    void setInMatchStatus(bool isInMatch);
    void setOpponentIdentifier(string opponentIdentifier);

    QString getUsername();
    string getUserIdentifier();
    bool getInMatchStatus();
    string getOpponentIdentifier();
signals:
    void jsonReceived(const QJsonObject &jsonDoc);
    void disconnectedFromClient();
    void error();
    void logMessage(const QString &msg);
public slots:
    void disconnectFromClient();
private slots:
    void receiveJson();
private:
    QTcpSocket *m_serverSocket;
    QString username;
    string userIdentifier;

    bool isInMatch;
    string opponentIdentifier;


};

#endif // SERVERWORKER_H
