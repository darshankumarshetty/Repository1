#include "PatientModel.h"

PatientModel::PatientModel(QObject *parent) : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void PatientModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

}

void PatientModel::print()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

}

const QString &PatientModel::name() const
{
    return m_name;
}

void PatientModel::setName(const QString &newName)
{
    m_name = newName;
}

const QString &PatientModel::age() const
{
    return m_age;
}

void PatientModel::setAge(const QString &newAge)
{
    m_age = newAge;
}

const QString &PatientModel::gender() const
{
    return m_gender;
}

void PatientModel::setGender(const QString &newGender)
{
    m_gender = newGender;
}

const QString &PatientModel::diseases() const
{
    return m_diseases;
}

void PatientModel::setDiseases(const QString &newDiseases)
{
    m_diseases = newDiseases;
}

const QString &PatientModel::address() const
{
    return m_address;
}

void PatientModel::setAddress(const QString &newAddress)
{
    m_address = newAddress;
}

const QString &PatientModel::middlename() const
{
    return m_middlename;
}

void PatientModel::setMiddlename(const QString &newMiddlename)
{
    m_middlename = newMiddlename;
}

const QString &PatientModel::Lastname() const
{
    return m_Lastname;
}

void PatientModel::setLastname(const QString &newLastname)
{
    m_Lastname = newLastname;
}
