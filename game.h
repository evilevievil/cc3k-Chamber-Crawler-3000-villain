#ifndef _GAME_H_
#define _GAME_H_

#include "textdisplay.h"
#include "tile.h"
#include "floorlevel.h"
#include <utility>
#include <vector>
#include <sstream>
#include "enemy.h"
#include "pc.h"

class Game: public FloorLevel {
  vector<vector<tile*>> map;
  vector<Enemy *> enemies;
  Tile* PC;


public:
  Game(char pc, std::string file);
  ~Game();
  void init();
  void refreshMap(); //check if win in this method
  void spawnAt(Posn p, Tile* t);
  void movePC(Posn p);
  void moveEnemies();
  void PCAttach(Posn p);
  void usePotion(Posn p);
  void generatorStair();
  void generatorEnemy();
  void generatorGold();
  void generatorPotion();
  
};
#endif
