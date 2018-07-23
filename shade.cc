#include "shade.h"

void Shade::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

int Shade::getScore(){
  return 1.5 * gold;
}

Shade::Shade(Posn p, Tile* t) PC{p, t, 125, 125, 25, 25} {}


