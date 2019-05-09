#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include <QTcpServer>
#include <QDebug>
#include <QString>
#include <time.h>
#include <algorithm>
#include "housechooser.h"
#include "cardservice.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    QTcpServer* getServer();
    
    void setDifficulty(QString diff);    
    QString getDifficulty();    
    void setMaxPlayers(int max);
    int getMaxPlayers();
    
signals:
    void allHolded();
    void tooFewCards();
    
public slots:
    void acceptConnection();
    void startRead();
    void onDisconnect();
    void announceWinner();
    void shuffle();
    void houseGetCards(int total);
    
private:
    QTcpServer* _server;
    CardService* _service;
    QString _difficulty;
    
    QMap<QTcpSocket*,QString> _clients; //connection and username
    QList<QString> _holdedPlayers; //keeps track of both holded and lost players
    
    QMap<QString, int> _currentPlayerTotal;
    
    int _pressedDealAgain; //number of players ready for new game
    int _numberOfConnections; //how many players have connected so far
    int _maxPlayers; //how many players can connect
    
    //decks used for playing
    QStringList _deck;
    QStringList _cards;
   
    //methods
    void removeClient(QTcpSocket *s);
    void sendCards();
    HouseChooser* createHouseChooser();
    void calculateCurrentTotal(QString card, QString username);
    void initializeCards();
    void reset();
    void writeToSocket(QTcpSocket *socket, QString message, QString qDebugMsg);
    void addToHolded(QTcpSocket *socket);
};

#endif // SERVER_H
