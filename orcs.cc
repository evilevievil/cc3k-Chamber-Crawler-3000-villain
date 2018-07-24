#include "orcs.h"

void Orcs::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}


Orcs::Orcs():
  Enemy{'O', 180, 180, 30, 25} {}
