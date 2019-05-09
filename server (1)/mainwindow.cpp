#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    
    _server = new Server(this);    
    
    connect(_ui->easyButton, SIGNAL(clicked()), this, SLOT(setDifficulty()));
    connect(_ui->hardButton, SIGNAL(clicked()), this, SLOT(setDifficulty()));
    connect(_ui->selectButton, SIGNAL(clicked()), this, SLOT(changeStackedWidgetIndex()));
    
    initializeUi();    
}

void MainWindow::setDifficulty()
{
    QRadioButton* button = qobject_cast<QRadioButton*>(QObject::sender());
    
    _server->setDifficulty(button->text());
    
    QString msg;
    msg += "Server running..\nPort: ";
    msg += QString::number(_server->getServer()->serverPort());
    msg += "\nDifficulty: ";
    msg += _server->getDifficulty();
    _ui->infoLabel->setText(msg);
    
    _ui->selectButton->setEnabled(true);
}

void MainWindow::changeStackedWidgetIndex()
{
    _server->setMaxPlayers(_ui->spinBox->text().toInt());
    qDebug() << "Max players: " + QString::number(_ui->spinBox->value());
    
    _ui->stackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::initializeUi()
{
    _ui->stackedWidget->setCurrentIndex(0);
    _ui->spinBox->setMaximum(5);
    _ui->spinBox->setMinimum(1);
    _ui->selectButton->setEnabled(false);
    
    QFont font;
    font.setBold(true);
    _ui->infoLabel->setFont(font);
    
    _ui->infoLabel->setAlignment(Qt::AlignCenter);
}
