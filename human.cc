#include "human.h"
#include "pc.h"
#include "goldhoard.h"
#include <cstdlib>


void Human::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}


void Human::dropReward(Map& map){
  // place a normal pile on current position
  map[position.first][position.second] = new NormalHoard {};


  int row, col;
  // get a neighbour position of the current position to place the second pile
  while(true){
    row = position.first + (rand() % 3) - 1;
    col = position.second + (rand() % 3) - 1;
    if(map[row][col]->getVisual() == '.') break;
  }

  map[row][col] = new NormalHoard{};
  delete this;
}


Human::Human():
  Enemy{'H', 140, 140, 20, 20} {}
	
