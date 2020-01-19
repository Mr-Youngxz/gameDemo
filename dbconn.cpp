#include "dbconn.h"

QSqlDatabase * DBCreator(){
    QSqlDatabase * qdb=new QSqlDatabase;
    (*qdb)=QSqlDatabase::addDatabase("QPSQL");
    qdb->setDatabaseName("dev");
    qdb->setHostName("localhost");
    qdb->setPort(5555);               //PostgreSQL port
    qdb->setUserName("postgres");     //user name
    qdb->setPassword("11111111");    //You PostgreSQL password
    return qdb;
}

QSqlQuery * QSqlQueryCreator(){
    return new QSqlQuery;
}


void closeDB(QSqlDatabase & db){
    db.close();
}
