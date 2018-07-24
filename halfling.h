#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "enemy.h"
#include "typedef.h"

class Halfling: public Enemy{
public:
  void attack(Tile* pc) override;
  void beAttacked(PC& pc) override;
	void beAttacked(Vampire& pc) override;
  Halfling();

};

#endif
