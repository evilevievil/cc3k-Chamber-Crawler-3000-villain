#include "goblin.h"

void Goblin::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

void Goblin::beAttacked(Orcs& o){
  d = 1.5 * damage(o.getAtk(), def);
  hp -= d;
  setDead();
  action << e.getVisual() << " deals " << d << " damage to PC" << endl;
}

Goblin::Goblin(Posn p, Tile *t): PC{p, t, 110, 15, 20} {}
