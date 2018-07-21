#ifndef _SHADE_H_
#define _SHADE_H_
#include "pc.h"

class Shade: public PC{
public:
	int getScore() override;
	Shade();
	~Shade();
};

#endif