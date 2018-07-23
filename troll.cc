#include "troll.h"

void Troll::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

Troll::Troll(Posn p, Tile* t): PC{p, t, 120, 120, 25, 15} {}
