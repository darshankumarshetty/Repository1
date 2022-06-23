#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QDebug>
#include <QPainter>

class MyRectangle : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MyRectangle();
    void paint(QPainter *painter) override;
    ~MyRectangle();
};

#endif // MYRECTANGLE_H
