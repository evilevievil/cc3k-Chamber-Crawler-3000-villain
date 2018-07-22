#include "tile.h"

Tile::Tile(char c, bool b): visual{c}, walkable{b} {}

Tile::~Tile() {}

bool Tile::isWalkable() {
  return Walkable;
}
