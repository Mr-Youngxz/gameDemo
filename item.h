#ifndef ITEM_H
#define ITEM_H
#include "QGraphicsPixmapItem"
#include "QPixmap"
#include "iostream"
#include "QGraphicsSceneMouseEvent"
class Item : public QGraphicsPixmapItem
{
private:
  int no=0;
public:
  Item();
  Item(QString & item);
  ~Item();
  void setImage(QString & item);
  QPixmap item;
  bool isMouse=false;

};

#endif // ITEM_H
