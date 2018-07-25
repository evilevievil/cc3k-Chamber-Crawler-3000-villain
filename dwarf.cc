#include "dwarf.h"
#include "vampire.h"
#include "pc.h"


void Dwarf::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

void Dwarf::beAttacked(Vampire& pc){
  int d = damage(pc.getAtk(), def);
  pc.restoreHp(-5); // Vampire loses 5 HP when attcking dwarf
  hp -= d;
  giveReward(pc);
  reportDamage(d, pc.action);
}

Dwarf::Dwarf():
  Enemy{'W', 100, 100, 20, 30} {}
