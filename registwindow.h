#ifndef REGISTWINDOW_H
#define REGISTWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include "dbconn.h"
#include "sha1.hpp"
#include "QMessageBox"
#include "ctime"
#include "mainwindow.h"
#include "loginwindow.h"

namespace Ui {
  class RegistWindow;
}

class RegistWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit RegistWindow(QWidget *parent = nullptr);
  ~RegistWindow();

private slots:
  void on_sub_btn_clicked();

private:
  Ui::RegistWindow *ui;
  std::shared_ptr<QSqlQuery> query=nullptr;
  std::shared_ptr<MainWindow> mainPtr = nullptr;

  //std::shared_ptr<QSqlDatabase> dbconnector = nullptr;
  QSqlDatabase * dbconnector=nullptr;
  bool regist();
  void closeEvent(QCloseEvent *event);
};

#endif // REGISTWINDOW_H
