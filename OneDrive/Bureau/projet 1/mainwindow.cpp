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
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(p.afficher());
    ui->lineEdit_ref->setValidator(new QIntValidator(1,99999999,this));
    ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));
    ui->comboBox_3->setModel(p.affichervaleur("REFERENCE"));
    ui->sup_ref_2->setModel(p.affichervaleur("REFERENCE"));


    QSqlQuery *query = p.statistique();
    QPieSeries *series = new QPieSeries();
    // carte bancaire Cheque Espece
    int montantCheque =0;
    int montantEspece =0;
    int montantCarte =0;
    while ( query->next() ){
        if ( query->value(2).toString() == "Carte bancaire"){
            montantCarte+= query->value(1).toInt();
        }
        if ( query->value(2).toString() == "Cheque"){
            montantCheque+= query->value(1).toInt();
        }
        if ( query->value(2).toString() == "Espece"){
            montantEspece+= query->value(1).toInt();
        }
    }

    series->append("Cheque", montantCheque);
    series->append("carte Bancaire", montantCarte);
    series->append("Especes", montantEspece);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("statistique type de paiements");

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame);

    //partie arduino

    int ret = A.connect_arduino();
    switch(ret){
        case(0):qDebug()<< "arduino is available and connected to " << A.getarduino_port_name();
            break;
        case(1):qDebug()<< "arduino is available but not connected to " << A.getarduino_port_name();
            break;
    case(-1):qDebug()<< "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lance
    //le slot update_label suite a la reception du signal readyRead ( reception des données d'une arduino )



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data = A.read_from_arduino();
}


void MainWindow::on_pushButton_clicked()
{
    int REFERENCE=ui->lineEdit_ref->text().toInt();
    float MONTANT=ui->lineEdit_mont->text().toFloat();
     QString TYPE_PAIEMENT=ui->comboBox_t->currentText();
     QString DATE_PAIEMENT=ui->dateEdit_d->text();
      paiement p(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT);

      if ((ui->lineEdit_ref->text().isEmpty()) || (ui->lineEdit_mont->text().isEmpty()))
      {
          A.write_to_arduino("2");
          QMessageBox::critical(nullptr,QObject::tr("not ok"),
                     QObject::tr("remplir tout les donées.\n"
                                 "click Cancel to exit."),QMessageBox::Cancel);
      }
      else
      {
          bool test=p.ajouter();
                  if (test)
                  {
                      A.write_to_arduino("1");
                      // Refresh (Actualiser)
                      ui->tableView->setModel(p.afficher());
                      QMessageBox::information(nullptr,QObject::tr("ok"),
                                               QObject::tr("ajout effectué.\n"
                                                           "click Cancel to exit."),QMessageBox::Cancel);
                  }else{
                      A.write_to_arduino("3");
                      QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("ajout non effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);

                  }

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

void MainWindow::on_pushButton_8_clicked()
{
    //sup_ref_2
    int ref=ui->sup_ref_2->currentText().toInt();
    bool test1=p.ajouter_remboursement(ref);
    if (test1)
    {
        // Refresh (Actualiser)
         ui->tableView->setModel(p.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("remboursement effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("remboursement non effectué.\n"
                               "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->tableView->setModel(p.afficher_trier(arg1));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    int checkButton= 2;
    if( ui->radioButton->isChecked() ){
        checkButton = 0;
    }else if(ui->radioButton_2->isChecked()){
        checkButton = 1;
    }

    qDebug() << checkButton << arg1;
    ui->tableView->setModel(p.recherche_avance(arg1,checkButton));
}

void MainWindow::on_pushButton_9_clicked()
{
    if ( mode == 0){
        ui->pushButton_9->setText("mode sombre");
        ui->tabWidget->setStyleSheet(
                    "QWidget {background-color: #ffffff; color:#000000;}"
                    "QTabBar::tab:!selected {background-color: #ffffff; color:#000000;}"
                    "QTabBar::tab:selected {background-color: #ffffff; color:#000000;}"

            );
        ui->tableView->setStyleSheet(
                    "QHeaderView::section { background-color:#ffffff ; color:#000000}"
                    "QTableCornerButton::section {background-color:#ffffff ;}"
                    );
        mode = 1;
    }else{
        ui->pushButton_9->setText("mode jour");
        ui->tabWidget->setStyleSheet(
                    "QWidget {background-color: #595959; color:#ffffff;}"
                    "QTabBar::tab:!selected {background-color: #595959; color:#ffffff;}"
                    "QTabBar::tab:selected {background-color: #ACACAC; color:#ffffff;}"

            );
        ui->tableView->setStyleSheet(
                    "QHeaderView::section { background-color:#595959 ; color:white}"
                    "QTableCornerButton::section {background-color:#595959 ;}"
                    );
        mode = 0;
    }
}


