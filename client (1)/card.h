#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QImage>

class Card
{   

public:
    Card(QString& c, QString& s);
    
    QImage getImage();
    QString getImgPath();
    int cardValue(int current);
    
private:
    QString _card;
    int _value;
    QString _suite;
    QImage _image;
    QString _imgPath;
};

#endif // CARD_H
