#ifndef _PC_H_
#define _PC_H_
#include "race.h"

class PC: public Race{
protected:
	int gold;
	int atkHistory, defHistory;
	
public:
	int getAtk();
	int getDef();
	int getGold();
	virtual int getScore();
	virtual void move(vector<vector<Tile*>>& map, Pair<int, int> p);
	virtual void beAffected(BA& potion);
	virtual void beAffected(BD& potion);
	virtual void beAffected(RH& potion);
	virtual void beAffected(WA& potion);
	virtual void beAffected(WD& potion);
	virtual void beAffected(PH& potion);
	virtual void attack(Race *victim);
	virtual void beAttacked(Race *victim);
	void checkSurroundings(vector<vector <Tile*>> &map);
	PC();
	virtual ~PC() = 0;
};

#endif