#include "connection.h"


Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_Aziz");
    db.setUserName("system");
    db.setPassword("12345678");
    if (db.open())
    {
        test=true;

    }


    return test;
}
