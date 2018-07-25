#ifndef _SLIME_H_
#define _SLIME_H_
#include "pc.h"
#include "typedef.h"

class Slime: public PC{
	
public:
	void attack(Tile* t) override;
	int getScore() override;
	Slime();
};

#endif
