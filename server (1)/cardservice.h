#ifndef CARDSERVICE_H
#define CARDSERVICE_H

#include <QObject>
#include <QString>
#include <time.h>

class CardService : public QObject
{
    Q_OBJECT
    
public:
    CardService();
    CardService(QStringList *dec, QObject *parent = 0);
    
    int cardValue(QString card, int current);
    QString pickCard();

private:
    QStringList *_deck;
};

#endif // CARDSERVICE_H
