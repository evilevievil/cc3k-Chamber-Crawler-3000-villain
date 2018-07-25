#ifndef _DWARF_H_
#define _DWARF_H_

#include "enemy.h"
#include "typedef.h"

class Vampire;

class Dwarf: public Enemy{
public:
  void attack(Tile* pc) override;
  void beAttacked(Vampire& pc) override;
  Dwarf();
};

#endif
