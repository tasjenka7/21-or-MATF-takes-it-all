#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    
    w.setFixedSize(280, 150);
    
    w.show();
    
    return a.exec();
}
