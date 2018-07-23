#include "vampire.h"

void Vampire::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

Vampire::Vampire(Posn p, Tile* t): PC{p, t, 9999, 50, 25, 25} {}
