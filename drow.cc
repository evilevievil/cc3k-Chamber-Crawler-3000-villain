#include "drow.h"
using namespace std;

void Drow::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

void Drow::beAttacked(Elf& e){
  int d = damage(e.getAtk(), def);
  hp -= d;
  setDead();
  action << e.getVisual() << " deals " << d << " damage to PC" << endl;
}

Drow::Drow(): PC{150, 150, 25, 15} {}
