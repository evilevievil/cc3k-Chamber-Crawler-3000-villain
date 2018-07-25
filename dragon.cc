#include "dragon.h"
#include "pc.h"


void Dragon::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

void Dragon::checkSurroundings(Map& map){


}

Dragon::Dragon(Tile* hoard):
  Enemy{'D', 150, 150, 20, 20}, hoard{hoard} {}
