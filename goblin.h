#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "pc.h"
#include "typedef.h"
#include "orcs.h"

class Goblin: public PC{
public:
	void attack(Tile* enemy) override;
	void beAttacked(Orcs& o) override;
	Goblin();
};

#endif
