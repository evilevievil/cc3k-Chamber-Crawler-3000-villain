#include "tile.h"

Tile::Tile(char c, bool b): visual{c}, walkable{b} {}

Tile::~Tile() {}


Tile::Tile(char visual, bool walkable):
  visual{visual}, walkable{walkable}, neighbors{} {}

Tile::~Tile() {}

bool Tile::isWalkable() {
  return walkable;
}
