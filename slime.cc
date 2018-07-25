#include "slime.h"
#include "enemy.h"

void Slime::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

int Slime::getScore(){
  return 1.5 * gold;
}

Slime::Slime(): PC{50, 50, 0, 200, "Slime"} {}


