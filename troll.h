#ifndef _TROLL_H_
#define _TROLL_H_
#include "pc.h"
#include "typedef.h"

class Troll: public PC{

public:
	void endTurnAction() override;
	void attack(Tile *enemy) override;
	Troll(Posn p, Tile* t);
};

#endif
