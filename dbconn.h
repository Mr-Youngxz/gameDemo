#ifndef DBCONN_H
#define DBCONN_H
#include "iostream"
#include <QtSql>
#include "QString"
#include "QStyle"
#include "memory"
#include "QSqlDatabase"

QSqlDatabase * DBCreator();
void closeDB(QSqlDatabase & db);
QSqlQuery * QSqlQueryCreator();

#endif // DBCONN_H
