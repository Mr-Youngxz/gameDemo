#ifndef REGISTWINDOW_H
#define REGISTWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include "dbconn.h"
#include "sha1.hpp"
#include "QMessageBox"
#include "ctime"
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
  QSqlDatabase * dbconnector=nullptr;
  void regist();
};

#endif // REGISTWINDOW_H
