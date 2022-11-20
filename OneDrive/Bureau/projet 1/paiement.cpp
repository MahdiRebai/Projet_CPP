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


// select * from messages where id= 11 ;

///  select * from messages where id = "'"select * from messages where 1=1  //"'" idaziz


bool paiement::ajouter_remboursement(int REFERENCE)
{
    QSqlQuery query;
    QString res=QString::number(REFERENCE);
            query.prepare("update GESTION_PAIEMENT set REMBOURSEMENT=:rem WHERE REFERENCE=:REFERENCE");
            query.bindValue(":rem",1);
            query.bindValue(":REFERENCE",REFERENCE);
            return query.exec();
};

QSqlQueryModel *paiement::afficher_trier(QString arg)
{
        QSqlQueryModel * model=new QSqlQueryModel();
        if ( arg == "Montant" ){
            model->setQuery("select * from GESTION_PAIEMENT ORDER BY MONTANT ASC");
        }else if ( arg == "Type de paiement" ){
            model->setQuery("select * from GESTION_PAIEMENT ORDER BY TYPE_PAIEMENT ASC");
        }
        else if ( arg == "Reference" ){
            model->setQuery("select * from GESTION_PAIEMENT ORDER BY REFERENCE ASC");
        }
        else if ( arg == "Date" ){
             model->setQuery("select * from GESTION_PAIEMENT ORDER BY DATE_PAIEMENT ASC");
        }else{
            model->setQuery("select * from GESTION_PAIEMENT");
        }

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTANT"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PAIEMENT"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_PAIEMENT"));
            return model;
    };


QSqlQuery* paiement::statistique(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from GESTION_PAIEMENT");
    query->exec();
    return query;
}


QSqlQueryModel *paiement::recherche_avance(QString arg, int checkedButton)
{
        QSqlQueryModel * model=new QSqlQueryModel();

        if ( checkedButton == 0 ){
            model->setQuery("select * from GESTION_PAIEMENT WHERE REFERENCE like '" "%" + arg + "%" "'  ");
        }else if ( checkedButton == 1 ){
            model->setQuery("select * from GESTION_PAIEMENT WHERE TYPE_PAIEMENT like '" "%" + arg + "%" "'  ");
        }

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTANT"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PAIEMENT"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_PAIEMENT"));
        return model;

};
