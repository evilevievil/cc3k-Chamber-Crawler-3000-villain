#ifndef _DROW_H_
#define _DROW_H_
#include "pc.h"
#include "typedef.h"

class Drow: public PC{		
public:
	void attack(Tile* t) override;
	void beAttacked(Elf& e) override;
	void beAffected(BA& potion) override;
	void beAffected(BD& potion) override;
	void beAffected(RH& potion) override;
	void beAffected(WA& potion) override;
	void beAffected(WD& potion) override;
	void beAffected(PH& potion) override;
	Drow();
};

#endif
