#ifndef GRIDVIEW_MODEL_H
#define GRIDVIEW_MODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QDebug>

class Gridview_Model : public QAbstractListModel
{
    Q_OBJECT
public:
    void init();
    explicit Gridview_Model(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role)const override;
};
#endif // GRIDVIEW_MODEL_H
