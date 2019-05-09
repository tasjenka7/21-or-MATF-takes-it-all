#include "card.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _socket(new QTcpSocket(this)),
    _total(0),
    _holdedFlag(false)
{
    _ui->setupUi(this);
    initializeUI();
    
    connectSignals();
    
    //Menu bar
    QAction* newGame = new QAction(tr("&newGame"), this);
    QAction* help = new QAction(tr("&help"), this);
    QAction* sound = new QAction(tr("&sound"), this);
    
    connect(_ui->actionNew_game, SIGNAL(triggered()), this, SLOT(newGame()));
    connect(_ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));
    connect(_ui->actionMusic, SIGNAL(triggered()), this, SLOT(playMusic()));
    
    QMenuBar* menuBar = new QMenuBar();
    menuBar->addAction(newGame);
    menuBar->addAction(help);
    menuBar->addAction(sound);

}


MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::connectSignals()
{
    connect(_ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableLoginButton()));
    
    //hit or hold
    connect(_ui->hit, SIGNAL(clicked()), this, SLOT(playerChoice()));
    connect(_ui->hold, SIGNAL(clicked()), this, SLOT(playerChoice())); 
    
    //start new game
    connect(_ui->startNew, SIGNAL(clicked()), this, SLOT(playerChoice())); 
    connect(_ui->startNew, SIGNAL(clicked()), this, SLOT(startNewGameUI()));
    
    connect(_ui->login, SIGNAL(clicked()), this, SLOT(login()));
    connect(_ui->lineEdit, SIGNAL(returnPressed()), _ui->login, SIGNAL(clicked()));
    connect(_ui->disconnect, SIGNAL(clicked()), this, SLOT(disconnect()));
    connect(_ui->disconnect, SIGNAL(clicked()), this, SLOT(close()));

    connect(_ui->disconnect_2, SIGNAL(clicked()), this, SLOT(back()));  //back in help


    connect(_ui->bet10, SIGNAL(clicked()), this, SLOT(bet10Clicked()));
    connect(_ui->bet25, SIGNAL(clicked()), this, SLOT(bet25Clicked()));
    connect(_ui->bet50, SIGNAL(clicked()), this, SLOT(bet50Clicked()));
    
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));   //when server wrote smth in socket, and he needs to read it
    connect(_socket, SIGNAL(connected()), this, SLOT(onConnected()));   // -||- accepted connection, he gets username
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorHappend()));  //error, socket gets error, we know whitch one
}


void MainWindow::errorHappend()
{
   qDebug() << "Error: " + _socket->errorString();
}


//read username from lineEdit and add it to username, then write to socket
void MainWindow::login()
{
    _username = _ui->lineEdit->text();
    _bettingMoney = _ui->spinBox->value();
    
    startNewGameUI();

    _ui->username->setText(_username);
    _ui->lcdNumber->display(QString::number(_bettingMoney));

    //We connect to ANA-LAPTOP or 192.168.1.241 depeding on witch computer we use as a host (ipconfig /all)
    _socket->connectToHost("192.168.1.241", 53413);
    _ui->stackedWidget->setCurrentIndex(1);
}


//notify server of what button player pressed
void MainWindow::playerChoice()
{
    _buttonPressed = qobject_cast<QPushButton*>(sender())->text();

    if(_buttonPressed.compare("Hold") == 0){
        disableUI();
        _holdedFlag = true;
    }
    
    writeToSocket(QString(_buttonPressed + "\n"), "notified server of button pressed");
    
}

void MainWindow::writeToSocket(QString message, QString qDebugMsg)
{
    _socket->write(message.toUtf8()); 
    _socket->flush();
    if(!_socket->waitForBytesWritten(10000))
        qDebug() << qDebugMsg;    
}

//write username to server
void MainWindow::onConnected()
{        
    writeToSocket(QString(_username + "\n"), "sent username to server");
}


