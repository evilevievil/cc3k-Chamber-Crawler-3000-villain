#include "drow.h"
using namespace std;

void Drow::attack(Tile* t){
  if(Enemy* e = dynamic_cast<Enemy*>(t)){
    e->beAttacked(*this);
  }
  else {
    throw "Invalid attack target";
  }
}

void Drow::beAttacked(Elf& e){
  int d = damage(e.getAtk(), def);
  hp -= d;
  setDead();
  action << e.getVisual() << " deals " << d << " damage to PC" << endl;
}

Drow::Drow(): PC{150, 150, 25, 15, "Drow"} {}

//override + overloaded methods for potion effects

void Drow::beAffected(BA &potion) override {
  atk = atk + BA_effect + (BA_effect / 2);
  atkHistory = atkHistory + BA_effect + (BA_effect / 2);
}



void Drow::beAffected(BD &potion) override {
  def = def + BD_effect + (BD_effect / 2);
  defHistory = defHistory + BD_effect + (BD_effect / 2);
}



void Drow::beAffected(RH &potion) override {
  int tmp = hp + RH_effect + (RH_effect / 2);
  if (tmp > maxhp) {hp = maxhp;}
}



void Drow::beAffected(WA &potion) override {
  atk = atk + WA_effect + (WA_effect / 2);
  atkHistory = atkHistory + WA_effect + (WA_effect / 2);
}




void Drow::beAffected(WD &potion) override{
  def = def + WD_effect;
  defHistory = defHistory + WD_effect + (WD_effect / 2);
}



void Drow::beAffected(PH &potion) override {
  int tmp = hp + PH_effect + (PH_effect / 2);
  if (tmp <= 0) {hp = 0;}
}




