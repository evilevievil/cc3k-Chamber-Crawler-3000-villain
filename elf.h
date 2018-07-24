#ifndef _ELF_H_
#define _ELF_H_

#include "enemy.h"
#include "typedef.h"

class Elf: public Enemy{
public:
  void attack(Tile* pc) override;
  Elf(Posn p, Tile* t);

};

#endif
