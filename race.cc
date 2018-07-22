#include "race.h"
#include <cmath>


Race::Race(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def): 
  Tile{c, false}, position{p}, curTile{t}, maxhp{maxhp}, hp{hp}, atk{atk}, def{def}
{}

Race::~Race() {}

int Race::getHp(){
  return hp;
}

int Race::getAtk(){
  return atk;
}

int Race::getDef(){
  return def;
}

int Race::damage(int atk, int def){
  return std::ceil((100 / (100 + def)) * atk);
}
