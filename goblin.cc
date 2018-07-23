#include "goblin.h"

void Goblin::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

void Goblin::beAttacked(Orcs& o){
  hp -= 1.5 * damage(o.getAtk(), def);
  if(hp <= 0) dead = true;
}

Goblin::Goblin(Posn p, Tile *t): PC{p, t, 110, 15, 20} {}
