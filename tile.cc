#include "tile.h"

Tile::Tile(char c, bool b): visual{c}, walkable{b} {}

Tile::~Tile() {}

char Tile::getVisual(){
  return visual;
}
bool Tile::isWalkable() {
  return walkable;
}

std::string Tile::beSpotted(){
  return "";
}
