#ifndef PAIEMENT_H
#define PAIEMENT_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>

class paiement
{
    QString TYPE_PAIEMENT;
    int REFERENCE;
    float MONTANT;
    QString DATE_PAIEMENT;
public:
    paiement();
    paiement(int,float,QString,QString);

    void setmontant(float MONTANT );
    void setreference(int REFERENCE);
    void settype(QString TYPE_PAIEMENT);
    void setdate(QString DATE_PAIEMENT);
    float get_montant();
    int get_reference();
    QString get_type();
    QString get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (int,float,QString,QString);
    QSqlQueryModel * affichervaleur(QString);
    bool ajouter_remboursement(int REFERENCE);
    QSqlQueryModel *afficher_trier(QString arg);
    QSqlQuery *statistique();
    QSqlQueryModel *recherche_avance(QString arg, int checkedButton);
private:


};

#endif // PAIEMENT_H
