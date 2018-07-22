#ifndef _RACE_H_
#define _RACE_H_
#include <utility>
#include "tile.h"
#include "typedef.h"

class Race: public Tile{
protected:
	Posn position;
	Tile* curTile;
	int maxhp, hp, atk, def;
	

public:
	int getHp();
	int getAtk();
	int getDef();
	int damage(int atk, int def);
	Race(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def);
	virtual ~Race() = 0;
};

#endif
