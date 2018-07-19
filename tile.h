#ifndef _TILE_H_
#define _TILE_H_


//Abstract superclass for Race, Item and Brick
class Tile {

//private fields
char visual;
bool isCell;


//public methods
public:
virtual ~Tile() = 0;

bool isStationary();


}
#endif
