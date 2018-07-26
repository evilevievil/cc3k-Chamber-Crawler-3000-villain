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
    bool win = false;

public:
    Game(char pc, std::string file = "map.txt");
    ~Game();

    bool won();
    bool dead();

    void restart();
    void enterFloor(); //check if win in this method
    void cleanMap();

    Posn dirpos(std::string d, Posn p);
    void movePC(std::string d);
    void moveEnemies();
    void PCAttack(std::string d);
    void usePotion(std::string d);
    void allocatorPC(int num);
    void generatorStair();
    void generatorEnemy();
    void generatorGold();
    void generatorPotion();
    Posn generatorpos(int num);
    void setFreeze(bool b);
    void oneTurn();

    friend std::ostream& operator<<(std::ostream& out, Game &g);
};
#endif
