#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "QGraphicsScene"
#include "item.h"
#include "memory"
#include "vector"
#include "iostream"
#include <unistd.h>
#include "QTimer"
class Scene : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit Scene(QObject *parent = nullptr);
  ~Scene(){
    if(timer!=nullptr)
        delete timer;
    std::cout<<"Scene Destroyed"<<std::endl;
  }

signals:
   void sendCount(int);
public slots:
   void addMouse();
   void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
   void recivedStarted();
   void recivedStop();
private:
  void loadImage(std::vector<Item *> & container,QString & source,int x,int y);
  void initial();
  //std::shared_ptr<Item> miceManager=nullptr;
  std::vector<Item *> imageContainer;
  int micePosition;
  Item * item;
  std::shared_ptr<Item> MiceManage;
  Item hemer;
  QTimer * timer=nullptr;
  int nowX=0;
  int nowY=0;
  static int count;
  bool miceCliked=false;
  std::vector<std::pair<int,int> *> position;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // SCENE_H
