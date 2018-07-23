#include "drow.h"

void Drow::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

void Drow::beAttacked(Elf& e){
  hp -= damage(e.getAtk(), def);
  if(hp <= 0) dead = true;
}

Drow::Drow(Posn p, Tile* t): PC{p, t, 150, 150, 25, 15} {}
