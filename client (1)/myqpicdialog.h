#ifndef MYQPICDIALOG_H
#define MYQPICDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class MyQPicDialog : public QDialog
{
    Q_OBJECT
    
public:
    MyQPicDialog(QWidget *parent = 0);
    void setLabel(QImage img);
    
private:
    QLabel *_imageLabel;    
};

#endif // MYQPICDIALOG_H
