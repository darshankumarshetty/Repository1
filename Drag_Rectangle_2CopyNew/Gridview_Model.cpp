#include "Gridview_Model.h"

void Gridview_Model::init()
{

}

Gridview_Model::Gridview_Model(QObject *parent) : QAbstractListModel(parent)
{
  qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int Gridview_Model::rowCount(const QModelIndex &index) const
{
    return 10;
}

QVariant Gridview_Model::data(const QModelIndex &index, int role) const
{

}


