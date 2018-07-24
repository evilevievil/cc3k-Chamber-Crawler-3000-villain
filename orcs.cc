#include "orcs.h"

void Orcs::attack(Tile* pc){
  pc->beAttacked(*this);
}


Orcs::Orcs(Posn p, Tile* t):
  Enemy{'O', p, t, 180, 180, 30, 25} {}
