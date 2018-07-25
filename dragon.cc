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
  // check one block radius of Dragon
  for(int i = position.first - 1; i < position.first + 2; ++i){
    for(int j = position.second - 1; j < position.second + 2; ++j){
      if(map[i][j]->getVisual() == '@'){
	      // pc is in one block radius, attck it
	      attack(map[i][j]);
        return;
      }
    }
  }
  //check one block radius of DragonHoard
  for(int i = hoard.first - 1; i < hoard.first + 2; ++i){
    for(int j = hoard.second - 1; j < hoard.second + 2; ++j){
      if(map[i][j]->getVisual() == '@'){
	      // pc is in one block radius, attck it
	      attack(map[i][j]);
        return;
      }
    }
  }
}

Dragon::Dragon(Posn hoard):
  Enemy{'D', 150, 150, 20, 20}, hoard{hoard} {}
