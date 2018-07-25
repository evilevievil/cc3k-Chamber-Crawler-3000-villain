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

public:
	int getHp();
	int getAtk();
	int getDef();
	int damage(int atk, int def);
	void setPosn(Posn p);
	Posn getPosn();
	Race(char c, int maxhp, int hp, int atk, int def);
	virtual ~Race() = 0;
};

#endif
