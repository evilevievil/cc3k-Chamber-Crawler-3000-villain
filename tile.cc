#include "tile.h"



Tile::Tile(char visual, bool walkable):
  visual{visual}, walkable{walkable}, neighbors{} {}

Tile::~Tile() {}

bool Tile::isWalkable() {
  return walkable;
}
