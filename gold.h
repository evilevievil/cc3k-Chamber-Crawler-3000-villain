#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"


class Gold: public Item {
//private fields


//public methods
  virtual void affect(PC &pc);
  Gold();

};



#endif
