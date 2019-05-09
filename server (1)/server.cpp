#include "server.h"

Server::Server(QObject* parent) : 
    QObject(parent),
    _pressedDealAgain(0),
    _numberOfConnections(0)
{
    _server = new QTcpServer(this);
    connect(_server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    connect(this, SIGNAL(tooFewCards()), this, SLOT(shuffle()));
    connect(this, SIGNAL(allHolded()), this, SLOT(announceWinner()));
        
    if(!_server->listen(QHostAddress::Any, 53413)){
        qDebug() << "Server is off.";
    } 
    else{
        qDebug() << "Server is on.";
    }
    
    initializeCards();
    _currentPlayerTotal["House"] = 0;
}


void Server::announceWinner()
{
    int max = 0;
    QString winner;    
    
    //check which player (both human and house) has most points
    for(QString p : _currentPlayerTotal.keys()){
        if(_currentPlayerTotal[p] > max && _currentPlayerTotal[p] < 22){
            if(_currentPlayerTotal[p] == 21){ 
                winner = p + " won";
                max = 21;
                break;
            }
                
            max = _currentPlayerTotal[p];
            winner = p + " won";
        }
    }    
    
    //if more than 1 player has max announce a tie
    if(_currentPlayerTotal.values().count(max) >= 2)
        winner = "Tie!";
    
    //if after all those if's no one won, announce it
    if(winner.compare("") == 0)
        winner = "Everyone lost";
    
    for(auto e : _clients.keys())
        writeToSocket(e, winner + "\n", "Player notified about the result");
    
    //reset everything    
    reset();
    
    //house gets cards first
    HouseChooser *chooser = createHouseChooser();
    chooser->start();
}


void Server::sendCards()
{
    //generate 2 cards at the start of each game for all users
    QString card;
    for(auto i = 0; i < 2; i++){
        
        for(auto e : _clients.keys()){
            card = _service->pickCard();    
             
            if(card.compare("Deck is empty!") != 0)
                calculateCurrentTotal(card, _clients[e]);
            
            writeToSocket(e, card + "\n", "Card sent");
        } //end for sockets
        
   } //end for
        
    //make sure there are enough cards before next hit/deal!
    if(_deck.size() <= 10)
        emit tooFewCards();
}


void Server::calculateCurrentTotal(QString card, QString username)
{
    QString c = card.split(" ")[0]; //this returns J for example
    
    _currentPlayerTotal[username] += _service->cardValue(c, _currentPlayerTotal[username]);
}


void Server::startRead()
{
    QTcpSocket* socket = (QTcpSocket*)sender();

    //client always writes a single line, so no need for while(canReadLines)
    QString line = QString::fromUtf8(socket->readLine()).trimmed();
    
    if(line.compare("Hit") == 0){      
        QString card;
        card = _service->pickCard();             
        
        if(card.compare("Deck is empty!") != 0)
            calculateCurrentTotal(card, _clients[socket]);
        
        writeToSocket(socket, card + "\n", "Card sent");
        
        //check if player lost and add him to the list of lost/holded players 
        if(_currentPlayerTotal[_clients[socket]] > 21)       
            addToHolded(socket);
        
        if(_deck.size() <= 10)
            emit tooFewCards();   
        
    } //end if hit
    else if(line.compare("Hold") == 0){  
        addToHolded(socket);
        
    } //end if hold
    else if(line.compare("Deal again") == 0){
        _pressedDealAgain++;
        if(_pressedDealAgain == _numberOfConnections)
            sendCards();          
        
    } //end if deal again
    else{
        _clients[socket] = line;
        qDebug() << "User" << line << "connected";
        _numberOfConnections++;
        _currentPlayerTotal.insert(line, 0);        
        
        if(_numberOfConnections == _maxPlayers){
            HouseChooser *chooser = createHouseChooser();
            chooser->start();
            
            sendCards();
        }
        
    } //end if send username
     
}


void Server::addToHolded(QTcpSocket *socket)
{
    _holdedPlayers.append(_clients[socket]);
    if(_holdedPlayers.size() == _maxPlayers)
        emit allHolded();    
}

void Server::initializeCards()
{
    //all possible cards
    _cards << "A" << "2" << "3" << "4" << "5"
           << "6" << "7" << "8" << "9" << "10"
           << "J" << "Q" << "K";
    
    for(auto i = _cards.cbegin(); i != _cards.cend(); i++){
        QString tmpSpades = (*i) + " spades";
        QString tmpHearts = (*i) + " hearts";
        QString tmpDiamonds = (*i) + " diamonds";
        QString tmpClubs = (*i) + " clubs";
                
        _deck.push_back(tmpSpades);
        _deck.push_back(tmpHearts);
        _deck.push_back(tmpDiamonds);
        _deck.push_back(tmpClubs);
    }
    
    //we want more randomness!
    std::random_shuffle(_deck.begin(), _deck.end());
    _service = new CardService(&_deck, this);
}


void Server::shuffle()
{
    qDebug() << "SHUFFLING";
    
    _cards.clear();
    _deck.clear();
    initializeCards();
}


HouseChooser* Server::createHouseChooser()
{
    HouseChooser *chooser = new HouseChooser(&_deck, _difficulty, this);
    connect(chooser, SIGNAL(resultReady(int)), this, SLOT(houseGetCards(int)));    
    connect(chooser, SIGNAL(finished()), chooser, SLOT(deleteLater()));

    return chooser;    
}


void Server::houseGetCards(int total)
{
    _currentPlayerTotal["House"] = total;
    
    if(_deck.size() <= 10)
        emit tooFewCards();
    
    qDebug() << "Current house total: " << total;
}


void Server::writeToSocket(QTcpSocket *socket, QString message, QString qDebugMsg)
{
    socket->write(message.toUtf8()); 
    socket->flush();
    if(!socket->waitForBytesWritten(10000))
        qDebug() << qDebugMsg;    
}


void Server::reset()
{
    for(QString p : _currentPlayerTotal.keys())
        _currentPlayerTotal[p] = 0;
    _holdedPlayers.clear(); 
    _pressedDealAgain = 0;  
}


//when player connects
void Server::acceptConnection()
{
    QTcpSocket* socket = _server->nextPendingConnection();
    qDebug() << "Client connected: " << socket->peerAddress().toString();

    connect(socket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    
    _clients.insert(socket, ""); 
}


//when player disconnects, remove from map
void Server::onDisconnect()
{
    QTcpSocket* socket = (QTcpSocket*)sender();
    qDebug() << "Client disconnected: " << _clients[socket];
    
    removeClient(socket);
}

void Server::removeClient(QTcpSocket *s)
{
    _currentPlayerTotal.remove(_clients[s]);
    _holdedPlayers.removeOne(_clients[s]);        
    _clients.remove(s);
    
    reset();
}

//getters and setters
QTcpServer* Server::getServer()
{
    return _server;
}

void Server::setDifficulty(QString diff)
{
    _difficulty = diff;
}

QString Server::getDifficulty()
{
    return _difficulty;
}

void Server::setMaxPlayers(int max)
{
    _maxPlayers = max;
//    _server->setMaxPendingConnections(_maxPlayers); 
//    see to make this work somehow
//    increase when someone disconnects and decrease when someone connets
//    i think..
}

int Server::getMaxPlayers()
{
    return _maxPlayers;
}

