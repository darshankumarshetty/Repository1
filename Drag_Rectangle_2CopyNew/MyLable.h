#ifndef MYLABLE_H
#define MYLABLE_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QHBoxLayout>

class MyLable : public QWidget
{
    Q_OBJECT
public:
    explicit MyLable(QWidget *parent = nullptr);
    void createLable();
    ~MyLable();

signals:

};

#endif // MYLABLE_H
