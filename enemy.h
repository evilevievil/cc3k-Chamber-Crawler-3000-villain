#ifndef _ENEMY_H_
#define _ENEMY_H_
#inclued "race.h"

class Enemy: public Race{	
public:
	void checkSurroundings();	
	Enemy();
	virtual ~Enemy();
};

#endif