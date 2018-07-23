#ifndef _SHADE_H_
#define _SHADE_H_
#include "pc.h"
#include "typedef.h"

class Shade: public PC{
public:
	void attack(Tile* enemy) override;
	int getScore() override;
	Shade(Posn p, Tile* t);
};

#endif
