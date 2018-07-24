#include "drow.h"

void Drow::attack(Tile* enemy){
  enemy->beAttacked(*this);
}

void Drow::beAttacked(Elf& e){
  d = damage(e.getAtk(), def);
  hp -= d;
  setDead();
  action << e.getVisual() << " deals " << d << " damage to PC" << endl;
}

Drow::Drow(Posn p, Tile* t): PC{p, t, 150, 150, 25, 15} {}

//override + overloaded methods for potion effects

void beAffected(BA &potion) override {
  atk = atk + BA_effect + (BA_effect / 2);
  atkHistory = atkHistory + BA_effect + (BA_effect / 2);
}



void beAffected(BD &potion) override {
  def = def + BD_effect + (BD_effect / 2);
  defHistory = defHistory + BD_effect + (BD_effect / 2);
}



void beAffected(RH &potion) override {
  int tmp = hp + RH_effect + (RH_effect / 2);
  if (tmp > maxhp) {hp = maxhp;}
}



void beAffected(WA &potion) override {
  atk = atk + WA_effect + (WA_effect / 2);
  atkHistory = atkHistory + WA_effect + (WA_effect / 2);
}




void beAffected(WD &potion) override{
  def = def + WD_effect;
  defHistory = defHistory + WD_effect + (WD_effect / 2);
}



void beAffected(PH &potion) override {
  int tmp = hp + PH_effect + (PH_effect / 2);
  if (tmp <= 0) {hp = 0;}
}




