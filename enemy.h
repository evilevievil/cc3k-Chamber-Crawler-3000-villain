#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "race.h"
#include "pc.h"
#include "typedef.h"
#include "vampire.h"
#include "goblin.h"
#include <sstream>

class Enemy: public Race{	
public:
	virtual void attack(Tile* t) = 0;
	void reportDamage(int damage, std::ostringstream& action);
	virtual void beAttacked(PC& pc);
	virtual void beAttacked(Vampire& pc);
	virtual void randMove(Map& map);
	void giveReward(PC& pc);
	void giveReward(Goblin& pc);
	virtual void checkSurroundings(Map& map);	
	Enemy(char c, int maxhp, int hp, int atk, int def);
};

#endif
