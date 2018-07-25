#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "enemy.h"
#include "typedef.h"

class Human: public Enemy{
public:
	void attack(Tile* pc) override;
	Human();

};

#endif
