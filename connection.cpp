#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("mourad");//inserer nom de l'utilisateur
db.setPassword("mourad");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
 void Connection::closeconnect(){db.close();}