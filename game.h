#ifndef _GAME_H_
#define _GAME_H_

#include "tile.h"
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include "enemy.h"
#include "pc.h"
#include "typedef.h"

class Game {
  Map map;
  std::vector<Enemy *> enemies;
  PC* PC;
  int floornum = 0;
  bool freeze = false;

public:
  Game(char pc, std::string file = "map.txt");
  ~Game();
  void restart();
  void enterFloor(); //check if win in this method
  void cleanMap();
  void spawnAt(Posn p, Tile* t);
  Posn dirpos(std::string d, Posn p);
  void movePC(std::string d);
  void moveEnemies();
  void PCAttack(std::string d);
  void usePotion(std::string d);
  void allocatorPC();
  void generatorStair();
  void generatorEnemy();
  void generatorGold();
  void generatorPotion();
  Posn generatorpos();
  void setFreeze(bool b);
  void oneTurn();
  
  friend std::ostream& operator<<(std::ostream& out, Game &g);
};
#endif
