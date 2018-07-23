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

void PC::restoreHp(int i){
  hp += i;
}

void PC::addGold(int i){
  gold += i;
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


void PC::beAttacked(Enemy& e){
  hp -= damage(e.getAtk(), def);
  if(hp <= 0) dead = true;
}


void PC::beAttacked(Elf& e){
  hp -= damage(e.getAtk(), def);
  hp -= damage(e.getAtk(), def);
  if(hp <= 0) dead = true;
}


void PC::beAttacked(Orcs& o){
  hp -= damage(o.getAtk(), def);
  if(hp <= 0) dead = true;
}


PC::PC(Posn p, Tile* t, int maxhp, int hp, int atk, int def): 
  Race{'@', p, t, maxhp, hp, atk, def}, gold{0}, atkHistory{0}, defHistory{0} {}


