#include "item.h"

Item::Item(){}

Item::~Item(){
    std::cout<<"Item Destoryed"<<std::endl;
}

Item::Item(QString & item){
    this->setImage(item);
}

void Item::setImage(QString & item){
  this->item.load(item);
  this->setPixmap(this->item);
}



