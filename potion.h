#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"
#include "pc.h"

class Potion: public Item {
//private fields

//protected fields

//public methods
public:
  Potion();
  virtual ~Potion() = 0;
  virtual std::string beSpotted() = 0;
}; 











#endif
