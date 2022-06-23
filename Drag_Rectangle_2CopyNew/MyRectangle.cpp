#include "MyRectangle.h"

MyRectangle::MyRectangle()
{
    qDebug()<<Q_FUNC_INFO<<"My Rectangle Constructor"<<Qt::endl;
}

void MyRectangle::paint(QPainter *painter)
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    QRectF f(10,10,80,80);//x,y,w,h
    painter->setBrush(Qt::green);
    painter->setPen(Qt::red);
    painter->drawRect(f);
}

MyRectangle::~MyRectangle()
{
    qDebug()<<Q_FUNC_INFO<<"My Rectangle Destructor"<<Qt::endl;
}
