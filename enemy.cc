#include "enemy.h"
#include "cstdlib"
#include <sstream>
using namespace std;

Enemy::Enemy(char c, int maxhp, int hp, int atk, int def):
  Race{c, maxhp, hp, atk, def} {}

void Enemy::reportDamage(int damage, ostringstream& action){
  action << "PC deals " << damage << " damage to " << visual << " (" << hp << " hp)" << endl;
}

// this is attacked by a PC
void Enemy::beAttacked(PC& pc){
  int d = damage(pc.getAtk(), def);
  hp -= d;
  giveReward(pc);
  reportDamage(d, pc.action);
}

// this is attacked by an vampire
void Enemy::beAttacked(Vampire& pc){
  int d = damage(pc.getAtk(), def);
  hp -= d;
  // vampire gains 5 HP after attck
  pc.restoreHp();
  giveReward(pc);
  reportDamage(d, pc.action);
}


void Enemy::giveReward(PC& pc){
  // give reward if this is slained
  if(hp <= 0){
    hp = 0; // set hp to 0 if it's lower than 0
    pc.addGold((rand() % 2) + 1);
  }
}

void Enemy::giveReward(Goblin& pc){
  if(hp <= 0){
    hp = 0; // set hp to 0 if it's lower than 0
    // 5 more additional gold is given to Goblin
    pc.addGold((rand() % 2) + 6);
  }
}

void Enemy::checkSurroundings(Map& map){
  //check if pc is in one block radius
  for(int i = position.first - 1; ++i; i < position.first + 2){
    for(int j = position.second - 1; ++j; j < position.second + 2){
      if(map[i][j]->getVisual() == '@'){
	      // pc is in one block radius, attck it
	      attack(map[i][j]);
        return;
      }
    }
  }
  // pc is not in one block radius, take a random move
  randMove(map);
}

// randmonly move to a neighbour square
void Enemy::randMove(Map& map){
  int x, y;
  while(true){
    // randomly choose a near square
    x = position.first + ((rand() % 3) - 1);
    y = position.second + ((rand() % 3) - 1);
    // check if it's a valid square to move to
    if(map[x][y]->getVisual() == '.'){
      break;
    }
  }
  // move to that square
  map[position.first][position.second] = map[x][y];
  map[x][y] = this;
  position = Posn {x, y};
}
