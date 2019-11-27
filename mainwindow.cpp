#include "mainwindow.h"
#include "QPixmap"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  scene=new Scene();
  this->ui->view->setScene(this->scene);
  //当锤子需要移动时候，需要对鼠标时间进行跟踪
  this->ui->view->setMouseTracking(true);
  connect(scene,SIGNAL(sendCount(int)),this,SLOT(recivedCount(int)));
  connect(this,SIGNAL(sendStarted()),scene,SLOT(recivedStarted()));
  connect(this,SIGNAL(sendStop()),scene,SLOT(recivedStop()));
}

void MainWindow::recivedCount(int count){
    this->ui->displayer->display(count);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    std::cout<<"dwdwd\n\n\n\n\n\n"<<std::endl;
    const QString n="确定退出？";
    QMessageBox msg(QMessageBox::Question,n,"确定退出？",QMessageBox::No|QMessageBox::Yes);
    if(msg.exec()==QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}

void MainWindow::on_start_btn_clicked()
{
    emit this->sendStarted();
}

void MainWindow::on_pause_btn_clicked()
{
    emit this->sendStop();
}

