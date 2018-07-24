#ifndef _TILE_H_
#define _TILE_H_
#include <vector>

//Abstract superclass for Race, Item and Brick
class Tile {

//protected private fields
protected:
  char visual;
  bool walkable;
<<<<<<< HEAD

//public methods
public:
  Tile(char c, bool b);
  char getVisual();
  bool isWalkable();
  virtual ~Tile() = 0;
  virtual std::string beSpotted();

};
#endif
