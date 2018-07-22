#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "race.h"
#include "typedef.h"

class Enemy: public Race{	
public:
	virtual void dropReward() = 0;
	virtual void attack(Tile* t);
	virtual void beAttacked(Enemy& pc);
	virtual void beAttacked(Vampire& pc);
	virtual void beAttacked(Goblin& pc);
	virtual void randMove(Map& map);
	void checkSurroundings();	
	Enemy(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def);
	virtual ~Enemy() = 0;
};

#endif
