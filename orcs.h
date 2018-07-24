#ifndef _ORCS_H_
#define _ORCS_H_

#include "enemy.h"
#include "typedef.h"

class Orcs: public Enemy{
public:
  void attack(Tile* pc) override;
  Orcs(Posn p, Tile* t);

};

#endif
