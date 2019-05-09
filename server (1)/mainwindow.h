#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "server.h"
#include <QMainWindow>

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
    void changeStackedWidgetIndex();
    void setDifficulty();
    
private:
    Ui::MainWindow *_ui;
    Server* _server;
    
    void initializeUi();
};

#endif // MAINWINDOW_H
