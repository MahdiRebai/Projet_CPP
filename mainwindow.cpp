#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qrcode.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "avis.h"
#include "connection.h"
#include <QTextStream>
#include <QFile>
#include<QMessageBox>
#include<QWidget>
#include <QTextStream>
#include <QDataStream>
#include <QSortFilterProxyModel>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include <fstream>
#include <iostream>
#include <notification.h>
#include <QIntValidator>
#include<QSqlQuery>
#include<QDebug>
#include<QApplication>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QtCharts/QChartView>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_c->setModel(Etmp.afficher());
    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                          QRegularExpression::CaseInsensitiveOption);
                ui->Objet->setValidator(new QRegularExpressionValidator(rx, this));
                ui->Num_avis->setValidator( new QIntValidator(0, 999999, this));
                QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                            ui->Nom->setValidator(new QRegularExpressionValidator(rx1, this));
                            QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                  QRegularExpression::CaseInsensitiveOption);
                                        ui->Reclamation->setValidator(new QRegularExpressionValidator(rx2, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


    void MainWindow::on_ajouter_clicked()
    {
        notification n;
        int Num_avis=ui->Num_avis->text().toInt();
        QString Nom=ui->Nom->text();
        QString Objet=ui->Objet->text();
        QString Reclamation=ui->Reclamation->text();

        avis C(Num_avis,Nom,Objet,Reclamation);
         bool test=C.ajouter();
         QMessageBox msgBox ;

         if  ((ui->Num_avis->text().isEmpty())||(ui->Nom->text().isEmpty())||(ui->Objet->text().isEmpty())||(ui->Reclamation->text().isEmpty()))
         {

     QMessageBox::warning(this,"we deliver","Veuillez remplir les champs obligatoires marqués en rouge");}
         else {
         if(test)
         { msgBox.setText(" ajout avec succes.") ;
             n.notification_ajout();
            ui->tab_c->setModel(C.afficher());}
         else
              msgBox.setText("echec.") ;
             msgBox.exec();}


    }


void MainWindow::on_supprimer_clicked()
{  avis C ;
    int Num_avis=ui->le_cin_sup->text().toInt();
    bool test=C.supprime(Num_avis);
    QMessageBox msgBox ;
    if(test)
       { msgBox.setText("suppression avec succes.") ;
    ui->tab_c->setModel(C.afficher());}
    else
         msgBox.setText("echec.") ;
    ui->tab_c->setModel(C.afficher());

        msgBox.exec();

}

void MainWindow::on_modifier_clicked()
{
          int Num_avis=ui->Num_avis->text().toInt();
          QString Nom=ui->Nom->text();
          QString Objet=ui->Objet->text();
          QString Reclamation=ui->Reclamation->text();

          avis a (QString,QString,QString,int);
          Etmp.setNom(Nom);
          Etmp.setObjet(Objet);
          Etmp.setReclamation(Reclamation);
         bool test=Etmp.modifier(Etmp.getNum_avis());
         if (test)
         {
             ui->tab_c->setModel(Etmp.afficher());

             QMessageBox::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("modif effectué\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);



         }
         else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("modif non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tri_pass_clicked()
{
    avis r;
    ui->tab_c->setModel(r.trier());
}

void MainWindow::on_tri_cin_clicked()
{
    avis r;
       ui->tab_c->setModel(r.trier2());
}

void MainWindow::on_tri_nom_clicked()
{
    avis r;
       ui->tab_c->setModel(r.trier1());
}



void MainWindow::on_recherchecin_textChanged(const QString &arg1)
{

}

void MainWindow::on_supprimer_2_clicked()
{
    avis c;
    QString re=ui->rech->text();
    if (re=="")
        ui->tab_c->setModel(c.afficher());
    else
        ui->tab_c->setModel(c.rechercher(re));

}

void MainWindow::on_supprimer_3_clicked()
{
    avis C;
    ui->tab_c->setModel(C.afficher());
}

void MainWindow::on_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM avis WHERE Num_avis  LIKE'"+arg1+"%' or Nom  LIKE'"+arg1+"%' or Objet LIKE'"+arg1+"%' or Reclamation LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) {
         model->setQuery(*query);
         ui->tab_c->setModel(model);
         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->rech->clear();}
}

void MainWindow::on_supprimer_4_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tab_c->model()->rowCount();
            const int columnCount = ui->tab_c->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("strTitle")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"

                //     "<align='right'> " << datefich << "</align>"
                "<center> <H1>Liste Des Reclamation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabcas->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_c->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++)
            {
                out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                for (int column = 0; column < columnCount; column++)
                {
                    if (!ui->tabcas->isColumnHidden(column))
                    {
                        QString data = ui->tab_c->model()->data(ui->tab_c->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table> </center>\n"
                "</body>\n"
                "</html>\n";

            QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty())
            {
                fileName.append(".pdf");
            }

            QPrinter p (QPrinter::PrinterResolution);
            p.setOutputFormat(QPrinter::PdfFormat);
            p.setPaperSize(QPrinter::A4);
            p.setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.setPageSize(p.pageRect().size()); // This is necessary if you want to hide the page number
            doc.print(&p);
}






