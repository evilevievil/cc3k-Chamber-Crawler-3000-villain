#ifndef _PC_H_
#define _PC_H_
#include "race.h"
#include "typedef.h"

class PC: public Race{
protected:
	int gold;
	int atkHistory, defHistory;
	bool dead = false;
	
public:
	int getGold();
	bool isDead();
	virtual int getScore();
	void restoreHp(int i = 5);
	void addGold(int i = 5);
	void move(Map& map, Pair<int, int> p);
	void checkSurroundings(Map& map);

	virtual void attack(Tile* t) = 0;
	virtual void beAttacked(Enemy& e);
	virtual void beAttacked(Elf& e);
	virtual void beAttacked(Orcs& o);

	virtual void beAffected(BA& potion);
	virtual void beAffected(BD& potion);
	virtual void beAffected(RH& potion);
	virtual void beAffected(WA& potion);
	virtual void beAffected(WD& potion);
	virtual void beAffected(PH& potion);
	PC(Posn p, Tile* t, int maxhp, int hp, int atk, int def);
};

#endif
