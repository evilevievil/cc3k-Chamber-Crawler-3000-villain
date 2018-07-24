#include "slime.h"

void Slime::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

int Slime::getScore(){
  return 1.5 * gold;
}

Slime::Slime(Posn p, Tile* t) PC{p, t, 50, 50, 0, 200} {}


