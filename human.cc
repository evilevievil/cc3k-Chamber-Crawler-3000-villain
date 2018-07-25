#include "human.h"

void Human::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

Human::Human():
  Enemy{'H', 140, 140, 20, 20} {}
	
