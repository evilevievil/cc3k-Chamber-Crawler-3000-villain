#ifndef _GAME_H_
#define _GAME_H_

#include "vector"
#include "textdisplay.h"
#include 'all races'

class Game {
  vector<vector<tile*>> emptyMap;
  vector<vector<tile*>> map;
  Tile* PC;
  Floor level;

public:
  Game(char pc);
  ~Game();
  init();
  refreshMap(); //check if win in this method
  spawnAt(int x, int y);
  movePC(int x, int y);
  moveEnemies();
  PCAttach(int x, int y);
  usePotion(int x, int y);

};
#endif
