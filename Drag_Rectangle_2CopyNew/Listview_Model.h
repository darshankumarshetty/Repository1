#ifndef LISTVIEW_MODEL_H
#define LISTVIEW_MODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QDebug>
#include <QList>
class Listview_Model : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Listview_Model(QObject *parent = nullptr);
    void init();
    int rowCount(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role)const override;
    Q_INVOKABLE void removeDataofList(int index);

private:
    QList<int> m_dataList;
};

#endif // LISTVIEW_MODEL_H
