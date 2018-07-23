#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "pc.h"
#include "typedef.h"

class Vampire: public PC{

public:
	void attack(Tile* enemy) override;
	Vampire(Posn p, Tile* t);
};

#endif
