#ifndef _ITEM_H_
#define _ITEM_H_
#include "tile.h"
#include "testpc.h"

class Item: public Tile {
//private fields


//public methods
public:
  virtual ~Item() = 0;
  virtual void affect(PC &pc) = 0;
  Item(char visual, bool walkable);  


};






#endif
