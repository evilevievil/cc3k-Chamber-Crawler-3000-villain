#ifndef _RACE_H_
#define _RACE_H_
#include <utility>
#include "tile.h"

class Race: public Tile{
protected:
	std::Pair<int, int> position;
	int maxhp, hp, atk, def;

public:
	int getHp();
	Race();
	virtual ~Race() = 0;
};

#endif