#include "MyLable.h"

MyLable::MyLable(QWidget *parent) : QWidget(parent)
{
    qDebug()<<Q_FUNC_INFO<<"MyLable constructor"<<Qt::endl;
    createLable();
}

void MyLable::createLable()
{
    setStyleSheet( "QWidget{ background-color : rgba( 160, 160, 160, 255); border-radius : 7px;  }" );
    QLabel *label = new QLabel(this);
       QHBoxLayout *layout = new QHBoxLayout();
       label->setText("Random String");
       layout->addWidget(label);
       setLayout(layout);
}

MyLable::~MyLable()
{
    qDebug()<<Q_FUNC_INFO<<"MyLable Destructor"<<Qt::endl;
}
