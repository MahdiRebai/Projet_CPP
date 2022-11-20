#include "mainwindow.h"
#include "connection.h"
#include "QMessageBox"
#include <QApplication>

int main(int argc, char *argv[])
{
    Connection c;
    bool test=c.createconnect();
    QApplication a(argc, argv);
    MainWindow w;

    if(test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
                          QObject::tr("connection successful.\n"
                                     "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}
