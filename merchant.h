#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "enemy.h"
#include "typedef.h"

class Merchant: public Enemy{
  static bool hostile;
public:
  void attack(Tile* pc) override;
  void beAttacked(PC& pc) override;
  void checkSurroundings(Map& map) override;
  static void resetHostile();
  Merchant();

};

#endif
