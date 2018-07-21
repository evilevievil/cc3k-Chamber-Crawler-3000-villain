#ifndef _GAME_H_
#define _GAME_H_

#include "textdisplay.h"
#include "tile.h"
#include "floorlevel.h"
#include <utility>
#include <vector>


class Game: public FloorLevel {
  vector<vector<tile*>> map;
  Tile* PC;

public:
  Game(char pc, string file);
  ~Game();
  init();
  refreshMap(); //check if win in this method
  spawnAt(Pair<int, int> p, Tile* t);
  movePC(Pair<int, int> p);
  moveEnemies();
  PCAttach(Pair<int, int> p);
  usePotion(Pair<int, int> p);

};
#endif
