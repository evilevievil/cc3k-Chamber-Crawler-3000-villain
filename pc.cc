#include "pc.h"
#include "typedef.h"


int PC::getGold(){
  return gold;
}

int PC::getScore(){
  return gold;
}

bool PC::isDead(){
  return dead;
}

void PC::move(Map& map, Posn p){
  Tile* newTile = map[p.first][p.second];
  if(! newTile->isWalkable()){
    // give message that this is an invalid move
    return;
  }
  map[position.first][position.second] = curTile;
  curTile = newTile;
  tile = this;
}

void PC::attack(Tile* t){
  t.beAttacked(*this);
}


void PC::beAttacked(Human& h){
  hp -= damage(h.getAtk(), def);
  if(hp <= 0) dead = true;
}


void PC::beAttacked(Dwarf& w){
  hp -= damage(w.getAtk(), def);
  if(hp <= 0) dead = true;
}

void PC::beAttacked(Elf& e){
  hp -= damage(e.getAtk(), def);
  if(hp <= 0) dead = true;
}

void PC::beAttacked(Orcs& o){
  hp -= damage(o.getAtk(), def);
  if(hp <= 0) dead = true;
}

void PC::beAttacked(Merchant& m){
  hp -= damage(m.getAtk(), def);
  if(hp <= 0) dead = true;
}

void PC::beAttacked(Dragon& d){
  hp -= damage(d.getAtk(), def);
  if(hp <= 0) dead = true;
}

void PC::beAttacked(Halfling& l){
  hp -= damage(l.getAtk(), def);
  if(hp <= 0) dead = true;
}

PC::PC(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def): 
  Race{c, p, t, maxhp, hp, atk, def}, gold{0}, atkHistory{0}, defHistory{0} {}


