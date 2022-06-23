#include "PatientViewModel.h"

PatientViewModel::PatientViewModel(QObject *parent) : QAbstractListModel(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    k=0;
    init();
}

void PatientViewModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(int i=0;i<5;i++){
        m_pat = new PatientModel;
        if(i==0){
            m_pat->setName("Kavana");
            m_pat->setMiddlename("Jagadish");
            m_pat->setLastname("Gowda");
            m_pat->setAge("25");
            m_pat->setGender("Female");
            m_pat->setDiseases("Dizziness");
            m_pat->setAddress("Kalasa");
        }
        else if(i==1){
            m_pat->setName("Johnson");
            m_pat->setLastname("Vaz");
            m_pat->setAge("28");
            m_pat->setGender("Male");
            m_pat->setDiseases("Fever");
            m_pat->setAddress("Sirsi");
        }
        else if(i==2){
            m_pat->setName("Sahana");
            m_pat->setLastname("Gowda");
            m_pat->setAge("23");
            m_pat->setGender("Female");
            m_pat->setDiseases("Vomit");
            m_pat->setAddress("Hassan");
        }
        else if(i==3){
            m_pat->setName("Shree");
            m_pat->setMiddlename("Vatsa");
            m_pat->setAge("24");
            m_pat->setGender("Male");
            m_pat->setDiseases("Cold");
            m_pat->setAddress("Somanahalli");
        }
        else if(i==4){
            m_pat->setName("Darshan");
            m_pat->setMiddlename("Kumar");
            m_pat->setLastname("Shetty");
            m_pat->setAge("26");
            m_pat->setGender("Male");
            m_pat->setDiseases("Head Ache");
            m_pat->setAddress("Byndoor");
        }
        m_PatientList.append(m_pat);
        getName(i);
    }
}

void PatientViewModel::print()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    {
        for(auto it=m_PatientList.begin();it!=m_PatientList.end();it++){
            qDebug()<<"iterator******"<<*it<<Qt::endl;
        }
    }
}

int PatientViewModel::rowCount(const QModelIndex &index) const
{
    return m_PatientList.size();
}

QVariant PatientViewModel::data(const QModelIndex &index, int role) const
{
    int row=index.row();
    PatientModel *pm=m_PatientList.at(row);
    qDebug()<<Q_FUNC_INFO<<"Row--"<<row<<"Role--"<<role<<Qt::endl;
    switch (role) {
    case 1:
        return pm->name();
    }
    return "str";
}
QHash<int, QByteArray> PatientViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1]="PatietName";
    return roles;
}

QString PatientViewModel::getName(int index)
{
    QString nam = m_PatientList.at(index)->name();
    qDebug()<<nam;
    return nam;
}

PatientModel *PatientViewModel::compareData(QString str,QString str1,QString str2)
{
    qDebug()<<"*************"<<Q_FUNC_INFO<<Qt::endl;
    for(auto it=m_PatientList.begin();it!=m_PatientList.end();it++){
        if(((*it)->name().compare(str)==0) && ((*it)->middlename().compare(str1)==0) &&((*it)->Lastname().compare(str2) ==0)){
            qDebug()<<"iterator before******"<<*it<<Qt::endl;
            return (*it);
        }
        else{
            qDebug()<<"iterator After******"<<*it<<Qt::endl;
        }
    }
    qDebug()<<"Iterator in false"<<Qt::endl;
    return 0;
}

void PatientViewModel::addNewData(QString str0, QString str1, QString str2, QString str3, QString str4,QString str5,QString str6)
{
    qDebug()<<str0<<str1<<str2<<str3<<str4<<Qt::endl;
    qDebug()<<"Inside the addNewData "<<Qt::endl;
    m_pat = new PatientModel;
    m_pat->setName(str0);
    m_pat->setMiddlename(str5);
    m_pat->setLastname(str6);
    m_pat->setAge(str1);
    m_pat->setGender(str2);
    m_pat->setDiseases(str3);
    m_pat->setAddress(str4);
    m_PatientList.append(m_pat);
    qDebug()<<"Obj"<<m_pat<<Qt::endl;
    iterator();
}

QString PatientViewModel::searchData(QString str)
{

    for(auto it=m_PatientList.begin();it!=m_PatientList.end();it++){
        if((*it)->name()[k]==str)
        {
            k++;
            return (*it)->name();
        }
    }
    return "";
}

//void PatientViewModel::newData(PatientModel* pt)
//{
//    qDebug()<<"Address "<<pt<<Qt::endl;
//    m_newList.append(pt);
//    iterator();
//}

void PatientViewModel::iterator()
{
    for(auto it=m_PatientList.begin();it!=m_PatientList.end();it++){
        qDebug()<<"NewData "<<(*it)->name()<<(*it)->middlename()<<(*it)->Lastname()<<Qt::endl;
    }
}


