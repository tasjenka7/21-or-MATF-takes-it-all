#include "card.h"

Card::Card(QString& c, QString& s) 
    : _card(c), _suite(s)
{
    _imgPath = "cards/" + _card + "_" + _suite + ".jpg";
    QImage img;
    img.load(_imgPath);
    
    _image = img;
}


int Card::cardValue(int current)
{
    if(!_card.compare("10") || !_card.compare("J") || !_card.compare("Q") || !_card.compare("K"))
        return 10;
    else if(!_card.compare("A")){
        if(current + 11 > 21)
            return 1;
        else
            return 11;
    }
    else
        return _card.toInt();
}


QImage Card::getImage()
{
    return _image;
}

QString Card::getImgPath()
{
    return _imgPath;
}
