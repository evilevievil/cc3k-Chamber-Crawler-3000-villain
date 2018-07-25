#include "merchant.h"
#include "pc.h"


bool Merchant::hostile = false;


void Merchant::attack(Tile* t){
  if(PC* pc = dynamic_cast<PC*>(t)){
    pc->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}


void Merchant::checkSurroundings(Map& map){
  // if not hostile, just take a random move
  if(! hostile){
    randMove(map);
    return;
  }

  //check if pc is in one block radius
  for (int i = position.first - 1; i < position.first + 2; ++i) {
      for (int j = position.second - 1; j < position.second + 2; ++j) {
      if(map[i][j]->getVisual() == '@'){
	// pc is in one block radius, attck it
	attack(map[i][j]);
        return;
      }
    }
  }
  // pc is not in one block radius, take a random move
  randMove(map);
}


void Merchant::resetHostile(){
  hostile = true;
}


Merchant::Merchant():
  Enemy{'M', 30, 30, 70, 5} {}