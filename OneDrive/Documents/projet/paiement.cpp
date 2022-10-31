#include "paiement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

paiement::paiement()
{
    REFERENCE=0;
    MONTANT=0;
    TYPE_PAIEMENT="";
    DATE_PAIEMENT="";
}

paiement::paiement(int REFERENCE,float MONTANT,QString TYPE_PAIEMENT,QString DATE_PAIEMENT)
{



   this->REFERENCE=REFERENCE;
    this->MONTANT = MONTANT;
    this->TYPE_PAIEMENT=TYPE_PAIEMENT;
    this->DATE_PAIEMENT=DATE_PAIEMENT;

}

 bool paiement::ajouter()
 {
     QSqlQuery query;


        QString MON = QString::number(MONTANT);
       QString REF = QString::number(REFERENCE);
       query.prepare("insert into GESTION_PAIEMENT(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT)"
                     "values(:REFERENCE,:MONTANT,:TYPE_PAIEMENT,:DATE_PAIEMENT)");
          query.bindValue(":REFERENCE",REF);
          query.bindValue(":MONTANT",MON);
          query.bindValue(":TYPE_PAIEMENT",TYPE_PAIEMENT);
          query.bindValue(":DATE_PAIEMENT",DATE_PAIEMENT);

   return query.exec();
 }
QSqlQueryModel *paiement::afficher()
{
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from GESTION_PAIEMENT");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTANT"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PAIEMENT"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_PAIEMENT"));
            return model;
    };

bool paiement::modifier(int REFERENCE,float MONTANT,QString TYPE_PAIEMENT,QString DATE_PAIEMENT)
{
    QSqlQuery query;
    QString mon=QString::number(MONTANT);
    QString res=QString::number(REFERENCE);
            query.prepare("update GESTION_PAIEMENT set REFERENCE =:REFERENCE,MONTANT=:MONTANT,TYPE_PAIEMENT=:TYPE_PAIEMENT,DATE_PAIEMENT=:DATE_PAIEMENT WHERE REFERENCE=:REFERENCE");
            query.bindValue(":REFERENCE",res);
            query.bindValue(":MONTANT",mon);
            query.bindValue(":TYPE_PAIEMENT",TYPE_PAIEMENT);
            query.bindValue(":DATE_PAIEMENT",DATE_PAIEMENT);
            return  query.exec();
};

bool paiement::supprimer(int REFERENCE)
{

    QSqlQuery query;
    QString res=QString::number(REFERENCE);
    query.prepare("Delete from GESTION_PAIEMENT where REFERENCE = :REFERENCE");
    query.bindValue(":REFERENCE",res);
    return  query.exec();
};
QSqlQueryModel* paiement::affichervaleur(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString ch="SELECT ";
    QString query=" FROM GESTION_PAIEMENT";
    query=ch+valeur+query;
    model->setQuery(query);
    return model;


}
