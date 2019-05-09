#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "card.h"
#include "myqpicdialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onConnected();
    void login();
    void errorHappend();
    void onReadyRead();
    void disconnect();
    void playerChoice();
    void enableLoginButton();
    void startNewGameUI();
    void newGame();
    void help();
    void back();
    void playMusic();
    
    void bet50Clicked();
    void bet25Clicked();
    void bet10Clicked();

private:
    Ui::MainWindow *_ui;
    QTcpSocket *_socket;
    QString _buttonPressed;
    QString _username;
    int _total;
    int _bettingMoney;
    int _chosenBet;
    int _currentIndex;
    QMediaPlayer *_player;

    //i didnt want a flag, but its too late and im too tired to think
    bool _holdedFlag;
    
    void editBetMoneyOver(int amount);
    void placedBet(int amount);
    void disableBets(bool p);
    
    void setBetImage(QString img, QPushButton *btn);
    void writeToSocket(QString message, QString qDebugMsg);
    void connectSignals();
    void disableUI();
    void initializeUI();

};

#endif // MAINWINDOW_H
