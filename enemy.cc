#include "enemy.h"
#include <rand>

Enemy::Enemy(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def):
  Race{c, p, t, maxhp, hp, atk, def} {}

Enemy::~Enemy() {}

void Enemy::checkSurroundings(){
}

void Enemy::randMove(Map& map){
}
