#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include "QMessageBox"
#include "QCloseEvent"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
signals:
  void sendStarted();
  void sendStop();

private slots:
  void on_start_btn_clicked();
  void recivedCount(int count);
  void on_pause_btn_clicked();

private:
  Ui::MainWindow *ui;
  Scene * scene;
  std::shared_ptr<Scene> sceneManager=nullptr;
  void closeEvent(QCloseEvent * event);

};
#endif // MAINWINDOW_H
