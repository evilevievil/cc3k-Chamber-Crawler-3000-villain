#include "dwarf.h"

void Dwarf::attack(Tile* pc){
  pc->beAttacked(*this);
}

void Dwarf::beAttacked(Vampire& pc){
  d = damage(pc.getAtk(), def);
  pc.restoreHp(-5); // Vampire loses 5 HP when attcking dwarf
  hp -= d;
  giveReward(pc);
  reportDamage(d, pc.action);
}

Dwarf::Dwarf(Posn p, Tile* t):
  Enemy{'W', p, t, 100, 100, 20, 30} {}
