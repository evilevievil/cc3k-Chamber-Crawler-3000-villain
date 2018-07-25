#include "troll.h"
#include "enemy.h"

void Troll::endTurnAction(){
  restoreHp();
}

void Troll::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

Troll::Troll(): PC{120, 120, 25, 15, "Troll"} {}
