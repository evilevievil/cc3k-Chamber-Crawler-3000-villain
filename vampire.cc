#include "vampire.h"

void Vampire::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

Vampire::Vampire(): PC{9999, 50, 25, 25} {}
