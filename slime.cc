#include "slime.h"

void Slime::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

int Slime::getScore(){
  return 1.5 * gold;
}

Slime::Slime() PC{50, 50, 0, 200, "Slime"} {}


