#ifndef _PC_H_
#define _PC_H_
#include "race.h"
#include "typedef.h"
#include "elf.h"
#include "orcs.h"
#include "potiontype.h"
#include <sstream>

class PC: public Race{
protected:
	int gold;
	int atkHistory, defHistory;
	bool dead = false;
	Tile* curTile = nullptr;
		
public:
	std::ostringstream action; //public field that records PC's actions in a turn

	int getGold();
	bool isDead();
	void setDead();
	void setCurTile(Tile* t);
	virtual int getScore();
	void restoreHp(int i = 5);
	void addGold(int i = 5);
	void move(Map& map, Posn p); // move to a new square if valid
	void checkSurroundings(Map& map); // check surrounding for items and
					  // report to action

	virtual void endTurnAction(); // PC does this at the end of a turn
	virtual void attack(Tile* t) = 0;
	void beAttacked(Enemy& e);
	virtual void beAttacked(Elf& e);
	virtual void beAttacked(Orcs& o);

	virtual void beAffected(BA& potion);
	virtual void beAffected(BD& potion);
	virtual void beAffected(RH& potion);
	virtual void beAffected(WA& potion);
	virtual void beAffected(WD& potion);
	virtual void beAffected(PH& potion);
	PC(int maxhp, int hp, int atk, int def);
};

#endif
