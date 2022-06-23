#ifndef PATIENTVIEWMODEL_H
#define PATIENTVIEWMODEL_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <PatientModel.h>
#include <QAbstractListModel>

class PatientViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PatientViewModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    QHash<int,QByteArray> roleNames()const override;

    void init();
    void print();

    Q_INVOKABLE QString getName(int index);
    Q_INVOKABLE PatientModel* compareData(QString str,QString str1,QString str2);
    Q_INVOKABLE void addNewData(QString str0,QString str1,QString str2,QString str3, QString str4,QString str5,QString str6);
    Q_INVOKABLE QString searchData(QString str);
//    Q_INVOKABLE void newData(PatientModel* pt);
    void iterator();
signals:
private:
    int k;
    PatientModel *m_pat;
    QList<PatientModel*> m_PatientList;
    QList<PatientModel*> m_newList;
};

#endif // PATIENTVIEWMODEL_H
