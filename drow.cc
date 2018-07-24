#include "drow.h"

void Drow::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

void Drow::beAttacked(Elf& e){
  d = damage(e.getAtk(), def);
  hp -= d;
  setDead();
  action << e.getVisual() << " deals " << d << " damage to PC" << endl;
}

Drow::Drow(Posn p, Tile* t): PC{p, t, 150, 150, 25, 15} {}
