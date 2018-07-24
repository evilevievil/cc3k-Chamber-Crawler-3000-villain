#include "human.h"

void Human::attack(Tile* pc){
  pc->beAttacked(*this);
}

Human::Human(Posn p, Tile* t):
  Enemy{'H', p, t, 140, 140, 20, 20} {}
	
