#include "halfling.h"
#include "vampire.h"
#include <cstdlib>
#include "pc.h"

void Halfling::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

// this is attacked by a PC
void Halfling::beAttacked(PC& pc){
  // PC's attack has 50% chance of missing
  int missed = rand() % 2;
  if(missed){
    pc.action << "PC's attack missed (" << hp << "hp). ";
    return;
  }
  // if not missed, do following
  int d = damage(pc.getAtk(), def);
  hp -= d;
  giveReward(pc);
  reportDamage(d, pc.action);
}

// this is attacked by an vampire
void Halfling::beAttacked(Vampire& pc){
  // PC's attack has 50% chance of missing
  int missed = rand() % 2;
  if(missed){
    pc.action << "PC's attack missed (" << hp << "hp). ";
    return;
  }
  // if not missed, do folloing
  int d = damage(pc.getAtk(), def);
  hp -= d;
  // vampire gains 5 HP after attck
  pc.restoreHp();
  giveReward(pc);
  reportDamage(d, pc.action);
}

Halfling::Halfling():
  Enemy{'E', 100, 100, 15, 20} {}
