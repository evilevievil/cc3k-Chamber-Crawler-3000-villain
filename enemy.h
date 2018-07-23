#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "race.h"
#include "typedef.h"

class Enemy: public Race{	
public:
	virtual void dropReward();
	virtual void attack(Tile* t) = 0;
	virtual void beAttacked(PC& pc);
	virtual void beAttacked(Vampire& pc);
	virtual void randMove(Map& map);
	void beAttacked(Goblin& pc);
	void checkSurroundings();	
	Enemy(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def);
};

#endif
