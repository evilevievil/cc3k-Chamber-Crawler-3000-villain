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
  Game(char pc, std::tring file);
  ~Game();
  void init();
  void refreshMap(); //check if win in this method
  void spawnAt(std::Pair<int, int> p, Tile* t);
  void movePC(std::Pair<int, int> p);
  void moveEnemies();
  void PCAttach(std::Pair<int, int> p);
  void usePotion(std::Pair<int, int> p);

};
#endif
