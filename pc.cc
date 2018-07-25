#include "pc.h"
using namespace std;


int PC::getGold(){
  return gold;
}

int PC::getScore(){
  return gold;
}

bool PC::isDead(){
  return dead;
}

void PC::setCurTile(Tile* t){
  curTile = t;
}

// set PC's dead to true if PC's hp falls below 0
void PC::setDead(){
  if(hp <= 0){
    hp = 0;
    dead = true;
  }
}

void PC::restoreHp(int i){
  hp += i;
}

void PC::addGold(int i){
  gold += i;
}

void PC::move(Map& map, Posn p){
  Tile* newTile = map[p.first][p.second];
  // check if new square is walkable
  if(! newTile->isWalkable()){
    action << "this is a invalid move." << endl;
    throw "Invalid move";
  }
  // walk to new square
  map[position.first][position.second] = curTile;
  curTile = newTile;
  newTile = this;
  position = p;
}

void PC::checkSurroundings(Map& map){
  // check neighbour squares and add to action the item spotted
  for(int i = position.first - 1; ++i; i < position.first + 2){
    for(int j = position.second - 1; ++j; j < position.second + 2){
      action << map[i][j]->beSpotted() << endl;
    }
  }
}

// PC that has special end turn actions will override this method
void PC::endTurnAction(){}


// PC is attacked by an enemy
void PC::beAttacked(Enemy& e){
  int d = damage(e.getAtk(), def);
  hp -= d;
  setDead();
  action << e.getVisual() << " deals " << d << " damage to  PC" << endl;
}

// PC is attacked by an elf
void PC::beAttacked(Elf& e){
  // Elf attacks twice
  int d = damage(e.getAtk(), def);
  hp -= 2 * d;
  setDead();
  action << e.getVisual() << " deals " << d << " + " << d << " damage to PC" << endl;
}

// PC is attacked by an Orcs
void PC::beAttacked(Orcs& o){
  int d = damage(o.getAtk(), def);
  hp -= d;
  setDead();
  action << o.getVisual() << " deals " << d << " damage to PC" << endl;
}


PC::PC(int maxhp, int hp, int atk, int def, string hero): 
  Race{'@', maxhp, hp, atk, def},name{hero}, gold{0}, atkHistory{0}, defHistory{0} {}



//overloaded methods for item(gold and potion)

virtual void PC::beAffected(BA &potion) {
  atk = atk + BA_effect;
  atkHistory = atkHistory + BA_effect;
}



virtual void PC::beAffected(BD &potion) {
  def = def + BD_effect;
  defHistory = defHistory + BD_effect;
}



virtual void PC::beAffected(RH &potion) {
  int tmpHP = hp + RH_effect;
  if (tmpHP > maxhp) {hp = maxhp;}
}



virtual void PC::beAffected(WA &potion) {
  atk = atk + WA_effect;
  atkHistory = atkHistory + WA_effect;
}




virtual void PC::beAffected(WD &potion) {
  def = def + WD_effect;
  defHistory = defHistory + WD_effect;
}



virtual void PC::beAffected(PH &potion) {
  int tmpHP = hp + PH_effect;
  if (tmpHP <= 0) {hp = 0;}
}


virtual void PC::beRich(SmallHoard &gold) {
 gold = gold + Small_effect; 
}



virtual void PC::beRich(NormalHoard &gold) {
  gold = gold + Normal_effect;
}


virtual void PC::beRich(MerchantHoard &gold) {
  gold = gold + Merchant_effect;
}


virtual void PC::beRich(DragonHoard &gold){
  gold = gold + Dragon_effect;
}