//read the card or other info that server sent
//other info: someone won, unblock (if pressed hold)..
void MainWindow::onReadyRead()
{
    while(_socket->canReadLine()){
        QString line = QString::fromUtf8(_socket->readLine()).trimmed();  
        
        if(line.compare("Deck is empty!") == 0){
            _total = 0;
        }
        else if(line.contains("won") || line.contains("Tie") || line.contains("lost")){
            //this is game over if
            _total = 0;

            if(line.contains(_username))
                editBetMoneyOver(2);
            else if(line.contains("Tie"))
                editBetMoneyOver(1);
            else
                editBetMoneyOver(0);

            QMessageBox info;
            info.setText(line);
            info.exec();
            
            _holdedFlag = true;
            disableBets(false);
            disableUI();
        }
        else{
            //create card:
            QStringList split = line.split(" ");
            Card c(split[0], split[1]);
            
            _total += c.cardValue(_total);       
            
            MyQPicDialog *cardPopup = new MyQPicDialog();
            cardPopup->setLabel(c.getImage());
            cardPopup->setWindowFlags(Qt::FramelessWindowHint);
            cardPopup->show();
            
            connect(cardPopup, SIGNAL(accepted()), this, SLOT(close()));
            
            //when timer times out, close the popup and exit the loop
            //the loop just stops the program from continuing
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), cardPopup, SLOT(close()));
            
            _ui->hand->setViewMode(QListWidget::IconMode);
            _ui->hand->setIconSize(QSize(81, 101));
            _ui->hand->setResizeMode(QListWidget::Adjust);
            _ui->hand->addItem(new QListWidgetItem(QIcon(c.getImgPath()), ""));
            
            QEventLoop loop;
            connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
            timer->start(1600);
            loop.exec();
            
            if(_total > 21){
                _total = 0;
                _holdedFlag = true;
                disableBets(false);
                disableUI();
    
//                QMessageBox info;
//                info.setText("You lost");
//                info.exec();
            }
            
        } //end if got card
        
    } //end while    
}


void MainWindow::editBetMoneyOver(int amount)
{
    _bettingMoney = _bettingMoney + amount * _chosenBet;
    disableBets(false);
    _ui->lcdNumber->display(QString::number(_bettingMoney));    
}


void MainWindow::placedBet(int amount)
{
    _bettingMoney = _bettingMoney - amount;
    _ui->lcdNumber->display(QString::number(_bettingMoney));
    _chosenBet = amount;    

    disableBets(true);
    if(_holdedFlag){
        _ui->startNew->setEnabled(true);    
        _holdedFlag = false;   
    }
}

void MainWindow::disableBets(bool p)
{
    _ui->bet25->setDisabled(p);
    _ui->bet10->setDisabled(p);
    _ui->bet50->setDisabled(p);
}

void MainWindow::disableUI()
{
    _ui->hit->setEnabled(false);
    _ui->hold->setEnabled(false);
}

void MainWindow::startNewGameUI()
{
    _ui->hit->setEnabled(true);
    _ui->hold->setEnabled(true);
    _ui->startNew->setDisabled(true);
    _ui->hand->clear();

}

void MainWindow::initializeUI()
{    
    this->setStyleSheet("MainWindow {background-image: url('cards/table_felt.jpg')}");
    _ui->hand->setStyleSheet("background-image: url('cards/table_felt.jpg')");
    _ui->hand->setFrameStyle(QFrame::NoFrame);
    
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("music/you_know_my_name.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    
    _player = new QMediaPlayer(this);
    _player->setPlaylist(playlist);
    _player->setVolume(50);
    
    
    _ui->label_4->setPixmap(QPixmap::fromImage(QImage("cards/logo.png"))); 
    _ui->label_4->setScaledContents(true);
    
    
    setBetImage("cards/chip10.png", _ui->bet10);
    setBetImage("cards/chip25.png", _ui->bet25);
    setBetImage("cards/chip50.png", _ui->bet50);
    
    _ui->login->setDisabled(true);
    _ui->startNew->setDisabled(true);
    
    _ui->label_4->setScaledContents(true);
    _ui->label_4->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    _ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::setBetImage(QString img, QPushButton *btn)
{
    QPixmap pixmap(img);
    QIcon ButtonIcon(pixmap);
    btn->setIcon(ButtonIcon);
    btn->setIconSize(pixmap.rect().size());
    
}

void MainWindow::enableLoginButton()
{
    _ui->login->setEnabled(true);
}

void MainWindow::newGame()
{
    _ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::help()
{
    _currentIndex = _ui->stackedWidget->currentIndex();
    _ui->stackedWidget->setCurrentIndex(2);
}

//go back to game after you read the rules
void MainWindow::back()
{
    _ui->stackedWidget->setCurrentIndex(_currentIndex);
}

//disconnect from host when Quit clicked
void MainWindow::disconnect()
{
    _socket->disconnectFromHost();
}

void MainWindow::bet50Clicked()
{
    placedBet(50);
}

void MainWindow::bet25Clicked()
{
    placedBet(25);
}

void MainWindow::bet10Clicked()
{
    placedBet(10);  
}

void MainWindow::playMusic()
{
    if(_player->state() == QMediaPlayer::PlayingState)
        _player->pause();
    else
        _player->play();
}
