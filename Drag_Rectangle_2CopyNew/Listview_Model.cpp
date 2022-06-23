#include "Listview_Model.h"

Listview_Model::Listview_Model(QObject *parent) : QAbstractListModel(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

void Listview_Model::init()
{
    for(int i=0;i<10;i++){
        m_dataList.append(i);
    }
}

int Listview_Model::rowCount(const QModelIndex &index) const
{
    return m_dataList.size();
}

QVariant Listview_Model::data(const QModelIndex &index, int role) const
{

}

void Listview_Model::removeDataofList(int index)
{
   qDebug()<<Q_FUNC_INFO <<Qt::endl;
   m_dataList.removeAt(index);
}

