#include "goblin.h"
using namespace std;

void Goblin::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

void Goblin::beAttacked(Orcs& o){
  int d = 1.5 * damage(o.getAtk(), def);
  hp -= d;
  setDead();
  action << o.getVisual() << " deals " << d << " damage to PC" << endl;
}

Goblin::Goblin(): PC{110, 110, 15, 20, "Goblin"} {}
