#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QObject>
#include <QDebug>
#include <QString>

class PatientModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString PName READ name CONSTANT)
    Q_PROPERTY(QString MName READ middlename CONSTANT)
    Q_PROPERTY(QString LName READ Lastname CONSTANT)
    Q_PROPERTY(QString PAge READ age CONSTANT)
    Q_PROPERTY(QString PGender READ gender CONSTANT)
    Q_PROPERTY(QString PDisease READ diseases CONSTANT)
    Q_PROPERTY(QString PAddress READ address CONSTANT)
public:
    explicit PatientModel(QObject *parent = nullptr);
    void init();
    void print();
    const QString &name() const;
    void setName(const QString &newName);

    const QString &age() const;
    void setAge(const QString &newAge);

    const QString &gender() const;
    void setGender(const QString &newGender);

    const QString &diseases() const;
    void setDiseases(const QString &newDiseases);

    const QString &address() const;
    void setAddress(const QString &newAddress);

    const QString &middlename() const;
    void setMiddlename(const QString &newMiddlename);

    const QString &Lastname() const;
    void setLastname(const QString &newLastname);

signals:
private:
    QString m_name;
    QString m_middlename;
    QString m_Lastname;
    QString m_age;
    QString m_gender;
    QString m_diseases;
    QString m_address;
};

#endif // PATIENTMODEL_H
