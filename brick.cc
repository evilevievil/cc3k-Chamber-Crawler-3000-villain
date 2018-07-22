#include "brick.h"

Tile::Item::Brick::Brick(char visual, bool walkable = false):
  Item{Tile{visual, walkable}} {}


