#ifndef _TESTPC_H_
#define _TESTPC_H_
#include "typedef.h"

class BA;
class BD;
class RH;
class WA;
class WD;
class PH;
class SmallHoard;
class NormalHoard;
class MerchantHoard;
class DragonHoard;


class PC {
public:
int HP, Atk, Def, Gold;
int atkHistory, defHistory;
char visual;

virtual ~PC() = 0;
PC(int HP, int Atk, int Def, int Gold, 
   int atkHistory, int defHistory, char visual):
  HP{HP}, Atk{Atk}, Def{Def}, Gold{Gold}, atkHistory{atkHistory},
  defHistory{defHistory}, visual{visual} {}


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


virtual void beRich(DragonHoard &gold){
  Gold = Gold + Dragon_effect;
}

};


#endif













;
