#ifndef _TROLL_H_
#define _TROLL_H_
#include "pc.h"

class Troll: public PC{

public:
	void attack(Race *victim) override;
	void beAttacked(Race *victim) override;
	void checkSurroundings(vector<vector <Tile*>> &map);
	Troll();
	~Troll();
};

#endif