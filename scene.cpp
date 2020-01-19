#include "scene.h"
#include "random"
#include "ctime"
int Scene::count =0;

Scene::Scene(QObject *parent) :QGraphicsScene(parent)
{
    srand(static_cast<unsigned>(time(0)));
    QString mice=":/mouse/mouse_alive.png";
    this->initial();
    timer=new QTimer;
    connect(this->timer,SIGNAL(timeout()),this,SLOT(addMouse()));
}

void Scene::initial(){
  QString hole=":/background/bg_hole.png";
  position.reserve(16);
  for(int i=1;i<=16;i++){
      loadImage(imageContainer,hole,nowX,nowY);
      position.emplace_back(new std::pair<int,int>(nowX,nowY));
      nowX+=131;
      if(i%4==0){
        nowY+=88;
        nowX=0;
      }
    }
  QString hammer=":/hamer/hammer_up.png";
  this->hammer.setImage(hammer);
  this->hammer.setPos(0,0);
  this->addItem(&this->hammer);
}

void Scene::loadImage(std::vector<Item *> & container,QString & source,int x,int y){
    item=new Item(source);
    item->setPos(x,y);
    this->addItem(item);
    container.push_back(item);
}

void Scene::addMouse(){
    QString mice=":/mouse/mouse_alive.png";
    micePosition=(rand()%16);
    item=new Item(mice);
    item->isMouse=true;
    this->nowX=static_cast<int>(this->position.at(micePosition)->first);
    this->nowY=static_cast<int>(this->position.at(micePosition)->second);
    this->item->setPos(nowX,nowY);
    this->addItem(item);
    this->miceCliked=true;
    this->MiceManage=std::shared_ptr<Item>(item);
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
  QString hemer_attacked=":/hamer/hammer_down.png";
  QPointF qp=mouseEvent->scenePos();
  this->hammer.setImage(hemer_attacked);
  const int x=static_cast<int>((qp.x()/131));
  const int y=static_cast<int>((qp.y()/88));
  if(miceCliked && (x==(nowX/131) && y==(nowY/88))){
      miceCliked=false;
      emit this->sendCount(++(this->count));
      QString miceAttaced=":/mouse/mouse_attcked.png";
      MiceManage->setImage(miceAttaced);
   }
}


void Scene::recivedStarted(){
    this->timer->start(1000);
}
void Scene::recivedStop(){
    //shared_ptr指针重置，销毁对象
    MiceManage.reset();
    this->timer->stop();
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
  QString hammer=":/hamer/hammer_up.png";
  this->hammer.setImage(hammer);
  QPointF qp=mouseEvent->scenePos();
  this->hammer.setPos(qp.x()-30,qp.y()-30);
}


