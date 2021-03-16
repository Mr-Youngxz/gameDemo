#include "registwindow.h"
#include "ui_registwindow.h"

RegistWindow::RegistWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::RegistWindow)
{

  dbconnector = DBCreator();
  dbconnector->open();
  ui->setupUi(this);
}

RegistWindow::~RegistWindow()
{
  delete ui;
}

void RegistWindow::on_sub_btn_clicked()
{
    if(this->regist()){
        mainPtr=std::shared_ptr<MainWindow>(new MainWindow);
        mainPtr->setWindowModality((Qt::ApplicationModal));
        this->mainPtr->show();
        this->setHidden(true);
    }

}

bool RegistWindow::regist(){
    if(query==nullptr)
      query=std::shared_ptr<QSqlQuery>(QSqlQueryCreator());
    const QString querySql="select id from player where name=:name ";
    const QString par1 = ":name";
    const QString account = this->ui->account->text();
    query->prepare(querySql);
    query->bindValue(par1,account);
    if(query->exec()){
        if(!query->next()){
            const QString sql="insert into player(name,ssid,regist_day) values (:name,:ssid,:regist_day)";
            const QString par2 = ":ssid";
            const QString par3=":regist_day";
            query->prepare(sql);
            SHA1 check;
            check.update((account+(ui->password->text())).toLocal8Bit().toStdString());
            QString pwd=QString(check.final().data());
            std::cout<<pwd.toStdString()<<std::endl;
            QString timeStamp=QString::number(static_cast<int>(time(0)));
            query->bindValue(par1,account);
            query->bindValue(par2,pwd);
            query->bindValue(par3,timeStamp);
            //std::cout<<query.;
            if(query->exec()){
                std::cout<<"insert success"<<std::endl;
                return true;
            }
            else{
                std::cout<<query->lastError().text().toLocal8Bit(). toStdString()<<std::endl;
                std::cout<<"insert failed"<<std::endl;
            }
          }
        else{
            QMessageBox::warning(this,"Invaild Regist Operation","Account Already Regist!",QMessageBox::Yes);
          }
     }
     else{
        std::cout<<query->lastError().text().toLocal8Bit().toStdString();
        std::cout<<"SQL Fail"<<std::endl;
    }
    return false;
}


void RegistWindow::closeEvent(QCloseEvent *event){
    const QString n="确定退出？";
    QMessageBox msg(QMessageBox::Question,n,"确定退出？",QMessageBox::No|QMessageBox::Yes);
    if(msg.exec()==QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}

