#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"paiement.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QIntValidator>
#include<QFile>
#include<QFileDialog>
#include<QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(p.afficher());
     ui->lineEdit_ref->setValidator(new QIntValidator(1,99999999,this));
     ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));
      ui->comboBox_3->setModel(p.affichervaleur("REFERENCE"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int REFERENCE=ui->lineEdit_ref->text().toInt();
    float MONTANT=ui->lineEdit_mont->text().toFloat();
     QString TYPE_PAIEMENT=ui->comboBox_t->currentText();
     QString DATE_PAIEMENT=ui->dateEdit_d->text();
      paiement p(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT);
      bool test=p.ajouter();
              if (test)
              {
                  // Refresh (Actualiser)
                  ui->tableView->setModel(p.afficher());
                  QMessageBox::information(nullptr,QObject::tr("ok"),
                                           QObject::tr("ajout effectué.\n"
                                                       "click Cancel to exit."),QMessageBox::Cancel);
              }
  else if ((ui->lineEdit_ref->text().isEmpty())||(ui->lineEdit_mont->text().isEmpty()))
              {
                  QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("remplir tout les donées.\n"
                                         "click Cancel to exit."),QMessageBox::Cancel);
              }
              else
              {
                  QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("ajout non effectué.\n"
                                         "click Cancel to exit."),QMessageBox::Cancel);

  }
}



void MainWindow::on_pushButton_5_clicked()
{
    paiement p;
       int REFERENCE=ui->comboBox_3->currentText().toInt();
       float MONTANT=ui->lineEdit->text().toFloat();
       QString TYPE_PAIEMENT=ui->comboBox_4->currentText();
       QString DATE_PAIEMENT=ui->dateEdit_3->text();
     bool test=p.modifier(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT);

       if (test)
       {
           // Refresh (Actualiser)
            ui->tableView->setModel(p.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("modification effectué.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                      QObject::tr("modification non effectué.\n"
                                  "Click Cancel to exit."),QMessageBox::Cancel);
   }


void MainWindow::on_pushButton_3_clicked()
{
    int REF=ui->sup_ref->currentText().toInt();

     bool test1=p.supprimer(REF);
     if (test1)
     {
         // Refresh (Actualiser)
          ui->tableView->setModel(p.afficher());
         QMessageBox::information(nullptr,QObject::tr("ok"),
                                  QObject::tr("supression effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                    QObject::tr("Supression non effectué.\n"
                                "Click Cancel to exit."),QMessageBox::Cancel);

}
