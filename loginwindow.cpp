#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
LoginWindow::LoginWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::LoginWindow)
{
    dbconnector=DBCreator();
    dbconnector->open();
    if(dbconnector->isOpen()){
         std::cout<<std::string("Active!")<<std::endl;
    }else{
         std::cout<<std::string("DataBase No Active!")<<std::endl;
    }
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
  delete ui;
}

void LoginWindow::on_sub_btn_clicked()
{
    if(this->LoginActivity()){
        mainPtr=std::shared_ptr<MainWindow>(new MainWindow);
        mainPtr->setWindowModality((Qt::ApplicationModal));
        this->mainPtr->show();

        this->setHidden(true);

    }else{
        QMessageBox::warning(this,"Invaild Info","Invaild Account or Password",QMessageBox::Yes);
    }
}


bool LoginWindow::LoginActivity(){
        if(query==nullptr)
          query=std::shared_ptr<QSqlQuery>(QSqlQueryCreator());
        const QString sql=" select pid,ssid from player where name=:name ";
        const QString par1 =":name";
        query->prepare(sql);
        SHA1 check;
        //provide user password
        QString account=ui->account->text();
        check.update((account+(ui->password->text())).toLocal8Bit().toStdString());
        QString pwd=QString(check.final().data());
        std::cout<<pwd.toStdString()<<std::endl;
        query->bindValue(par1,account);
        if(query->exec()){
            if(query->next()&&(query->value(1).toString().compare(pwd))){
                  std::cout<<query->value(1).data();
                  return true;
              }
         }
         else
            std::cout<<"Invaild Account or password"<<std::endl;
        return false;
}

void LoginWindow::on_regist_btn_clicked()
{
    regPtr=std::shared_ptr<RegistWindow> (new RegistWindow());
    regPtr->setWindowModality((Qt::ApplicationModal));
    this->regPtr->show();
}
