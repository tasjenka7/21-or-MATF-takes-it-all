#include "cardservice.h"


CardService::CardService()
{}

CardService::CardService(QStringList *dec, QObject *parent)
    : QObject(parent), _deck(dec)
{}


int CardService::cardValue(QString card, int current)
{
    if(!card.compare("10") || !card.compare("J") || !card.compare("Q") || !card.compare("K"))
        return 10;
    else if(!card.compare("A")){
        if(current + 11 > 21)
            return 1;
        else
            return 11;
    }
    else
        return card.toInt();
}

QString CardService::pickCard()
{
    QString card;
    if( !_deck->empty() ){
        qsrand(time(NULL));
        card = _deck->at(qrand() % _deck->size());

        _deck->removeOne(card);
    }
    else{
        card = "Deck is empty!";
    }
    
    return card;    
}
