#include "myqpicdialog.h"

MyQPicDialog::MyQPicDialog(QWidget *parent) : 
    QDialog(parent)
{
    _imageLabel = new QLabel();
    _imageLabel->setFixedSize(156, 221);
    
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(_imageLabel, 0, 0);
    
    this->setStyleSheet("background-image: url('cards/table_felt.jpg')");
    
    setLayout(layout);
}

void MyQPicDialog::setLabel(QImage img)
{
    _imageLabel->setPixmap(QPixmap::fromImage(img));
    _imageLabel->setScaledContents(true);
}

