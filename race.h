#ifndef _RACE_H_
#define _RACE_H_
#include <utility>
#include <string>
#include "tile.h"
#include "typedef.h"

class Race: public Tile{
protected:
	Posn position;
	int maxhp, hp, atk, def;
	bool dead = false;

public:
	int getHp();
	int getAtk();
	int getDef();
	bool getDead();
	int damage(int atk, int def);
	void setPosn(Posn p);
	Posn getPosn();
	Race(char c, int maxhp, int hp, int atk, int def);
	virtual ~Race() = 0;
};

#endif
