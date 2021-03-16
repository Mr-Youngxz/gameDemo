#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QtSql>
#include "dbconn.h"
#include "sha1.hpp"
#include "registwindow.h"
#include "QMessageBox"

namespace Ui {
  class LoginWindow;
}

class LoginWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit LoginWindow(QWidget *parent = nullptr);
  ~LoginWindow();

private slots:
  void on_regist_btn_clicked();
  void on_sub_btn_clicked();

private:
  Ui::LoginWindow *ui = nullptr;
  std::shared_ptr<MainWindow> mainPtr = nullptr;
  std::shared_ptr<RegistWindow> regPtr = nullptr;
  std::shared_ptr<QSqlQuery> query = nullptr;
  std::shared_ptr<QSqlDatabase> dbconnector = nullptr;
  //QSqlDatabase * dbconnector = nullptr;
  bool LoginActivity();
};

#endif // LOGINWINDOW_H
