#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "race.h"
#include "typedef.h"

class Enemy: public Race{	
public:
	virtual void attack(Tile* pc) = 0;
	void beAttacked(PC& pc);
	virtual void beAttacked(Vampire& pc);
	virtual void randMove(Map& map);
	void giveReward(PC& pc);
	void giveReward(Goblin& pc);
	virtual void checkSurroundings();	
	Enemy(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def);
};

#endif
