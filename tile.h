#ifndef _TILE_H_
#define _TILE_H_
#include <vector>

//Abstract superclass for Race, Item and Brick
class Tile {

//protected private fields
protected:
  char visual;
  bool walkable;
  std::vector<Tile *> neighbors;

//public methods
public:
  virtual ~Tile() = 0;
  Tile(char visual, bool walkable);
  bool isWalkable();
  virtual std::string beSpotted() = 0;

};
#endif
