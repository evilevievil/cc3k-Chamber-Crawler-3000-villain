#include <iostrem>
#include "tile.h"
#include "item.h"
#include "gold.h"
#include "potion.h"
#include "goldhoard.h"
#include "potiontype.h"
#include "typedef.h"
using namespace std

class PC {
public:
int HP, Atk, Def, Gold;
int atkHistory, defHistory;
char visual;

virtual ~PC() = 0;


virtual void beAffected(BA &potion) {
  Atk = Atk + BA_effect;
  atkHistory = atkHistory + BA_effect;
}



virtual void beAffected(BD &potion) {
  Def = Def + BD_effect;
  defHistory = defHistory + BD_effect;
}



virtual void beAffected(RH &potion) {
  HP = HP + RH_effect;
}



virtual void beAffected(WA &potion) {
  Atk = Atk + WA_effect;
  atkHistory = atkHistory + WA_effect;
}




virtual void beAffected(WD &potion) {
  Def = Def + WD_effect;
  defHistory = defHistory + WD_effect;
}



virtual void beAffected(PH &potion) {
  HP = HP + PH_effect;
}


virtual void beRich(SmallHoard &gold) {
 Gold = Gold + Small_effect; 
}



virtual void beRich(NormalHoard &gold) {
  Gold = Gold + Normal_effect;
}


virtual void beRich(MerchantHoard &gold) {
  Gold = Gold + Merchant_effect;
}


virtual void beRich(DragonHoard &gold);
  Gold = Gold + Dragon_effect;
};

class Slime: public PC{
Slime ():
public: 
  PC{50, 1, 200, 0, 0, 0, 'S'} {}
// lol Slime is lame..... no atk and 200 defence...
};

class Final: public PC{

Final():
public:
  PC{200, 50, 10, 0, 0, 0, 'F'} {}  

void beAffected(BA &potion) override {
  Atk = Atk + BA_effect + (BA_effect / 2);
  atkHistory = atkHistory + BA_effect + (BA_effect / 2);
}



void beAffected(BD &potion) override {
  Def = Def + BD_effect + (BD_effect / 2);
  defHistory = defHistory + BD_effect + (BD_effect / 2);
}



void beAffected(RH &potion) override {
  HP = HP + RH_effect + (RH_effct / 2);
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

switch(s) {

case "slime-rh" : rh->affect(*slime);
                  break;
case "slime-ba" : ba->affect(*slime);
                  break;
case "slime-bd" : bd->affect(*slime);
                  break;
case "slime-ph" : ph->affect(*slime);
                  break;
case "slime-wa" : wa->affect(*slime);
                  break;
case "final-wd" : wd->affect(*exam);
                  break; 
case "final-rh" : rh->affect(*exam);
                  break;
case "final-ba" : ba->affect(*exam);
                  break;
case "final-bd" : bd->affect(*exam);
                  break;
case "final-ph" : ph->affect(*exam);
                  break; 
case "final-wa" : wa->affect(*exam);
                  break;
case "final-wd" : wd->affect(*exam);
                  break; 

case "slime-sg" : sg->affect(*slime);
                  break;
case "slime-ng" : ng->affect(*slime);
                  break;
case "slime-mg" : mg->affect(*slime);
                  break;
case "slime-dg" : dg->affect(*slime);
                  break;
case "final-sg" : sg->affect(*exam);
                  break;
case "final-ng" : ng->affect(*exam);
                  break;
case "final-mg" : mg->affect(*exam);
                  break;
case "final-dg" : dg->affect(*exam);
                  break; 



}

print_PC(slime);
print_PC(exam);

}








} 



















































