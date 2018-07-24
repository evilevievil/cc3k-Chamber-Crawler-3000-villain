#ifndef _BRICK_H_
#define _BRICK_H_

#include "tile.h"

class Brick: public Tile{
public:
  //public method
  Brick(char visual, bool walkable = false);
};

#endif
