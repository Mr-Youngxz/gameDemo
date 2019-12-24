#include "dbconn.h"

QSqlDatabase * DBCreator(){
    QSqlDatabase * qdb=new QSqlDatabase;
    //use Postgresql
    (*qdb)=QSqlDatabase::addDatabase("QPSQL");
    qdb->setDatabaseName("dev");
    qdb->setHostName("localhost");
    qdb->setPort(5555);      //Postgresql port
    qdb->setUserName("");    //user name
    qdb->setPassword("");   //You PostgreSQL password
    return qdb;
}

QSqlQuery * QSqlQueryCreator(){
    return new QSqlQuery;
}


void closeDB(QSqlDatabase & db){
    db.close();
}
