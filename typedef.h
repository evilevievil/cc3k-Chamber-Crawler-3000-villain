#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <utility>
#include <vector>

class Tile;

typedef std::vector<std::vector<Tile*>> Map;
typedef std::pair<int, int> Posn;

const int RH_effect = 10;
const int BA_effect = 5;
const int BD_effect = 5;
const int PH_effect = -10;
const int WA_effect = -5;
const int WD_effect = -5;
const int Small_effect = 1;
const int Normal_effect = 2;
const int Merchant_effect = 4;
const int Dragon_effect = 6;


enum Direction{
	no, 
	so, 
	ea,
	we, 
	ne,
	nw,
	se, 
	sw 
}

#endif


