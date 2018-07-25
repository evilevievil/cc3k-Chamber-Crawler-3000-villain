#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "enemy.h"
#include "typedef.h"

class Dragon: public Enemy{
  Tile* hoard;
public:
  void attack(Tile* pc) override;
  void checkSurroundings(Map& map) override;
  Dragon(Tile* hoard);

};

#endif
