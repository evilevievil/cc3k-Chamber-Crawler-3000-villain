#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "race.h"
#include "typedef.h"

class Enemy: public Race{	
public:
	void attack(Tile* t);
	void beAttacked(Shade& pc);
	void beAttacked(Drow& pc);
	void beAttacked(Vampire& pc);
	void beAttacked(Troll& pc);
	void beAttacked(Goblin& pc);
	void randMove(Map& map);
	void checkSurroundings();	
	Enemy(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def);
	virtual ~Enemy();
};

#endif
