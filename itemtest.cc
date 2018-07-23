#include <iostream>
#include <string>
#include "testpc.h"
#include "tile.h"
#include "item.h"
#include "gold.h"
#include "potion.h"
#include "goldhoard.h"
#include "potiontype.h"
#include "typedef.h"
using namespace std;


class Slime: public PC{
public:
Slime (): 
  PC{50, 1, 200, 0, 0, 0, 'S'} {}
~Slime() {}
// lol Slime is lame..... no atk and 200 defence...
};

class Final: public PC{
public:
Final():
  PC{200, 50, 10, 0, 0, 0, 'F'} {}  
~Final() {}
void beAffected(BA &potion) override {
  int temp = Atk + BA_effect + (BA_effect / 2);
  atkHistory = atkHistory + BA_effect + (BA_effect / 2);
}



void beAffected(BD &potion) override {
  Def = Def + BD_effect + (BD_effect / 2);
  defHistory = defHistory + BD_effect + (BD_effect / 2);
}



void beAffected(RH &potion) override {
  HP = HP + RH_effect + (RH_effect / 2);
}



void beAffected(WA &potion) override {
  Atk = Atk + WA_effect + (WA_effect / 2);
  atkHistory = atkHistory + WA_effect + (WA_effect / 2);
}




void beAffected(WD &potion) override{
  Def = Def + WD_effect;
  defHistory = defHistory + WD_effect + (WD_effect / 2);
}



void beAffected(PH &potion) override {
  HP = HP + PH_effect + (PH_effect / 2);
}

};


void print_PC(PC *pc) {
cout<<pc->visual<<':'<<endl;
cout<<"HP = "<<pc->HP<<endl;
cout<<"Atk = "<<pc->Atk<<endl;
cout<<"Def = "<<pc->Def<<endl;
cout<<"Gold = "<<pc->Gold<<endl;
cout<<"atkHistory = "<<pc->atkHistory<<endl;
cout<<"defHistory = "<<pc->defHistory<<endl;
}


int main() {

PC *slime = new Slime();
PC *exam = new Final();

Potion *rh = new RH();
Potion *ba = new BA();
Potion *bd = new BD();
Potion *ph = new PH();
Potion *wa = new WA();
Potion *wd = new WD();

Gold *sg = new SmallHoard();
Gold *ng = new NormalHoard();
Gold *mg = new MerchantHoard();
Gold *dg = new DragonHoard();

string s;

while (cin>>s) {

if (s == "slime-rh") {
  rh->affect(*slime);
} else if (s == "slime-ba") {
  ba->affect(*slime);
} else if (s == "slime-bd") {
  bd->affect(*slime);
} else if (s == "slime-ph") {
  ph->affect(*slime);
} else if (s == "slime-wa") {
  wa->affect(*slime);
} else if (s == "slime-wd") {
  wd->affect(*slime);
} else if (s == "final-rh") {
  rh->affect(*exam);
} else if (s == "final-ba") {
  ba->affect(*exam);
} else if (s == "final-bd") {
  bd->affect(*exam);
} else if (s == "final-ph") {
  ph->affect(*exam);
} else if (s == "final-wa") {
  wa->affect(*exam);
} else if (s == "final-wd") {
  wd->affect(*slime);
} else {break;}



print_PC(slime);
print_PC(exam);

}








} 



















































