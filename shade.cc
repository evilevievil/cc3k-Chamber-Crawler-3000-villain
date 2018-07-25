#include "shade.h"
#include "enemy.h"

void Shade::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

int Shade::getScore(){
  return 1.5 * gold;
}

Shade::Shade(): PC{125, 125, 25, 25, "Shade"} {}


