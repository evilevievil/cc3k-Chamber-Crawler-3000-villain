#include "elf.h"

void Elf::attack(Tile* pc){
  pc->beAttacked(*this);
}


Elf::Elf(Posn p, Tile* t):
  Enemy{'E', p, t, 140, 140, 30, 10} {}
