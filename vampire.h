#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "pc.h"

class Vampire: public PC{

public:
	void attack(Race *victim) override;
	void beAttacked(Race *victim) override;
	void checkSurroundings(vector<vector <Tile*>> &map);
	Vampire();
	~Vampire();
};

#endif