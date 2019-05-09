#include "housechooser.h"

HouseChooser::HouseChooser(QStringList* dec, QString dif, QObject *parent)
    : QThread(parent), _deck(dec), _diff(dif)
{
    _service = new CardService(_deck, this);
}

void HouseChooser::run()
{
    int current = 0;
    if(_diff.compare("Easy") == 0){
        for( ; current < 16; ){
            QString card = _service->pickCard();
    
            qDebug() << "House card: " + card;
            
            current += _service->cardValue(card.split(" ")[0], current); 
        }
    }
    else{
        while( current < 18 ){
            QString card = _service->pickCard();
    
            current += _service->cardValue(card.split(" ")[0], current); 
            
            qDebug() << "House card: " + card;
        }
        
        if( current < 21 ){
            
            while(true){
                int temp = 21 - current;
                int usefulCards = 0;

                for(auto c : *_deck){
                    int value = _service->cardValue(c.split(" ")[0], current);
                    if(value <= temp)
                        usefulCards += 1;
                }

                int usefulPercent = usefulCards/_deck->size();
                if( usefulPercent > 3*(1 - usefulPercent) ){
                    QString card = _service->pickCard();

                    qDebug() << "House card: " + card;

                    current += _service->cardValue(card.split(" ")[0], current);

                    if(current > 21)
                        break;
                }
                else
                    break;
            } //end while
            
        } //end if
        
    }//end else
    
//    qDebug() << "************************************";
//    qDebug() << *_deck;
//    qDebug() << "************************************";
    
    emit resultReady(current);
}
