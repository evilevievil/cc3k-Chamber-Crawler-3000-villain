#ifndef _ITEM_H_
#define _ITEM_H_
#include tile.h

class Item: public Tile {
//private fields


//public methods
  virtual ~Item() = 0;
  virtual void affect(PC &pc) = 0;
  


};






#endif
