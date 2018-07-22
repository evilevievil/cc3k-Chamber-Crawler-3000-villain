#ifndef _DROW_H_
#define _DROW_H_
#include "pc.h"

class Drow: public PC{		
public:
	void attack(Race *victim) override;
	void beAttacked(Race *victim) override;
	void checkSurroundings(vector<vector <Tile*>> &map);
	void beAffected(BA& potion) override;
	void beAffected(BD& potion) override;
	void beAffected(RH& potion) override;
	void beAffected(WA& potion) override;
	void beAffected(WD& potion) override;
	void beAffected(PH& potion) override;
	Shade();
	~Shade();
};

#endif