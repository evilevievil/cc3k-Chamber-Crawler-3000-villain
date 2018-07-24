#include "dragon.h"

void Dragon::attack(Tile* pc){
  pc->beAttacked(*this);
}

void Dragon::checkSurroundings(Map& map){


}

Dragon::Dragon(Posn p, Tile* t, Tile* hoard):
  Enemy{'E', p, t, 150, 150, 20, 20}, hoard{hoard} {}
