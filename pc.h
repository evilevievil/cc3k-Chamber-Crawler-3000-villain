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
	virtual void move(Map& map, Pair<int, int> p);
	void checkSurroundings(Map& map);

	virtual void attack(Tile* t);
	virtual void beAttacked(Human& h);
	virtual void beAttacked(Dwarf& w);
	virtual void beAttacked(Elf& e);
	virtual void beAttacked(Orcs& o);
	virtual void beAttacked(Merchant& m);
	virtual void beAttacked(Dragon& d);
	virtual void beAttacked(Halfling& l);

	virtual void beAffected(BA& potion);
	virtual void beAffected(BD& potion);
	virtual void beAffected(RH& potion);
	virtual void beAffected(WA& potion);
	virtual void beAffected(WD& potion);
	virtual void beAffected(PH& potion);
	PC(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def);
	virtual ~PC() = 0;
};

#endif
