#ifndef _ITEM_H_
#define _ITEM_H_

class Item: public Tile {
//private fields


//public methods
  virtual ~Item() = 0;
  virtual void affect(PC &pc) = 0;
  


};






#endif
