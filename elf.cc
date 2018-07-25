#include "elf.h"
#include "pc.h"

void Elf::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}


Elf::Elf():
  Enemy{'E', 140, 140, 30, 10} {}
