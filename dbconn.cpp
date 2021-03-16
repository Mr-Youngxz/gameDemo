#include "dbconn.h"

QSqlDatabase * DBCreator(){
    QSqlDatabase * qdb=new QSqlDatabase;
    (*qdb)=QSqlDatabase::addDatabase("QPSQL");
    qdb->setDatabaseName("dev");      //database you created before
    qdb->setHostName("localhost");
    qdb->setPort(5432);               //PostgreSQL port
    qdb->setUserName("postgres");     //user name
    qdb->setPassword("password");    //You PostgreSQL password
    return qdb;
}

QSqlQuery * QSqlQueryCreator(){
    return new QSqlQuery;
}

void closeDB(QSqlDatabase & db){
    db.close();
}
