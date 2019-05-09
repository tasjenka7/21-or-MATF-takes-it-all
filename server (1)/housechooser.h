#ifndef HOUSECHOOSER_H
#define HOUSECHOOSER_H

#include <QThread>
#include <QDebug>
#include <time.h>
#include "cardservice.h"

class HouseChooser : public QThread
{ 
    Q_OBJECT
    
public:
    void run();
    HouseChooser(QStringList* dec, QString dif, QObject *parent = 0);
    
signals:
    void resultReady(const int &s);

private:
    CardService* _service;
    QStringList* _deck;
    QString _diff;
};

#endif // HOUSECHOOSER_H
